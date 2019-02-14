/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : Switch Program File              */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

/* Initialization                                 */
/* Description       : Initializes the SW         */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void SW_voidInit(void){

}

/* Get Switch State                               */
/* Description       : get the state of the SW    */
/* Input Argument(s) : SW's ID & Pointer to the   */
/*                     value got from switch      */
/* Return            : Error Status               */
u8 SW_u8GetSwState(u8 Copy_u8SwId, u8* Copy_u8ValuePtr){
/* Local variables declaration                    */
	  u8  Local_u8ErrorStatus;
	  u8* Local_u8SwStatePtr;

	  if (SW_Au8SwArray[Copy_u8SwId][SW_u8_CONNECTION_TYPE] == SW_u8_PULL_UP ){
		  DIO_u8GetPinValue(SW_Au8SwArray[Copy_u8SwId][SW_u8_PIN_NUMBER],Local_u8SwStatePtr);
		  if ((*Local_u8SwStatePtr) == SW_u8_PULL_UP_PRESSED){
			  *Copy_u8ValuePtr = SW_u8_PRESSED;
		  }else if ((*Local_u8SwStatePtr) == SW_u8_PULL_UP_RELEASED){
			  *Copy_u8ValuePtr = SW_u8_RELEASED;
		  }else{
			  Local_u8ErrorStatus = ERROR_NOK;
		  }
	  }else if (SW_Au8SwArray[Copy_u8SwId][SW_u8_CONNECTION_TYPE] == SW_u8_PULL_DOWN ){
		  DIO_u8GetPinValue(SW_Au8SwArray[Copy_u8SwId][SW_u8_PIN_NUMBER],Local_u8SwStatePtr);
		   if ((*Local_u8SwStatePtr) == SW_u8_PULL_DOWN_PRESSED){
		    *Copy_u8ValuePtr = SW_u8_PRESSED;
		   }else if ((*Local_u8SwStatePtr) == SW_u8_PULL_DOWN_RELEASED){
		    *Copy_u8ValuePtr = SW_u8_RELEASED;
		   }else{
		    Local_u8ErrorStatus = ERROR_NOK;
		   }
	  }else {
		  Local_u8ErrorStatus = ERROR_NOK;
	  }

	  return Local_u8ErrorStatus;
}
