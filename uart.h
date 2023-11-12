/*
 * uart.h
 *
 *  Created on: Oct 29, 2023
 *      Author: HP
 */

#ifndef UART_H_
#define UART_H_

#include "bitmap.h"
#include"AvrRegisters.h"
#include "uart_config.h"

#define RXC_ID     7
#define TXC_ID     6
#define UDRE_ID    5
#define FE_ID      4
#define DOR_ID     3
#define PE_ID      2
#define U2X_ID     1
#define MPCM_ID    0

#define RXCIE_ID     7
#define TXCIE_ID     6
#define UDRIE_ID    5
#define RXEN_ID     4
#define TXEN_ID     3
#define UCSZ2_ID    2
#define RXB8_ID     1
#define TXB8_ID     0

#define URSEL_ID    7
#define UMSEL_ID    6
#define UPM1_ID     5
#define UPM0_ID     4
#define USBS_ID     3
#define UCSZ1_ID    2
#define UCSZ0_ID    1
#define UCPOL_ID    0

/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void USART_Init( );

/****************************************************************/
/* Description    : This function used to Send Data				*/
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit( u8 data );

/****************************************************************/
/* Description    : This function used to Receive Data			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
u8 USART_Receive( );



#endif /* UART_H_ */
