/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */

#include"lcd.h"
#include"DIO.h"
#include"uart.h"
#include"stdtypes.h"
#include <stdio.h>
#include <stdlib.h>

u8 hexCharToNum(u8 hexChar) {
	if (hexChar >= '0' && hexChar <= '9') {
		return hexChar - '0';
	} else if (hexChar >= 'A' && hexChar <= 'F') {
		return hexChar - 'A' + 10;
	} else if (hexChar >= 'a' && hexChar <= 'f') {
		return hexChar - 'a' + 10;
	} else {
		return 0xFF; //  error
	}
}

// Function to receive a byte and interpret it as a hexadecimal number
u8 uart_receive_hex() {
	u8 highNibble, lowNibble;

	highNibble = USART_Receive();
	lowNibble = USART_Receive();

	return (hexCharToNum(highNibble) << 4) | hexCharToNum(lowNibble);
}

#define accessed 1
#define no_access 0

#define encrypt_OK 1
#define encrypt_NOK 0

//Receive
int main() {

	DIO_init();
	LCD_init();
	USART_Init();
//	u8 data='0';
	u8 service, subservice, routine_msb, routine_lsb;
	u8 random[4];
	u8 key[4] = { 0x35, 0x35, 0x35, 0x35 };
	u8 encrypt_saved[4];
	u8 encrypt[4];
	u8 flag = no_access;
	u8 flag_enc = encrypt_OK;
	while (1) {

		service = uart_receive_hex();
		subservice = uart_receive_hex();
		//service = 0x31 subservice = 0x01
		if ((service == 0x31) && (subservice == 0x01)) {
			routine_msb = uart_receive_hex();
			routine_lsb = uart_receive_hex();
			if ((routine_msb == 0xAA) && (routine_lsb == 0x00)) {
				if (flag == no_access) {
					LCD_sendCommand(LCD_CLEAR_DISPLAY);
					LCD_writeString("NRC 7F 31 35");
				} else if (flag == accessed) {    //TURN ON LED
					LCD_sendCommand(LCD_CLEAR_DISPLAY);
					LCD_writeString("7101AA00");
					DIO_SetPinValue(PORTC_ID, PIN0_ID, LOGIC_HIGH);
				}
			}

		}
		service = uart_receive_hex();
		subservice = uart_receive_hex();
//SEND 2701 WITH UART
		if ((service == 0x27) && (subservice == 0x01)) {
			//RECEIVE 6701 + 4 RANDOM BYTES
			LCD_sendCommand(LCD_CLEAR_DISPLAY);
			LCD_GotoRowColumn(0, 0);
			LCD_writeString("67 01 ");
			// Generate 4 random hexadecimal numbers and save them in the array
			for (int i = 0; i < 4; i++) {
				random[i] = rand() % 100;
			}
			for (int i = 0; i < 4; i++) {
				char buffer[3]; // Buffer to hold the string representation (2 characters + null terminator)
				sprintf(buffer, "%02X", random[i]); // Convert the hexadecimal value to a string
				LCD_writeString(buffer);
				LCD_writeChar(' ');
			}

		}
//ENCRYPT THE RANDOM NUMBER USING SYMMETRIC KEY
		for (int i = 0; i < 4; i++) {
			encrypt_saved[i] = random[i] ^ key[i];
		}

//0X2702 + 4 ENCRYPTED BYTES
		service = uart_receive_hex();
		subservice = uart_receive_hex();
		if ((service == 0x27) && (subservice == 0x02)) {

			for (int i = 0; i < 4; i++) {
				encrypt[i] = uart_receive_hex();
			}

//compare 4 bytes calculated by MC with 4 bytes sent by uart
			for (int i = 0; i < 4; i++) {
				if (encrypt[i] != encrypt_saved[i]) {
					flag_enc = encrypt_NOK;
				}

			}

			if (flag_enc == encrypt_OK) {
				//RECEIVE 6702
				LCD_sendCommand(LCD_CLEAR_DISPLAY);
				LCD_writeString("67 02");
				flag = accessed; //SECURITY ACCESS SUCCESS!
			} else if (flag_enc == encrypt_NOK) {
				LCD_sendCommand(LCD_CLEAR_DISPLAY);
				LCD_writeString("7F2735");
			}

		}


	}
	return 0;
}

