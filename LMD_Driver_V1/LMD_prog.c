/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 12 Feb 2019                      */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LMD Program File                 */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "Delay.h"
#include "DIO_interface.h"
#include "LMD_interface.h"
#include "LMD_private.h"
#include "LMD_config.h"

/* Initialization                                 */
/* Description       : Initializes the LMD        */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void LMD_voidInit(void){

}

/* Display Image                                  */
/* Description       : Display an image on the LMD*/
/* Input Argument(s) : pointer to image array and */
/*                     color of image             */
/* Return            : Error Status               */
u8 LMD_u8LmdDisplay(u8 *Copy_u8LmdImage, u8 Copy_u8LmdColor){
/* Local variables declaration                    */
	  u8 Local_u8ErrorStatus;
	  u8 Local_u8OutLoop;
	  u8 Local_u8InLoop;

/* First activate the pins that activate the LMD  */
	  DIO_u8SetPortDirection(LMD_u8_ACTIVE_PORT , DIO_u8_PORT_OUTPUT);

/* Second check color selected then display image */
	  switch (Copy_u8LmdColor){
	  case LMD_u8_GREEN:
		  DIO_u8SetPortDirection(LMD_u8_GREEN_PORT , DIO_u8_PORT_OUTPUT);
		  for (Local_u8OutLoop=0 ; Local_u8OutLoop<18 ; Local_u8OutLoop++){
			  for (Local_u8InLoop=0 ; Local_u8InLoop<8 ; Local_u8InLoop++){
				  if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_LOW){
					  DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , ~(1 << Local_u8InLoop));
					  DIO_u8SetPortValue(LMD_u8_GREEN_PORT , Copy_u8LmdImage[Local_u8InLoop]);
					  Delay(1);
			      }else if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_HIGH){
			  	      DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , (1 << Local_u8InLoop));
			  	      DIO_u8SetPortValue(LMD_u8_GREEN_PORT , Copy_u8LmdImage[Local_u8InLoop]);
			  	      Delay(1);
			      }
			  }
		  }

		  Local_u8ErrorStatus = ERROR_OK;
	  break;

	  case LMD_u8_RED:
		  DIO_u8SetPortDirection(LMD_u8_RED_PORT , DIO_u8_PORT_OUTPUT);
		  for (Local_u8OutLoop=0 ; Local_u8OutLoop<18 ; Local_u8OutLoop++){
			  for (Local_u8InLoop=0 ; Local_u8InLoop<8 ; Local_u8InLoop++){
				  if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_LOW){
				  	  DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , ~(1 << Local_u8InLoop));
				      DIO_u8SetPortValue(LMD_u8_RED_PORT , Copy_u8LmdImage[Local_u8InLoop]);
				  	  Delay(1);
				  }else if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_HIGH){
				  	   DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , (1 << Local_u8InLoop));
				  	   DIO_u8SetPortValue(LMD_u8_RED_PORT , Copy_u8LmdImage[Local_u8InLoop]);
					   Delay(1);
				  }
		      }
		  }


		  Local_u8ErrorStatus = ERROR_OK;
	  break;

	  default:
		  Local_u8ErrorStatus = ERROR_NOK;
	  }

	  return Local_u8ErrorStatus;
}
