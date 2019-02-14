/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : SSD Program File                 */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

/* Global variables declaration                   */
u8 SSD_u8_LastValue;
u8 SSD_u8_SddState;

/* Initialization                                 */
/* Description       : Initializes the SSD        */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void SSD_voidInit(void){
	SSD_u8_LastValue = ZERO;
}

/* Set SSD On                                     */
/* Description       : Turns the LED on, on the   */
/*                     previous value             */
/* Input Argument(s) : SSD ID                     */
/* Return            : Error Status               */
u8 SSD_u8SetOn(u8 Copy_u8SsdId){
/* Local variables declaration                    */
	  u8 Local_u8ErrorStatus;

	  SSD_u8_SddState = SDD_u8_STATE_ON;
	  Local_u8ErrorStatus = SSD_u8SetValue(Copy_u8SsdId, SSD_u8_LastValue);

	  return Local_u8ErrorStatus;
}

/* Set SSD Off                                    */
/* Description       : Turns the SSD off          */
/* Input Argument(s) : SSD ID                     */
/* Return            : Error Status               */
u8 SSD_u8SetOff(u8 Copy_u8SsdId){
/* Local variables declaration                    */
	  u8 Local_u8ErrorStatus;

	  SSD_u8_SddState = SDD_u8_STATE_OFF;

	  if ((SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_TYPE])==SSD_u8_COMMON_CATHODE){
	 		  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_EN_SEGMENT_PIN], SSD_u8_COMMON_CATHODE_DIS);
	 		 Local_u8ErrorStatus = ERROR_OK;
	  }else  if ((SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_TYPE])==SSD_u8_COMMON_ANODE){
		     DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_EN_SEGMENT_PIN], SSD_u8_COMMON_ANODE_DIS);
		     Local_u8ErrorStatus = ERROR_OK;
	  }else{
		  Local_u8ErrorStatus = ERROR_NOK;
	  }

	  return Local_u8ErrorStatus;
}

/* Set value on SSD                               */
/* Description       : Writes a value on SSD      */
/* Input Argument(s) : SSD ID and Value           */
/* Return            : Error Status               */
u8 SSD_u8SetValue(u8 Copy_u8SsdId, u8 Copy_u8Value){
/* Local variables declaration                    */
	  u8 Local_u8ErrorStatus;

	  if (SSD_u8_SddState == SDD_u8_STATE_OFF){
		  return Local_u8ErrorStatus;
	  }
/* Set the pins, attached to the SSD, direction to*/
/* be output                                      */
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);
	  DIO_u8SetPinDirection(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_EN_SEGMENT_PIN], DIO_u8_PIN_OUTPUT);

