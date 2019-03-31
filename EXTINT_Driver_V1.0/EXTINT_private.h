/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 20 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : External Interrupts Private File */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef EXTINT_PRIVATE_H
#define EXTINT_PRIVATE_H
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : The addresses of external interrupts'*/
/*           registers                            */
#define EXTINT_u8_MCUCR   	 ((Register_8Bit*) 0x55)
#define EXTINT_u8_MCUCSR  	 ((Register_8Bit*) 0x54)
#define EXTINT_u8_GICR  	 ((Register_8Bit*) 0x5B)
#define EXTINT_u8_GIFR 		 ((Register_8Bit*) 0x5A)
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : The numbers corresponding to the     */
/*           interrupt's sense control bits in    */
/*           MCUCR and MCUCSR registers           */
/* Interrupt 1 sense control bits                 */
#define EXTINT_MCUCR_ISC11	 3
#define EXTINT_MCUCR_ISC10   2
/* Interrupt 0 sense control bits                 */
#define EXTINT_MCUCR_ISC01	 1
#define EXTINT_MCUCR_ISC00	 0
/* Interrupt 2 sense control bits                 */
#define EXTINT_MCUCSR_ISC2	 6
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : The numbers corresponding to the     */
/*           interrupt's state bits in the GICR   */
/*           register                             */
#define EXTINT_INT0_STATE_BIT		6
#define EXTINT_INT1_STATE_BIT		7
#define EXTINT_INT2_STATE_BIT		5
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Values written in the registers      */
#define EXTINT_ONE			 1
#define EXTINT_ZERO			 0
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Indexes of the pointers to function  */
/*           array                                */
#define EXTINT_u8_INT0_PTR				  (u8)0
#define EXTINT_u8_INT1_PTR				  (u8)1
#define EXTINT_u8_INT2_PTR				  (u8)2

#endif
