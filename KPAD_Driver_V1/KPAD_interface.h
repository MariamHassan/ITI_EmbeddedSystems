/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Feb 2019                      */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : KPAD Interface File              */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef KPAD_INTERFACE_H
#define KPAD_INTERFACE_H

/* Comment : Key States                           */
#define KPAD_u8_PRESSED     (u8)1
#define KPAD_u8_RELEASED    (u8)0

/* Get Pressed Keys                               */
/* Description       : Activate the columns and   */
/*                     then scan rows to detect   */ 
/*                     pressed keys and then store*/ 
/*                     them in an array           */
/* Input Argument(s) : pointer to 2D array of size*/
/*                     rows x cols                */
/* Return            : Error Status               */
u8 KPAD_u8GetKeysPressed(u8 Copy_u8KpadKeys[3][3]);

#endif
