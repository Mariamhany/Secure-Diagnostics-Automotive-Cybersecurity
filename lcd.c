/*
 * lcd.c
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#include "DIO.h"
#include "AvrRegisters.h"
#include "DIO_config.h"
#include "lcd.h"
#include "bitmap.h"
#include <util/delay.h>


void LCD_init(){

	LCD_sendCommand(LCD_GO_TO_HOME);
#if (LCD_DATA_BITS_MODE == 8)
	/* 8 BITS - 2 LINES - 5*7 */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#elif (LCD_DATA_BITS_MODE == 4)
	/* 4 BITS - 2 LINES - 5*7 */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#endif
	/* SET DISPLAY ON - DISABLE CURSOR - BLNKING OFF */
	LCD_sendCommand(LCD_DISPLAY_ON_OFF);
	/* CLEAR DISPLAY */
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}
void LCD_sendCommand(u8 command){

	u8 lcd_port_value =0;
	/* RS=0 */
	DIO_SetPinValue(LCD_RS_PORT_ID ,LCD_RS_PIN_ID,LOGIC_LOW );
#if (LCD_DATA_BITS_MODE == 8)
	/*out the command */
	DIO_SetPortValue(LCD_DATA_PORT_ID,command );
	/*E=1*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_HIGH );
	_delay_ms(2);
	/*E=0*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_LOW );
#elif  (LCD_DATA_BITS_MODE == 4)

	/* out the LAST 4 bits of the required command to the data bus D4 --> D7 */
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D4_ID,GET_BIT(command,4) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D5_ID,GET_BIT(command,5) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D6_ID,GET_BIT(command,6) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D7_ID,GET_BIT(command,7) );

	/*E=1*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_HIGH );
	_delay_ms(1);
	/*E=0*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_LOW );

	/* out the FIRST 4 bits of the required command to the data bus D4 --> D7 */

	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D4_ID,GET_BIT(command,0) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D5_ID,GET_BIT(command,1) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D6_ID,GET_BIT(command,2) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D7_ID,GET_BIT(command,3) );


	/*E=1*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_HIGH );
	_delay_ms(1);
	/*E=0*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_LOW );
	_delay_ms(2);
#endif
}

void LCD_writeChar(u8 data)
{
	u8 lcd_port_value =0;
	/* RS=1 */
	DIO_SetPinValue(LCD_RS_PORT_ID ,LCD_RS_PIN_ID,LOGIC_HIGH);
_delay_ms(1);
#if (LCD_DATA_BITS_MODE == 8)
	/*out the DATA */
	DIO_SetPortValue(LCD_DATA_PORT_ID,data );
	/*E=1*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_HIGH );
	_delay_ms(2);
	/*E=0*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_LOW );
#elif  (LCD_DATA_BITS_MODE == 4)
	/* out the LAST 4 bits of the required data to the data bus D4 --> D7 */

	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D4_ID,GET_BIT(data,4) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D5_ID,GET_BIT(data,5) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D6_ID,GET_BIT(data,6) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D7_ID,GET_BIT(data,7) );
	//_delay_ms(1);
	/*E=1*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_HIGH );
	_delay_ms(1);
	/*E=0*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_LOW );

	/* out the FIRST 4 bits of the required data to the data bus D4 --> D7 */

	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D4_ID,GET_BIT(data,0) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D5_ID,GET_BIT(data,1) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D6_ID,GET_BIT(data,2) );
	DIO_SetPinValue(LCD_DATA_PORT_ID ,LCD_PIN_D7_ID,GET_BIT(data,3) );
	/*E=1*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_HIGH );
	_delay_ms(1);
	/*E=0*/
	DIO_SetPinValue(LCD_E_PORT_ID ,LCD_E_PIN_ID,LOGIC_LOW );
	_delay_ms(2);
#endif
}

void LCD_writeString(const char *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_writeChar(Str[i]);
		i++;
	}
}

void LCD_GotoRowColumn(u8 row,u8 col)
{
u8 lcd_memory_address;
/* calculate required address for DDRAM*/
switch (row){
case 0: lcd_memory_address=col;
break;
case 1: lcd_memory_address=col+0x40;
break;
case 2:lcd_memory_address=col+0x14;
break;
case 3:lcd_memory_address=col+0x54;
break;
}
/* In datasheet set D7 =1 for set DDRAM address & address from D0->D6
 * address OR 0x80 */
LCD_sendCommand((lcd_memory_address) | (0x80));

}

void LCD_storeCustomChar (u8*pattern,u8 CGRAM_index){
	u8 address,i;
	if (CGRAM_index < 8 ){
		/* index=0 address*8 =0x00
		 * index =1 address*8=0x08 next location & so on till 8 */
		address = CGRAM_index * 8;
		/* In datasheet set D6 =1 for set CGRAM address & address from D0->D5*/
		address= SET_BIT(address,6);
		LCD_sendCommand(address);
		/* looping in the array of pattern */
		for (i=0 ; i<7;i++)
		{
			LCD_writeChar(pattern[i]);
		}
	}
	/* Go back to DDRAM*/
	LCD_sendCommand(LCD_GO_TO_HOME);
}
 void LCD_displayCustomChar(u8 CGRAM_index,u8 row , u8 col){
	 LCD_GotoRowColumn(row,col);
	 LCD_writeChar (CGRAM_index);
 }

 void LCD_integertoString(u8 num)
 {
	 char buff[16];
	 itoa(num,buff,10);
	 LCD_writeString(buff);
 }
