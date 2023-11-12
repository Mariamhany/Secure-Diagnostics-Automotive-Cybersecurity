/*
 * bitmap.h
 *
 *  Created on: Oct 17, 2023
 *      Author: HP
 */

#ifndef BITMAP_H_
#define BITMAP_H_


#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#define GET_BIT(REG,BIT) ((REG >> BIT) & 0x01)

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

//#define CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0) (Ob##X7##X6##X5##X4##X3##X2##X1##X0)
//#define CONC_BIT(X7,X6,X5,X4,X3,X2,X1,X0) CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0)



#endif /* BITMAP_H_ */
