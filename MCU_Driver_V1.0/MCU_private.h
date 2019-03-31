/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 24 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : MCU Private File                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef MCU_PRIVATE_H
#define MCU_PRIVATE_H

/* Comment : The address of SREG                  */
#define MCU_u8_SREG    ((Register_8Bit*) 0x5F)

/* Comment : The number corresponding to the      */
/*           global interrupt's enable bit in the */
/*           SREG                                 */
#define MCU_GIE 		7

/* Comment : Values written in the registers      */
#define MCU_GIE_ENABLE			1
#define MCU_GIE_DISABLE     	0

#endif
