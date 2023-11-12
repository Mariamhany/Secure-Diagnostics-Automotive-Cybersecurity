/*
 * DIO.h
 *
 *  Created on: Oct 17, 2023
 *      Author: HP
 */

#ifndef DIO_H_
#define DIO_H_

#include "stdtypes.h"

/**********      Definitions          ********/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

#define PIN_INPUT              0
#define PIN_OUTPUT             1
#define PORT_INPUT             0
#define PORT_OUTPUT          (0xFF)

#define LOGIC_LOW              0
#define LOGIC_HIGH             1
/**********      Type declaration       ********/

//typedef enum {
//	PIN_INPUT,PIN_OUTPUT
//} DIO_PinDirection;

//typedef enum {
//	PORT_INPUT,PORT_OUTPUT=0XFF
//} DIO_PortDirection;

/**********      Function Prototypes     ********/
void DIO_init();
void DIO_SetPinDirection (u8 port_num, u8 pin_num,u8 direction);
void DIO_SetPinValue (u8 port_num, u8 pin_num,u8 value);
u8 DIO_GetPinValue (u8 port_num, u8 pin_num);
void DIO_TogglePinValue(u8 port_num, u8 pin_num);
void DIO_SetPortDirection (u8 port_num, u8 direction);
void DIO_SetPortValue (u8 port_num,u8 value);
u8 DIO_GetPortValue (u8 port_num);


#endif /* DIO_H_ */
