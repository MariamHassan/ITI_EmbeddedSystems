/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 4 Mar 2019                       */   
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : LCD Private File                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/* Write                                          */
/* Description       : The write sequence on LCD  */
/*                     either for command or data */
/* Input Argument(s) : Data or command value      */
/* Return            : Error Status               */
static u8 u8Write(u8 Copy_u8DataCommand);

#endif
