/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 24 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : MCU Interface File               */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef MCU_INTERFACE_H
#define MCU_INTERFACE_H

/* Comment : API's prototypes                     */
/* Enable                                         */
/* Description       : Activate global interrupt  */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void MCU_voidEnableGlobalIntp(void);

/* Disable                                        */
/* Description       : Deactivate global interrupt*/
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void MCU_voidDisableGlobalIntp(void);

#endif
