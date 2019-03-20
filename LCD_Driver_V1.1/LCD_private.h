/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Mar 2019                      */   
/* Version     : V1.1                             */
/**************************************************/
/**************************************************/
/* Description : LCD Private File                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/* Comment : Mode of operation                   */
/* Options : 8 bit mode                          */
/*           4 bit mode                          */
#define LCD_u8_4BIT_MODE	(u8)0
#define LCD_u8_8BIT_MODE	(u8)1
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Comment : Bits of values passed to Write func. */
#define LCD_u8_BIT0  (u8)0
#define LCD_u8_BIT1  (u8)1  
#define LCD_u8_BIT2  (u8)2
#define LCD_u8_BIT3  (u8)3
#define LCD_u8_BIT4  (u8)4
#define LCD_u8_BIT5  (u8)5  
#define LCD_u8_BIT6  (u8)6
#define LCD_u8_BIT7  (u8)7  
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Comment : Number of x and y positions          */
#define LCD_u8_X_POSITIONS		    (u8)16
#define LCD_u8_Y_POSITIONS		    (u8)2
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Comment : Visible window limit addresses       */
#define LCD_u8_LINE_0_BEGIN		    (u8)0x00
#define LCD_u8_LINE_0_VW		    (u8)0x0F
#define LCD_u8_LINE_0_END		    (u8)0x27
#define LCD_u8_LINE_1_BEGIN         (u8)0x40
#define LCD_u8_LINE_1_VW            (u8)0x4F
#define LCD_u8_LINE_1_END           (u8)0x67
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Comment : CGRAM Information                    */
#define LCD_u8_CGRAM_SECTIONS_NUM 	(u8)8
#define LCD_u8_CGRAM_INIT_ADD       (u8)0x00
#define LCD_u8_CGRAM_LOCATIONS_NUM  (u8)8
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Comment : API's prototypes                     */
/* Write Command                                  */
/* Description       : Instruction to LCD to      */
/*                     control it                 */
/* Input Argument(s) : Command Value              */   
/* Return            : Error Status               */
static void LCD_voidWriteCommand(u8 Copy_u8Command);

/* Write Character                                */
/* Description       : Write character on LCD     */
/* Input Argument(s) : Character value            */
/* Return            : Error Status               */
static void LCD_voidWriteChar(u8 Copy_u8Data);

/* Write                                          */
/* Description       : The write sequence in LCD  */
/*                     for either data or command */
/* Input Argument(s) : Command or Data Value      */   
/* Return            : Error Status               */
static void LCD_voidWrite(u8 Copy_u8DataCommand);

/* Set DDRAM Address                              */
/* Description       : Set the DDRAM address to   */
/*                     write in specific position */
/* Input Argument(s) : Address value              */   
/* Return            : Error Status               */
static void LCD_voidSetDdramAddress(u8 Copy_u8Address);

/* Set CGRAM Address                              */
/* Description       : Set the CGRAM address to   */
/*                     write in it special char's */
/* Input Argument(s) : Address value              */   
/* Return            : Error Status               */
static void LCD_voidSetCgramAddress(u8 Copy_u8Address);


#endif
