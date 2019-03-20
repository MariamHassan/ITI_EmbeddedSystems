/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 10 Mar 2019                      */
/* Version     : V1.1                             */
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

	  u8 Local_u8RowValue;
	  u8 Local_u8ColValue;

/* First activate the pins that activate the LMD  */
	  //DIO_u8SetPortDirection(LMD_u8_ACTIVE_PORT , DIO_u8_PORT_OUTPUT);

/* Second check color selected then display image */
	  switch (Copy_u8LmdColor){
	  case LMD_u8_GREEN:
		  //DIO_u8SetPortDirection(LMD_u8_GREEN_PORT , DIO_u8_PORT_OUTPUT);
		  for (Local_u8OutLoop=0 ; Local_u8OutLoop<18 ; Local_u8OutLoop++)
		  {
			  for (Local_u8InLoop=0 ; Local_u8InLoop<8 ; Local_u8InLoop++)
			  {
				  if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_LOW)
				  {
					  /*controlling rows' values*/
					  Local_u8RowValue = ~(1 << Local_u8InLoop);
					  //DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , ~(1 << Local_u8InLoop));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE0, GET_BIT(Local_u8RowValue,0));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE1, GET_BIT(Local_u8RowValue,1));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE2, GET_BIT(Local_u8RowValue,2));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE3, GET_BIT(Local_u8RowValue,3));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE4, GET_BIT(Local_u8RowValue,4));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE5, GET_BIT(Local_u8RowValue,5));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE6, GET_BIT(Local_u8RowValue,6));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE7, GET_BIT(Local_u8RowValue,7));

					  /*controlling cols' values*/
					  Local_u8ColValue = Copy_u8LmdImage[Local_u8InLoop];
					  //DIO_u8SetPortValue(LMD_u8_GREEN_PORT , Copy_u8LmdImage[Local_u8InLoop]);
					  DIO_u8SetPinValue(LMD_u8_GREEN0, GET_BIT(Local_u8ColValue,0));
					  DIO_u8SetPinValue(LMD_u8_GREEN1, GET_BIT(Local_u8ColValue,1));
					  DIO_u8SetPinValue(LMD_u8_GREEN2, GET_BIT(Local_u8ColValue,2));
					  DIO_u8SetPinValue(LMD_u8_GREEN3, GET_BIT(Local_u8ColValue,3));
					  DIO_u8SetPinValue(LMD_u8_GREEN4, GET_BIT(Local_u8ColValue,4));
					  DIO_u8SetPinValue(LMD_u8_GREEN5, GET_BIT(Local_u8ColValue,5));
					  DIO_u8SetPinValue(LMD_u8_GREEN6, GET_BIT(Local_u8ColValue,6));
					  DIO_u8SetPinValue(LMD_u8_GREEN7, GET_BIT(Local_u8ColValue,7));

					  Delay(100);
			      }
				  else if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_HIGH)
				  {
					  /*controlling rows' values*/
					 Local_u8RowValue = (1 << Local_u8InLoop);
					 //DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , (1 << Local_u8InLoop));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE0, GET_BIT(Local_u8RowValue,0));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE1, GET_BIT(Local_u8RowValue,1));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE2, GET_BIT(Local_u8RowValue,2));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE3, GET_BIT(Local_u8RowValue,3));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE4, GET_BIT(Local_u8RowValue,4));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE5, GET_BIT(Local_u8RowValue,5));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE6, GET_BIT(Local_u8RowValue,6));
					 DIO_u8SetPinValue(LMD_u8_ACTIVE7, GET_BIT(Local_u8RowValue,7));

					 /*controlling cols' values*/
					 Local_u8ColValue = Copy_u8LmdImage[Local_u8InLoop];
					 //DIO_u8SetPortValue(LMD_u8_GREEN_PORT , Copy_u8LmdImage[Local_u8InLoop]);
					 DIO_u8SetPinValue(LMD_u8_GREEN0, GET_BIT(Local_u8ColValue,0));
					 DIO_u8SetPinValue(LMD_u8_GREEN1, GET_BIT(Local_u8ColValue,1));
					 DIO_u8SetPinValue(LMD_u8_GREEN2, GET_BIT(Local_u8ColValue,2));
					 DIO_u8SetPinValue(LMD_u8_GREEN3, GET_BIT(Local_u8ColValue,3));
					 DIO_u8SetPinValue(LMD_u8_GREEN4, GET_BIT(Local_u8ColValue,4));
					 DIO_u8SetPinValue(LMD_u8_GREEN5, GET_BIT(Local_u8ColValue,5));
					 DIO_u8SetPinValue(LMD_u8_GREEN6, GET_BIT(Local_u8ColValue,6));
					 DIO_u8SetPinValue(LMD_u8_GREEN7, GET_BIT(Local_u8ColValue,7));

			  	     Delay(100);
			      }
			  }
		  }

		  Local_u8ErrorStatus = ERROR_OK;
	  break;

	  case LMD_u8_RED:
		  //DIO_u8SetPortDirection(LMD_u8_RED_PORT , DIO_u8_PORT_OUTPUT);
		  for (Local_u8OutLoop=0 ; Local_u8OutLoop<18 ; Local_u8OutLoop++)
		  {
			  for (Local_u8InLoop=0 ; Local_u8InLoop<8 ; Local_u8InLoop++)
			  {
				  if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_LOW)
				  {
					  /*controlling rows' values*/
					  Local_u8RowValue = ~(1 << Local_u8InLoop);
					  //DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , ~(1 << Local_u8InLoop));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE0, GET_BIT(Local_u8RowValue,0));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE1, GET_BIT(Local_u8RowValue,1));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE2, GET_BIT(Local_u8RowValue,2));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE3, GET_BIT(Local_u8RowValue,3));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE4, GET_BIT(Local_u8RowValue,4));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE5, GET_BIT(Local_u8RowValue,5));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE6, GET_BIT(Local_u8RowValue,6));
					  DIO_u8SetPinValue(LMD_u8_ACTIVE7, GET_BIT(Local_u8RowValue,7));

					  /*controlling cols' values*/
					  Local_u8ColValue = Copy_u8LmdImage[Local_u8InLoop];
					  //DIO_u8SetPortValue(LMD_u8_RED_PORT , Copy_u8LmdImage[Local_u8InLoop]);
					  DIO_u8SetPinValue(LMD_u8_RED0, GET_BIT(Local_u8ColValue,0));
					  DIO_u8SetPinValue(LMD_u8_RED1, GET_BIT(Local_u8ColValue,1));
					  DIO_u8SetPinValue(LMD_u8_RED2, GET_BIT(Local_u8ColValue,2));
					  DIO_u8SetPinValue(LMD_u8_RED3, GET_BIT(Local_u8ColValue,3));
					  DIO_u8SetPinValue(LMD_u8_RED4, GET_BIT(Local_u8ColValue,4));
					  DIO_u8SetPinValue(LMD_u8_RED5, GET_BIT(Local_u8ColValue,5));
					  DIO_u8SetPinValue(LMD_u8_RED6, GET_BIT(Local_u8ColValue,6));
					  DIO_u8SetPinValue(LMD_u8_RED7, GET_BIT(Local_u8ColValue,7));

				  	  Delay(100);
				  }
				  else if (LMD_u8_ACTIVE_LEVEL == LMD_u8_ACTIVE_HIGH)
				  {
					  /*controlling rows' values*/
					   Local_u8RowValue = (1 << Local_u8InLoop);
					   //DIO_u8SetPortValue(LMD_u8_ACTIVE_PORT , (1 << Local_u8InLoop));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE0, GET_BIT(Local_u8RowValue,0));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE1, GET_BIT(Local_u8RowValue,1));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE2, GET_BIT(Local_u8RowValue,2));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE3, GET_BIT(Local_u8RowValue,3));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE4, GET_BIT(Local_u8RowValue,4));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE5, GET_BIT(Local_u8RowValue,5));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE6, GET_BIT(Local_u8RowValue,6));
					   DIO_u8SetPinValue(LMD_u8_ACTIVE7, GET_BIT(Local_u8RowValue,7));

					   /*controlling cols' values*/
					   Local_u8ColValue = Copy_u8LmdImage[Local_u8InLoop];
					   //DIO_u8SetPortValue(LMD_u8_RED_PORT , Copy_u8LmdImage[Local_u8InLoop]);
					   DIO_u8SetPinValue(LMD_u8_RED0, GET_BIT(Local_u8ColValue,0));
					   DIO_u8SetPinValue(LMD_u8_RED1, GET_BIT(Local_u8ColValue,1));
					   DIO_u8SetPinValue(LMD_u8_RED2, GET_BIT(Local_u8ColValue,2));
					   DIO_u8SetPinValue(LMD_u8_RED3, GET_BIT(Local_u8ColValue,3));
					   DIO_u8SetPinValue(LMD_u8_RED4, GET_BIT(Local_u8ColValue,4));
					   DIO_u8SetPinValue(LMD_u8_RED5, GET_BIT(Local_u8ColValue,5));
					   DIO_u8SetPinValue(LMD_u8_RED6, GET_BIT(Local_u8ColValue,6));
					   DIO_u8SetPinValue(LMD_u8_RED7, GET_BIT(Local_u8ColValue,7));

					   Delay(100);
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
