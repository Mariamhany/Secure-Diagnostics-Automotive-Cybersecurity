/*
 * DIO.c
 *
 *  Created on: Oct 17, 2023
 *      Author: HP
 */

#include "stdtypes.h"
#include "DIO.h"
#include "AvrRegisters.h"
#include "bitmap.h"
#include "DIO_config.h"

//#define CONC_HELPER(PORT_PIN7,PORT_PIN6,PORT_PIN5,PORT_PIN4,PORT_PIN3,PORT_PIN2,PORT_PIN1,PORT_PIN0) Ob##PORT_PIN7##PORT_PIN6##PORT_PIN5##PORT_PIN4##PORT_PIN3##PORT_PIN2##PORT_PIN1##PORT_PIN0
//#define CONC_BIT(PORT_PIN7,PORT_PIN6,PORT_PIN5,PORT_PIN4,PORT_PIN3,PORT_PIN2,PORT_PIN1,PORT_PIN0) CONC_HELPER(PORT_PIN7,PORT_PIN6,PORT_PIN5,PORT_PIN4,PORT_PIN3,PORT_PIN2,PORT_PIN1,PORT_PIN0)


//#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
//#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

void DIO_init()
{
DDRA=CONC_BIT(PORTA_PIN7,PORTA_PIN6,PORTA_PIN5,PORTA_PIN4,PORTA_PIN3,PORTA_PIN2,PORTA_PIN1,PORTA_PIN0);

DDRB=CONC_BIT(PORTB_PIN7,PORTB_PIN6,PORTB_PIN5,PORTB_PIN4,PORTB_PIN3,PORTB_PIN2,PORTB_PIN1,PORTB_PIN0);

DDRC=CONC_BIT(PORTC_PIN7,PORTC_PIN6,PORTC_PIN5,PORTC_PIN4,PORTC_PIN3,PORTC_PIN2,PORTC_PIN1,PORTC_PIN0);

DDRD=CONC_BIT(PORTD_PIN7,PORTD_PIN6,PORTD_PIN5,PORTD_PIN4,PORTD_PIN3,PORTD_PIN2,PORTD_PIN1,PORTD_PIN0);

}

void DIO_SetPinDirection(u8 port_num, u8 pin_num, u8 direction) {

	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT))
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			else
			{
				SET_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRB,pin_num);
			} else
			{
				SET_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRC,pin_num);
			} else
			{
				SET_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			else
			{
				SET_BIT(DDRD,pin_num);
			}
			break;
		} //SWITCH
	}
}
void DIO_SetPinValue(u8 port_num, u8 pin_num, u8 value)
{
	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT))
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
			if (value == LOGIC_LOW)
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			else
			{
				SET_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if (value == LOGIC_LOW)
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			else
			{
				SET_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if (value == LOGIC_LOW)
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			else
			{
				SET_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if (value == LOGIC_LOW)
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			else
			{
				SET_BIT(PORTD,pin_num);
			}
			break;

}
	}
}
u8 DIO_GetPinValue(u8 port_num, u8 pin_num)
{
	u8 value=LOGIC_LOW;

	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT))
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
			if (BIT_IS_SET(PINA,pin_num))
			{
				value=LOGIC_HIGH;
			}
			else
			{
				value=LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if (BIT_IS_SET(PINB,pin_num))
			{
				value=LOGIC_HIGH;
			}
			else
			{
				value=LOGIC_LOW;
			}
            break;
		case PORTC_ID:
			if (BIT_IS_SET(PINC,pin_num))
			{
				value=LOGIC_HIGH;
			}
			else
			{
				value=LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if (BIT_IS_SET(PIND,pin_num))
			{
				value=LOGIC_HIGH;
			}
			else
			{
				value=LOGIC_LOW;
			}
			break;
}

}
	return value;
}

void DIO_TogglePinValue(u8 port_num, u8 pin_num){
	if ((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT))
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
	    TOGGLE_BIT(PORTA,pin_num);
		break;
		case PORTB_ID:
	    TOGGLE_BIT(PORTB,pin_num);
		break;
		case PORTC_ID:
	    TOGGLE_BIT(PORTC,pin_num);
		break;
		case PORTD_ID:
	    TOGGLE_BIT(PORTD,pin_num);
		break;

		}
	}
}


/***PORT**/
void DIO_SetPortDirection(u8 port_num, u8 direction)
{
	if ((port_num >= NUM_OF_PORTS))
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
			DDRA=direction;
		break;
		case PORTB_ID:
			DDRB=direction;
		break;
		case PORTC_ID:
			DDRC=direction;
		break;
		case PORTD_ID:
			DDRD=direction;
		break;
}
	}
}
void DIO_SetPortValue(u8 port_num, u8 value)
{
	if ((port_num >= NUM_OF_PORTS) )
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
			PORTA=value;
		break;
		case PORTB_ID:
			PORTB=value;
		break;
		case PORTC_ID:
			PORTC=value;
		break;
		case PORTD_ID:
			PORTD=value;
		break;
}
	}
}
u8 DIO_GetPortValue(u8 port_num)
{
	u8 value=LOGIC_LOW;
	if ((port_num >= NUM_OF_PORTS))
	{

	}
	else {
		switch (port_num) {
		case PORTA_ID:
			value=PINA;
		break;
		case PORTB_ID:
			value=PINB;
		break;
		case PORTC_ID:
			value=PINC;
		break;
		case PORTD_ID:
			value=PIND;
		break;

	}

}
	return value;
}

//int main(){
//
//	DIO_init();
//
//
//	return 0;
//}
