/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LED Program File                 */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

/* Initialization                                 */
/* Description       : Initialize the LED         */ 
/* Input Argument(s) : void                       */
/* Return            : void                       */
void LED_voidInit(void){
  
}

/* Turn LED On                                    */
/* Description       : Turn the LED on            */ 
/* Input Argument(s) : LED ID                     */
/* Return            : Error Status               */
u8 LED_u8LedOn(u8 Copy_u8LedId){
/* Local variables declaration                    */
  u8 Local_u8ErrorStatus;
  
/* Set specified pin direction to output          */ 
  DIO_u8SetPinDirection(LED_Au8LedArray[Copy_u8LedId][LED_u8_PIN_NUMBER], DIO_u8_PIN_OUTPUT);
  
/* Set specified pin value to HIGH or LOW         */
/* according to LED's connection                  */
  if (LED_Au8LedArray[Copy_u8LedId][LED_u8_CONNECTION_TYPE] == LED_u8_CONNECTION_FORWARD){
    
    DIO_u8SetPinValue(LED_Au8LedArray[Copy_u8LedId][LED_u8_PIN_NUMBER], LED_u8_FORWARD_ON);
    Local_u8ErrorStatus = ERROR_OK;
    
  }else if (LED_Au8LedArray[Copy_u8LedId][LED_u8_CONNECTION_TYPE] == LED_u8_CONNECTION_REVERSE){
    
    DIO_u8SetPinValue(LED_Au8LedArray[Copy_u8LedId][LED_u8_PIN_NUMBER], LED_u8_REVERSE_ON);
    Local_u8ErrorStatus = ERROR_OK;
    
  }else{
    
    Local_u8ErrorStatus = ERROR_NOK;
    
  }

  return Local_u8ErrorStatus;
}

/* Turn LED Off                                   */
/* Description       : Turn the LED off           */ 
/* Input Argument(s) : Pin Number & Type          */
/* Return            : Error Status               */
u8 LED_u8LedOff(u8 Copy_u8LedId){
/* Local variables declaration                    */
  u8 Local_u8ErrorStatus;
  
/* Set specified pin direction to output          */ 
  DIO_u8SetPinDirection(LED_Au8LedArray[Copy_u8LedId][LED_u8_PIN_NUMBER], DIO_u8_PIN_OUTPUT);
  
/* Set specified pin value to HIGH or LOW         */
/* according to LED's connection                  */
  if (LED_Au8LedArray[Copy_u8LedId][LED_u8_CONNECTION_TYPE] == LED_u8_CONNECTION_FORWARD){
    
    DIO_u8SetPinValue(LED_Au8LedArray[Copy_u8LedId][LED_u8_PIN_NUMBER], LED_u8_FORWARD_OFF);
    Local_u8ErrorStatus = ERROR_OK;
    
  }else if (LED_Au8LedArray[Copy_u8LedId][LED_u8_CONNECTION_TYPE] == LED_u8_CONNECTION_REVERSE){
    
    DIO_u8SetPinValue(LED_Au8LedArray[Copy_u8LedId][LED_u8_PIN_NUMBER], LED_u8_REVERSE_OFF);
    Local_u8ErrorStatus = ERROR_OK;
    
  }else{
    
    Local_u8ErrorStatus = ERROR_NOK;
    
  }

  return Local_u8ErrorStatus;
}