/* Check if the SSD is common cathode or anode  */
/* to assign the enable pin accordingly then    */
/* display value by referring to the look up    */
/* table                                        */
	  if ((SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_TYPE])==SSD_u8_COMMON_CATHODE){
		  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_EN_SEGMENT_PIN], SSD_u8_COMMON_CATHODE_EN);

		  switch(Copy_u8Value){
		  case NINE:
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
					            SSD_Au8CommonCathodeNum9[SSD_u8_A_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
			  					SSD_Au8CommonCathodeNum9[SSD_u8_B_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
			  					SSD_Au8CommonCathodeNum9[SSD_u8_C_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
			  					SSD_Au8CommonCathodeNum9[SSD_u8_D_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
			  					SSD_Au8CommonCathodeNum9[SSD_u8_E_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
			  					SSD_Au8CommonCathodeNum9[SSD_u8_F_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
			  					SSD_Au8CommonCathodeNum9[SSD_u8_G_SEGMENT_VALUE]);

			  Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case EIGHT:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum8[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum8[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum8[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum8[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum8[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum8[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum8[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case SEVEN:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum7[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum7[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum7[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum7[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum7[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum7[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum7[SSD_u8_G_SEGMENT_VALUE]);
		  break;

		  case SIX:
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		   			           SSD_Au8CommonCathodeNum6[SSD_u8_A_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum6[SSD_u8_B_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum6[SSD_u8_C_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum6[SSD_u8_D_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum6[SSD_u8_E_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum6[SSD_u8_F_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum6[SSD_u8_G_SEGMENT_VALUE]);

		   	Local_u8ErrorStatus = ERROR_OK;
		   break;

		  case FIVE:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum5[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum5[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum5[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum5[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum5[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum5[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum5[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case FOUR:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum4[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum4[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum4[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum4[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum4[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum4[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum4[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case THREE:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum3[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum3[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum3[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum3[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum3[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum3[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum3[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case TWO:
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		   			           SSD_Au8CommonCathodeNum2[SSD_u8_A_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum2[SSD_u8_B_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum2[SSD_u8_C_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum2[SSD_u8_D_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum2[SSD_u8_E_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum2[SSD_u8_F_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		   	 				   SSD_Au8CommonCathodeNum2[SSD_u8_G_SEGMENT_VALUE]);

		   	Local_u8ErrorStatus = ERROR_OK;
		   break;

		  case ONE:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum1[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum1[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum1[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum1[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum1[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum1[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum1[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case ZERO:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonCathodeNum0[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum0[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum0[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum0[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum0[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum0[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonCathodeNum0[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;
		  }
	  }else if ((SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_TYPE])==SSD_u8_COMMON_ANODE){
		  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_EN_SEGMENT_PIN], SSD_u8_COMMON_ANODE_EN);

		  switch(Copy_u8Value){
		  case NINE:
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
					            SSD_Au8CommonAnodeNum9[SSD_u8_A_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
			  					SSD_Au8CommonAnodeNum9[SSD_u8_B_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
			  					SSD_Au8CommonAnodeNum9[SSD_u8_C_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
			  					SSD_Au8CommonAnodeNum9[SSD_u8_D_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
			  					SSD_Au8CommonAnodeNum9[SSD_u8_E_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
			  					SSD_Au8CommonAnodeNum9[SSD_u8_F_SEGMENT_VALUE]);
			  DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
			  					SSD_Au8CommonAnodeNum9[SSD_u8_G_SEGMENT_VALUE]);

			  Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case EIGHT:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum8[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum8[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum8[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum8[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum8[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum8[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum8[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case SEVEN:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum7[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum7[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum7[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum7[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum7[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum7[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum7[SSD_u8_G_SEGMENT_VALUE]);
		  break;

		  case SIX:
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		   			           SSD_Au8CommonAnodeNum6[SSD_u8_A_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum6[SSD_u8_B_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum6[SSD_u8_C_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum6[SSD_u8_D_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum6[SSD_u8_E_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum6[SSD_u8_F_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum6[SSD_u8_G_SEGMENT_VALUE]);

		   	Local_u8ErrorStatus = ERROR_OK;
		   break;

		  case FIVE:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum5[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum5[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum5[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum5[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum5[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum5[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum5[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case FOUR:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum4[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum4[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum4[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum4[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum4[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum4[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum4[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case THREE:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum3[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum3[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum3[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum3[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum3[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum3[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum3[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case TWO:
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		   			           SSD_Au8CommonAnodeNum2[SSD_u8_A_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum2[SSD_u8_B_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum2[SSD_u8_C_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum2[SSD_u8_D_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum2[SSD_u8_E_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum2[SSD_u8_F_SEGMENT_VALUE]);
		   	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		   	 				   SSD_Au8CommonAnodeNum2[SSD_u8_G_SEGMENT_VALUE]);

		   	Local_u8ErrorStatus = ERROR_OK;
		   break;

		  case ONE:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum1[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum1[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum1[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum1[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum1[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum1[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum1[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;

		  case ZERO:
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_A_SEGMENT_PIN],
		  			           SSD_Au8CommonAnodeNum0[SSD_u8_A_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_B_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum0[SSD_u8_B_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_C_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum0[SSD_u8_C_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_D_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum0[SSD_u8_D_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_E_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum0[SSD_u8_E_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_F_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum0[SSD_u8_F_SEGMENT_VALUE]);
		  	 DIO_u8SetPinValue(SSD_Au8SsdArray[Copy_u8SsdId][SSD_u8_G_SEGMENT_PIN],
		  	 				   SSD_Au8CommonAnodeNum0[SSD_u8_G_SEGMENT_VALUE]);

		  	Local_u8ErrorStatus = ERROR_OK;
		  break;
		  }
	  }else{
		  Local_u8ErrorStatus = ERROR_NOK;
	  }

	  if (Local_u8ErrorStatus == ERROR_OK){
		  SSD_u8_LastValue = Copy_u8Value;
	  }else{
		  SSD_u8_LastValue = ZERO;
	  }

	  return Local_u8ErrorStatus;
}
