/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 4 Mar 2019                       */   
/* Version     : V1.0                             */
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
 
/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Sequence to initialize the */
/*                     LCD to start writing       */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void LCD_voidLcdInit(void)
{
    //Delay on power on
    delay_milliSecond(40);

    //Set function
    LCD_u8WriteCommand(0b00111000); //0x38
    delay_milliSecond(2);

    //Display ON/OFF
    LCD_u8WriteCommand(0b00001110); //0x0E
    delay_milliSecond(2);

    //Display Clear
    LCD_u8WriteCommand(0b0000001); //0x01
    delay_milliSecond(10);
}
 

/* Write Command                                  */
/* Description       : Send commands to LCD to    */
/*                     perform specific task      */
/* Input Argument(s) : Command number             */
/* Return            : Error Status               */
u8 LCD_u8WriteCommand(u8 Copy_u8Command){
   u8 Local_u8Result = ERROR_OK;
   
   DIO_u8SetPinValue(LCD_u8_RS,DIO_u8_PIN_LOW);
   Local_u8Result = u8Write(Copy_u8Command);
   
   return Local_u8Result;
}

/* Write Data                                     */
/* Description       : Write a character on LCD   */
/* Input Argument(s) : character                  */
/* Return            : Error Status               */
u8 LCD_u8WriteData(u8 Copy_u8Data){
   u8 Local_u8Result = ERROR_OK;
   
   DIO_u8SetPinValue(LCD_u8_RS,DIO_u8_PIN_HIGH);
   Local_u8Result = u8Write(Copy_u8Data);
   
   return Local_u8Result;
}


/* Write                                          */
/* Description       : The write sequence on LCD  */
/*                     either for command or data */
/* Input Argument(s) : Data or command value      */
/* Return            : Error Status               */
static u8 u8Write(u8 Copy_u8DataCommand){
  u8 Local_u8Result = ERROR_OK;
  
  DIO_u8SetPinValue(LCD_u8_RW,DIO_u8_PIN_LOW);
  DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_LOW);
  
  DIO_u8SetPinValue(LCD_u8_D0,GET_BIT(Copy_u8DataCommand,0));
  DIO_u8SetPinValue(LCD_u8_D1,GET_BIT(Copy_u8DataCommand,1));
  DIO_u8SetPinValue(LCD_u8_D2,GET_BIT(Copy_u8DataCommand,2));
  DIO_u8SetPinValue(LCD_u8_D3,GET_BIT(Copy_u8DataCommand,3));
  DIO_u8SetPinValue(LCD_u8_D4,GET_BIT(Copy_u8DataCommand,4));
  DIO_u8SetPinValue(LCD_u8_D5,GET_BIT(Copy_u8DataCommand,5));
  DIO_u8SetPinValue(LCD_u8_D6,GET_BIT(Copy_u8DataCommand,6));
  DIO_u8SetPinValue(LCD_u8_D7,GET_BIT(Copy_u8DataCommand,7));
  
  DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_HIGH);
  delay_milliSecond(10);
  DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_LOW);
  
  return Local_u8Result;
}


