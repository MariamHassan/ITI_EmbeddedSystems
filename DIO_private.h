/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : DIO Private File                 */
/*               This file has:                   */   
/*                1- Initial pins direction macros*/
/*                2- Initial pins values macros   */
/*                3- The addresses of the         */
/*                   micro-controller registers.  */
/**************************************************/
/* Preprocessor Guard                                */
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* Comment : Initial value on pins when setting   */
/*           it into input or output. These        */
/*           values are micro-controller dependent.  */
#define DIO_u8_PIN_INIT_INPUT  0   
#define DIO_u8_PIN_INIT_OUTPUT 1   

/* Comment : Initial value on pins when setting   */
/*           it to high, low or default. These    */
/*           values are microntroller dependent.  */ 
#define DIO_u8_PIN_INIT_HIGH   1 
#define DIO_u8_PIN_INIT_LOW    0
#define DIO_u8_PIN_INIT_DEF    0

/* Comment : The addresses of microntroller       */
/*           ports registers. DDR,PORT and PIN.   */
/*           These values are microntroller       */
/*           dependent.                           */  
#define DIO_u8_DDRA   ((Register_8Bit*) 0x3A)
#define DIO_u8_PINA   ((Register_8Bit*) 0x39)
#define DIO_u8_PORTA  ((Register_8Bit*) 0x3B)

#define DIO_u8_DDRB   ((Register_8Bit*) 0x37)
#define DIO_u8_PINB   ((Register_8Bit*) 0x36)
#define DIO_u8_PORTB  ((Register_8Bit*) 0x38)
               
#define DIO_u8_DDRC   ((Register_8Bit*) 0x34)
#define DIO_u8_PINC   ((Register_8Bit*) 0x33)
#define DIO_u8_PORTC  ((Register_8Bit*) 0x35)
               
#define DIO_u8_DDRD   ((Register_8Bit*) 0x31)
#define DIO_u8_PIND   ((Register_8Bit*) 0x30)
#define DIO_u8_PORTD  ((Register_8Bit*) 0x32)


#endif
