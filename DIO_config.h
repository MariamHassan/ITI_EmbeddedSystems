/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : DIO Configuration File           */
/*               This file describes the initial  */
/*               values and directions of the     */
/*               pins of the AVR                  */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* Comment :   Initial Pin Directions             */
/* Range   :   DIO_u8_PIN_INIT_OUTPUT             */
/*             DIO_u8_PIN_INIT_INPUT              */
#define DIO_u8_PIN0_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN1_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN2_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN3_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN4_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN5_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN6_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN7_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
                    
#define DIO_u8_PIN8_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN9_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN10_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN11_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN12_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN13_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN14_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN15_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
                    
#define DIO_u8_PIN16_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN17_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN18_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN19_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN20_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN21_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN22_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN23_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
                    
#define DIO_u8_PIN24_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN25_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN26_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN27_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN28_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN29_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN30_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN31_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT

/* Comment :   Initial Pin Values                 */
/* Range   :   define DIO_u8_PIN_INIT_HIGH        */
/*             define DIO_u8_PIN_INIT_LOW         */
/*             define DIO_u8_PIN_INIT_DEF         */
/*                                                */
/* Warning :   Input pins mustn't be written on!  */    
#define DIO_u8_PIN0_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN1_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN2_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN3_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN4_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN5_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN6_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN7_INIT_VALUE   DIO_u8_PIN_INIT_DEF
                    
#define DIO_u8_PIN8_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN9_INIT_VALUE   DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN10_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN11_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN12_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN13_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN14_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN15_INIT_VALUE  DIO_u8_PIN_INIT_DEF
                    
#define DIO_u8_PIN16_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN17_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN18_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN19_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN20_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN21_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN22_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN23_INIT_VALUE  DIO_u8_PIN_INIT_DEF
                    
#define DIO_u8_PIN24_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN25_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN26_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN27_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN28_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN29_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN30_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#define DIO_u8_PIN31_INIT_VALUE  DIO_u8_PIN_INIT_DEF

#endif
