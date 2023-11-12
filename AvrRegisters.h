/*
 * IO_reg.h
 *
 *  Created on: Oct 17, 2023
 *      Author: HP
 */

#ifndef AVRREGISTERS_H_
#define AVRREGISTERS_H_

#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)0x3A)
#define PINA *((volatile u8*)0x39)

#define PORTB *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x36)

#define PORTC *((volatile u8*)0x35)
#define DDRC *((volatile u8*)0x34)
#define PINC *((volatile u8*)0x33)

#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)

#define SREG *((volatile u8*)0x5F)
#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)

#define SFIOR *((volatile u8*)0x50)
#define ADMUX *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)
#define ADC *((volatile u16*)0x24) //u16 to store both adcl + adch start at adcl!


#define OCR0 *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TCCR2 *((volatile u8*)0x45)
#define TCNT2 *((volatile u8*)0x44)
#define OCR2 *((volatile u8*)0x43)

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)

#define TCNT1  *((volatile u16*)0x4C) //to return whole 16 bits

#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)

#define OCR1A *((volatile u16*)0x4A) //

#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)

#define OCR1B *((volatile u16*)0x48) //

#define ICR1H *((volatile u8*)0x47)
#define ICR1L *((volatile u8*)0x46)

#define ICR1 *((volatile u16*)0x46)

#define UCSRC  *((volatile u8*)0x40)
#define UBRRH  *((volatile u8*)0x40)
#define UDR *((volatile u8*)0x2C)
#define UCSRA  *((volatile u8*)0x2B)
#define UCSRB  *((volatile u8*)0x2A)
#define UBRRL  *((volatile u8*)0x29)




#endif /* AVRREGISTERS_H_ */
