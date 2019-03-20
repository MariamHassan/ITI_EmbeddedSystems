/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Mar 2019                      */   
/* Version     : V1.1                             */
/**************************************************/
/**************************************************/
/* Description : LCD Interface File               */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LCD_INTERFACE_H                           
#define LCD_INTERFACE_H

/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : 8bit sequence to initialize*/
/*                     the LCD to start writing   */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void LCD_void8BitLcdInit(void);

/* Initialization                                 */
/* Description       : 4bit sequence to initialize*/
/*                     the LCD to start writing   */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void LCD_void4BitLcdInit(void);

/* Clear Display                                  */
/* Description       : Clear the display to write */
/*                     from the (0,0) position    */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void LCD_voidClearDisplay(void);

/* Write Data                                     */
/* Description       : Write character/string on  */
/*                     LCD in the current position*/
/* Input Argument(s) : Pointer to string          */
/* Return            : Void                       */
void LCD_voidWriteData(u8 *Copy_u8Data);

/* Write Data in Specific Position                */
/* Description       : Write character/string on  */
/*                     LCD in a specific position */
/* Input Argument(s) : Pointer to string          */
/*                     X Position                 */
/*                     Y Position                 */
/* Options           : X from 0 to 16             */
/*                   : Y from 0 to 1              */
/* Return            : Error Status               */
u8 LCD_u8WriteInPosition(u8 *Copy_u8Data , u8 Copy_u8XPos , u8 Copy_u8YPos);

/* Store Pattern                                  */
/* Description       : Store special pattern in   */
/*                     CGRAM                      */
/* Input Argument(s) : Array of pattern value     */
/*                     Index to memory section    */
/* Return            : Error Status               */
u8 LCD_u8StorePattern(u8 Copy_Au8Pattern[8], u8 Copy_u8Index);

/* Write Pattern                                  */
/* Description       : Write special pattern on   */
/*                     LCD in the current position*/
/* Input Argument(s) : Index of pattern in CGRAM  */
/* Options           : From 0 to 7                */
/* Return            : Error Status               */
u8 LCD_u8WritePattern(u8 Copy_u8Index);

/* Write special pattern in Specific Position     */
/* Description       : Write special pattern on   */
/*                     LCD in a specific position */
/* Input Argument(s) : Index of pattern in CGRAM  */
/*                     X Position                 */
/*                     Y Position                 */
/* Options           : Index; from 0 to 7         */
/*                     X; from 0 to 15            */
/*                     Y; from 0 to 1             */
/* Return            : Error Status               */
u8 LCD_u8WritePatternInPosition(u8 Copy_u8Index , u8 Copy_u8XPos , u8 Copy_u8YPos);
#endif
