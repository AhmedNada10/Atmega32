/********************************************************* Documentation ****************************************************
**
*******************************************************************************************************************************
*		File:
*		Author:  Ahmed Nada
*		Data:
*		description:-
********************************************************************************************************************************
**
*/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/********************************************************* MACROS section *******************************************************/
/*Port Name*/
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3
/*Pins name*/
#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
/*Direction Status*/
#define INPUT   0
#define OUTPUT  1
/*PIN Status*/
#define LOW  0
#define HIGH 1
/*******************************************************************************************************************************/

/********************************************************* Global variables section **********************************************/

/*******************************************************************************************************************************/

/********************************************************* Function prototypes section ******************************************/
/*Pin Functions*/
void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction);  // Direction Options --> 1:INPUT , 2:OUTPUT
void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value);          // Value Options --> 1:LOW  , 2:HIGH
u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId );
void DIO_voidToggelPin(u8 Copy_u8PortId , u8 Copy_u8PinId );
void DIO_voidSetPinAsPullUp(u8 Copy_u8PortId , u8 Copy_u8PinId);
/*Port functions*/
void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction);       // Direction Options --> 1:INPUT , 2:OUTPUT
void DIO_voidSetPortValue(u8 Copy_u8PortId , u8 Copy_u8Value);               // Value Options --> 1:LOW  , 2:HIGH
void DIO_voidToggelPort(u8 Copy_u8PortId );
/*******************************************************************************************************************************/

#endif /* DIO_INTERFACE_H_ */


/********************************************************* History Log ****************************************************
**
*******************************************************************************************************************************
*	User 							Date								Brief
*****************************************************************************************
*
*
*
*********************************************************************************************************************************
**
*/
