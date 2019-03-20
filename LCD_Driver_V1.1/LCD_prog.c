/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Mar 2019                      */   
/* Version     : V1.1                             */
/**************************************************/
/**************************************************/
/* Description : LCD Program File                 */
/**************************************************/
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DELAY_MS_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

/* Global variables declaration                   */
u8 LCD_u8_DataAddress;
u8 LCD_u8_PatternNumber;
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Initialization                                 */
/* Description       : 8bit sequence to initialize*/
/*                     the LCD to start writing   */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void LCD_void8BitLcdInit(void)
{
  //Delay on power on
  delay_milliSecond(40);
  
  //Set function
  LCD_voidWriteCommand(0b00111000);
  delay_milliSecond(2);
  
  //Display ON/OFF
  LCD_voidWriteCommand(0b00001100);
  delay_milliSecond(2);
  
  //Display Clear
  LCD_voidWriteCommand(0b0000001);
  delay_milliSecond(10);

  //Initialize global variables
  LCD_u8_DataAddress = 0x00;
  LCD_u8_PatternNumber = 0;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Initialization                                 */
/* Description       : 4bit sequence to initialize*/
/*                     the LCD to start writing   */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void LCD_void4BitLcdInit(void)
{
  //Delay on power on
  delay_milliSecond(40);
  
  //Set function
  LCD_voidWriteCommand(0b00100000);
  LCD_voidWriteCommand(0b00100000);
  LCD_voidWriteCommand(0b10000000);
  delay_milliSecond(2);
  
  //Display ON/OFF
  LCD_voidWriteCommand(0b00000000);
  LCD_voidWriteCommand(0b11100000);
  delay_milliSecond(2);
  
  //Display Clear
  LCD_voidWriteCommand(0b0000000);
  LCD_voidWriteCommand(0b00010000);
  delay_milliSecond(10);

  //Initialize global variables
  LCD_u8_DataAddress = 0x00;
  LCD_u8_PatternNumber = 0;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Clear Display                                  */
/* Description       : Clear the display to write */
/*                     from the (0,0) position    */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void LCD_voidClearDisplay(void)
{
	LCD_voidWriteCommand(0b0000001);
    delay_milliSecond(10);
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Write Data                                     */
/* Description       : Write character/string on  */
/*                     LCD in the current position*/
/* Input Argument(s) : Pointer to string          */
/* Return            : Void                       */
void LCD_voidWriteData(u8 *Copy_u8Data)
{
	LCD_voidSetDdramAddress(LCD_u8_DataAddress);

	while(*Copy_u8Data != '\0')
	      {
	    	LCD_voidWriteChar(*Copy_u8Data);
	        Copy_u8Data++;
	        LCD_u8_DataAddress++;

	        /*End of line 1*/
	        if (LCD_u8_DataAddress > LCD_u8_LINE_0_VW  && LCD_u8_DataAddress < LCD_u8_LINE_0_END)
	        {
	        	LCD_u8_DataAddress = LCD_u8_LINE_1_BEGIN;
	            LCD_voidSetDdramAddress(LCD_u8_DataAddress);
	        }
	        /*End of line 2*/
	        else if (LCD_u8_DataAddress > LCD_u8_LINE_1_VW && LCD_u8_DataAddress< LCD_u8_LINE_1_END )
	        {
	        	LCD_u8_DataAddress = LCD_u8_LINE_0_BEGIN;
	            LCD_voidSetDdramAddress(LCD_u8_DataAddress);
	        }
	      }
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Write Data in Specific Position                */
/* Description       : Write character/string on  */
/*                     LCD in a specific position */
/* Input Argument(s) : Pointer to string          */
/*                     X Position                 */
/*                     Y Position                 */
/* Return            : Error Status               */
u8 LCD_u8WriteInPosition(u8 *Copy_u8Data , u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	if ((Copy_u8XPos < LCD_u8_X_POSITIONS) && (Copy_u8YPos < LCD_u8_Y_POSITIONS))
	{
        LCD_u8_DataAddress  = Copy_u8XPos + (Copy_u8YPos * LCD_u8_LINE_1_BEGIN);

        LCD_voidWriteData(Copy_u8Data);
	}
	else
	{
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Store Pattern                                  */
/* Description       : Store special pattern in   */
/*                     CGRAM                      */
/* Input Argument(s) : Array of pattern value     */
/*                     Index to memory section    */
/* Return            : Error Status               */
u8 LCD_u8StorePattern(u8 Copy_Au8Pattern[8], u8 Copy_u8Index)
{
	u8 local_u8ErrorStatus = ERROR_OK;
	u8 Local_u8Loop;

	if ((Copy_u8Index < LCD_u8_CGRAM_SECTIONS_NUM) && (LCD_u8_PatternNumber <  LCD_u8_CGRAM_SECTIONS_NUM))
	{
	    //Switch to CGRAM
	    LCD_voidSetCgramAddress(LCD_u8_CGRAM_INIT_ADD+(Copy_u8Index*LCD_u8_CGRAM_LOCATIONS_NUM));

	    //Fill desired section in CGRAM with the pattern
	    for (Local_u8Loop=0 ; Local_u8Loop<LCD_u8_CGRAM_LOCATIONS_NUM ; Local_u8Loop++)
	    {
	    	LCD_voidWriteChar(Copy_Au8Pattern[Local_u8Loop]);
	    }

	    //Increase number of patterns stored counter
	    LCD_u8_PatternNumber++;
	}
	else
	{
		local_u8ErrorStatus = ERROR_NOK;
	}
	return local_u8ErrorStatus;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Write Pattern                                  */
/* Description       : Write special pattern on   */
/*                     LCD in the current position*/
/* Input Argument(s) : Index of pattern in CGRAM  */
/* Options           : From 0 to 7                */
/* Return            : Error Status               */
u8 LCD_u8WritePattern(u8 Copy_u8Index)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	//Switch back to DDRAM
	LCD_voidSetDdramAddress(LCD_u8_DataAddress);

	if (Copy_u8Index <  LCD_u8_CGRAM_SECTIONS_NUM)
	{
	    //Check current position on LCD
        //End of line 1
        if (LCD_u8_DataAddress > LCD_u8_LINE_0_VW  && LCD_u8_DataAddress < LCD_u8_LINE_0_END)
        {
        	LCD_u8_DataAddress = LCD_u8_LINE_1_BEGIN;
        	LCD_voidSetDdramAddress(LCD_u8_DataAddress);
        }
        //End of line 2
        else if (LCD_u8_DataAddress > LCD_u8_LINE_1_VW && LCD_u8_DataAddress< LCD_u8_LINE_1_END )
        {
        	LCD_u8_DataAddress = LCD_u8_LINE_0_BEGIN;
        	LCD_voidSetDdramAddress(LCD_u8_DataAddress);
        }

        //Display the pattern form CGRAM
        LCD_voidWriteChar(Copy_u8Index);
        LCD_u8_DataAddress++;
	    }
	    else
	    {
	    	Local_u8ErrorStatus = ERROR_NOK;
	    }
	return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
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
u8 LCD_u8WritePatternInPosition(u8 Copy_u8Index , u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	if ((Copy_u8XPos < LCD_u8_X_POSITIONS) && (Copy_u8YPos < LCD_u8_Y_POSITIONS))
	{
		//Set the DDRAM address
		LCD_u8_DataAddress  = Copy_u8XPos + (Copy_u8YPos * LCD_u8_LINE_1_BEGIN);

		LCD_u8WritePattern(Copy_u8Index);
	}
	else
	{
	  	Local_u8ErrorStatus = ERROR_NOK;
	 }
	 return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Write Command                                  */
/* Description       : Instruction to LCD to      */
/*                     control it                 */
/* Input Argument(s) : Command Value              */   
/* Return            : Void                       */
static void LCD_voidWriteCommand(u8 Copy_u8Command)
{
   DIO_u8SetPinValue(LCD_u8_RS,DIO_u8_PIN_LOW);
   LCD_voidWrite(Copy_u8Command);
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Write Character                                */
/* Description       : Write character on LCD     */
/* Input Argument(s) : Character value            */
/* Return            : Void                       */
static void LCD_voidWriteChar(u8 Copy_u8Data)
{
    DIO_u8SetPinValue(LCD_u8_RS,DIO_u8_PIN_HIGH);
    LCD_voidWrite(Copy_u8Data);
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Write                                          */
/* Description       : The write sequence in LCD  */
/*                     for either data or command */
/* Input Argument(s) : Command or Data Value      */   
/* Return            : Void                       */
static void LCD_voidWrite(u8 Copy_u8DataCommand)
{
  DIO_u8SetPinValue(LCD_u8_RW,DIO_u8_PIN_LOW);
  DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_LOW);
  
  DIO_u8SetPinValue(LCD_u8_D0, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT0));
  DIO_u8SetPinValue(LCD_u8_D1, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT1));
  DIO_u8SetPinValue(LCD_u8_D2, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT2));
  DIO_u8SetPinValue(LCD_u8_D3, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT3));
  DIO_u8SetPinValue(LCD_u8_D4, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT4));
  DIO_u8SetPinValue(LCD_u8_D5, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT5));
  DIO_u8SetPinValue(LCD_u8_D6, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT6));
  DIO_u8SetPinValue(LCD_u8_D7, GET_BIT(Copy_u8DataCommand, LCD_u8_BIT7));
  
  DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_HIGH);
  delay_milliSecond(10);
  DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_LOW);
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Set DDRAM Address                              */
/* Description       : Set the DDRAM address to   */
/*                     write on specific position */
/* Input Argument(s) : Address value              */   
/* Return            : Void                       */
static void LCD_voidSetDdramAddress(u8 Copy_u8Address)
{
	Copy_u8Address |= 0x80;
	LCD_voidWriteCommand(Copy_u8Address);
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/* Set CGRAM Address                              */
/* Description       : Set the CGRAM address to   */
/*                     write in it special chars  */
/* Input Argument(s) : Address value              */   
/* Return            : Void                       */
static void LCD_voidSetCgramAddress(u8 Copy_u8Address)
{
	Copy_u8Address &= 0x7F; //to make bit7 zero
	Copy_u8Address |= 0x40; //to make bit6 one
	LCD_voidWriteCommand(Copy_u8Address);
}

