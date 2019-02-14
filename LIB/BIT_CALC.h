/**************************************************/
/* Author : Mariam Ahmed                          */
/* Date   : 5 Feb 2019                            */
/**************************************************/
/**************************************************/
/* Description : Bit Calculation File             */
/*               This file has:                   */   
/*                1- Macro like functions for     */
/*                   registers' operations        */
/*                2- 8 bit concatenation macro    */
/*                   like function                */
/**************************************************/
/* Preprocessor Guard                                */
#ifndef BIT_CALC_H
#define BIT_CALC_H

/* Comment : Macro like functions for registers'  */
/*           operations                           */
/* Note    : Bit numbering starts from 0          */
/*-----------------BIT OPERATIONS-----------------*/
/* Set Bit                                        */
/* Description : given a register and a bit number*/
/*               it sets the corresponding bit in */
/*               that position in that register   */
#define SET_BIT(REG,BIT_NUM)		(REG |= 1 << BIT_NUM )

/* Clear Bit                                      */
/* Description : given a register and a bit number*/
/*               it clears the corresponding bit  */
/*               in that position in that register*/
#define CLEAR_BIT(REG,BIT_NUM)	(REG &= ~( 1 << BIT_NUM ))

/* Get Bit                                        */
/* Description : given a register and a bit number*/
/*               it gets the corresponding bit in */
/*               that position in that register   */
#define GET_BIT(REG,BIT_NUM)		((REG & (1<<BIT_NUM)) >> BIT_NUM)


/* Assign Bit                                     */
/* Description : given a register, a bit number   */
/*               and a value, it assigns the      */
/*               corresponding bit in that        */
/*               position in that register with   */
/*               the specified value              */
#define ASSIGN_BIT(REG,BIT_NUM,VALUE)		do\
                                            {\
                                             REG &= ~(0x01<<BIT_NUM);\
                                             REG |= ((VALUE & 0x01)<<BIT_NUM);\
                                            }while(0)

/*--------------LOW NIBBLE OPERATIONS-------------*/
/* Set Low Nibble                                 */
/* Description : given a register, it sets the    */
/*               low nibble of this register      */
#define SET_LOW_NIBBLE(REG)		  (REG |= 0x0FU)

/* Clear Low Nibble                               */
/* Description : given a register, it clears the  */
/*               low nibble of this register      */
#define CLEAR_LOW_NIBBLE(REG)		(REG &= 0xF0U)

/* Get Low Nibble                                 */
/* Description : given a register, it gets the    */
/*               low nibble of this register      */
#define GET_LOW_NIBBLE(REG)		  ((REG & 0x0FU))


/* Assign Low Nibble                              */
/* Description : given a register and a value, it */
/*               assigns the low nibble of this   */
/*               register with that value         */
#define ASSIGN_LOW_NIBBLE(REG,BIT_NUM,VALUE)	do\
                                                {\
                                                  REG &= 0xF0U ;\
                                                  REG |= ((VALUE & 0x0FU));\
                                                }while(0)

/*-------------HIGH NIBBLE OPERATIONS-------------*/
/* Set High Nibble                                */
/* Description : given a register, it sets the    */
/*               high nibble of this register     */
#define SET_HIGH_NIBBLE(REG)		  (REG |= 0xF0U)

/* Clear High Nibble                              */
/* Description : given a register, it clears the  */
/*               high nibble of this register     */
#define CLEAR_HIGH_NIBBLE(REG)		(REG &= 0x0FU)

/* Get High Nibble                                */
/* Description : given a register, it gets the    */
/*               high nibble of this register     */
#define GET_HIGH_NIBBLE(REG)		  ((REG & 0xF0U)>>4)


/* Assign High Nibble                             */
/* Description : given a register and a value, it */
/*               assigns the high nibble of this  */
/*               register with that value         */
#define ASSIGN_HIGH_NIBBLE(REG,BIT_NUM,VALUE)		do\
                                                {\
                                                  REG &= 0x0FU ;\
                                                  REG |= ((VALUE & 0x0FU)<<4);\
                                                }while(0)

/* Comment : Concatenation function to concatenate*/
/*           bits together in a register          */ 
#define CONC_8BIT(b7,b6,b5,b4,b3,b2,b1,b0)    CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0 

#endif 
