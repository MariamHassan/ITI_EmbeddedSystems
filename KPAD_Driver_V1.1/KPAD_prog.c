/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Feb 2019                      */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : KPAd Program File                */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "KPAD_interface.h"
#include "KPAD_private.h"
#include "KPAD_config.h"


/* Comment : Arrays to hold pins of the rows and*/
/*           columns                            */
static const u8 KPAD_Au8Rows[KPAD_u8_NUM_ROWS]= {KPAD_u8_ID0_ROW1,
                                    KPAD_u8_ID0_ROW2,
                                    KPAD_u8_ID0_ROW3};

static const u8 KPAD_Au8Cols[KPAD_u8_NUM_COLS]= {KPAD_u8_ID0_COL1,
                                    KPAD_u8_ID0_COL2,
                                    KPAD_u8_ID0_COL3};

/* Get Pressed Keys                               */
/* Description       : Activate the columns and   */
/*                     then scan rows to detect   */ 
/*                     pressed keys and then store*/ 
/*                     them in an array           */
/* Input Argument(s) : 2D array sized rows x cols */
/* Return            : Error Status               */
u8 KPAD_u8GetKeysPressed(u8 Copy_u8KpadKeys[3][3])
{
/* Local variables declaration                    */
	u8 Local_u8ErrorStatus = ERROR_OK;
    
    u8 Local_u8RowValue;

    u8 Local_u8ColLoop;
    u8 Local_u8RowLoop;
    u8 Local_u8index;
    
    u8 Local_u8Loop1;
    u8 Local_u8Loop2;
    
/* Initialize the keys' states                    */
    for (Local_u8Loop1 = 0 ; Local_u8Loop1 <KPAD_u8_NUM_ROWS ; Local_u8Loop1++)
    {
      for (Local_u8Loop2 = 0 ; Local_u8Loop2 <KPAD_u8_NUM_COLS ; Local_u8Loop2++)
      {
        Copy_u8KpadKeys[Local_u8Loop1][Local_u8Loop2] = KPAD_u8_RELEASED;
      }
    }

/* Activate a column and scan rows for change     */                        
    if (KPAD_u8_Input_Connection == KPAD_u8_PULL_UP)
    {
      for (Local_u8ColLoop=0 ; Local_u8ColLoop<KPAD_u8_NUM_COLS ; Local_u8ColLoop++)
      {
        //Columns loop
        for (Local_u8index=0 ; Local_u8index<KPAD_u8_NUM_COLS ; Local_u8index++)
        {
          if (Local_u8ColLoop == Local_u8index)
          {
            DIO_u8SetPinValue((KPAD_Au8Cols[Local_u8index]),DIO_u8_PIN_LOW);
          }
          else
          {
            DIO_u8SetPinValue((KPAD_Au8Cols[Local_u8index]),DIO_u8_PIN_HIGH);
          }
        }
        //Rows loop
        for (Local_u8RowLoop=0 ; Local_u8RowLoop<KPAD_u8_NUM_ROWS ; Local_u8RowLoop++)
        {
          DIO_u8GetPinValue((KPAD_Au8Rows[Local_u8RowLoop]),&Local_u8RowValue);
          
          if (Local_u8RowValue == DIO_u8_PIN_LOW)
          {
            Copy_u8KpadKeys[Local_u8RowLoop][Local_u8ColLoop] = KPAD_u8_PRESSED;
          }
        }  
      }
    }
    else if (KPAD_u8_Input_Connection == KPAD_u8_PULL_DOWN)
    {
      for (Local_u8ColLoop=0 ; Local_u8ColLoop<KPAD_u8_NUM_COLS ; Local_u8ColLoop++)
      {
        //Columns loop
        for (Local_u8index=0 ; Local_u8index<KPAD_u8_NUM_COLS ; Local_u8index++)
        {
          if (Local_u8ColLoop == Local_u8index)
          {
            DIO_u8SetPinValue((KPAD_Au8Cols[Local_u8index]),DIO_u8_PIN_HIGH);
          }
          else
          {
            DIO_u8SetPinValue((KPAD_Au8Cols[Local_u8index]),DIO_u8_PIN_LOW);
          }
        }
        //Rows loop
        for (Local_u8RowLoop=0 ; Local_u8RowLoop<KPAD_u8_NUM_ROWS ; Local_u8RowLoop++)
        {
          DIO_u8GetPinValue((KPAD_Au8Rows[Local_u8RowLoop]),&Local_u8RowValue);
          
          if (Local_u8RowValue == DIO_u8_PIN_HIGH)
          {
            Copy_u8KpadKeys[Local_u8RowLoop][Local_u8ColLoop] = KPAD_u8_PRESSED;
          }
        }  
      }
    }
    else
    {
      Local_u8ErrorStatus = ERROR_NOK;
    }
     
    return Local_u8ErrorStatus;
}
