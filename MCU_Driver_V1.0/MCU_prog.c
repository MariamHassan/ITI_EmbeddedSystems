/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 24 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : MCU Program File                 */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "MCU_config.h"
#include "MCU_interface.h"
#include "MCU_private.h"

/* Enable                                         */
/* Description       : Activate global interrupt  */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void MCU_voidEnableGlobalIntp(void)
{
	ASSIGN_BIT((MCU_u8_SREG->ByteAccess), (MCU_GIE), (MCU_GIE_ENABLE));
}

/* Disable                                        */
/* Description       : Deactivate global interrupt*/
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void MCU_voidDisableGlobalIntp(void)
{
	ASSIGN_BIT((MCU_u8_SREG->ByteAccess), (MCU_GIE), (MCU_GIE_DISABLE));
}
