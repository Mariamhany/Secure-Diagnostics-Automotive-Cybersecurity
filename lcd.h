/*
 * lcd.h
 *
 *  Created on: Oct 20, 2023
 *      Author: HP
 */

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define LCD_DATA_BITS_MODE 4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#if (LCD_DATA_BITS_MODE == 4)

/* if LCD_LAST_PORT_PINS is defined in the code, the LCD driver will use the last 4 pins in the gpio port for for data.
 * To use the first four pins in the gpio port for data just remove LCD_LAST_PORT_PINS */
#define LCD_LAST_PORT_PINS

#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID         PIN4_ID
#else
#define LCD_FIRST_DATA_PIN_ID         PIN0_ID
#endif

#endif
/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA_ID
#define LCD_RS_PIN_ID                  PIN3_ID

//#define LCD_RW_PORT_ID                 PORT_ID
//#define LCD_RW_PIN_ID                  PIN5_ID

#define LCD_E_PORT_ID                  PORTA_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTB_ID
#define LCD_PIN_D4_ID                 PIN0_ID
#define LCD_PIN_D5_ID                 PIN1_ID
#define LCD_PIN_D6_ID                 PIN2_ID
#define LCD_PIN_D7_ID                 PIN4_ID

/* LCD Commands */
#define LCD_GO_TO_HOME                 0x02
#define LCD_CLEAR_DISPLAY              0x01
#define LCD_DISPLAY_ON_OFF             0x0C
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
//

#endif /* LCD_H_ */

/* **************  Functions Prototypes   ***************    */

/* Description :
 * Initialize the LCD:
 *  Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_writeChar(u8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_writeString(const char *Str);

/*
 * Description :
 * Go to a certain row column on the screen
 */
void LCD_GotoRowColumn(u8 row,u8 col);


void LCD_storeCustomChar (u8*pattern,u8 CGRAM_index);
void LCD_displayCustomChar(u8 CGRAM_index,u8 row , u8 col);
void LCD_integertoString(u8 num);
