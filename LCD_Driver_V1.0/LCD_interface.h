/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 4 Mar 2019                       */   
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : LCD Interface File               */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LCD_INTERFACE_H                           
#define LCD_INTERFACE_H

/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Sequence to initialize the */
/*                     LCD to start writing       */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void LCD_voidLcdInit(void);

/* Write Command                                  */
/* Description       : Send commands to LCD to    */
/*                     perform specific task      */
/* Input Argument(s) : Command number             */
/* Return            : Error Status               */
u8 LCD_u8WriteCommand(u8 Copy_u8Command);

/* Write Data                                     */
/* Description       : Write a character on LCD   */
/* Input Argument(s) : character                  */
/* Return            : Error Status               */
u8 LCD_u8WriteData(u8 Copy_u8Data);

#endif
