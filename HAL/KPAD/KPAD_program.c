/********************************************************* Documentation ****************************************************
**
*******************************************************************************************************************************
*		File:
*		Author:  Ahmed Nada
*		Date:
*		description:-
********************************************************************************************************************************
**
*/


/********************************************************* Include section ****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KPAD_config.h"
#include "KPAD_interface.h"
#include<util\delay.h>
/*******************************************************************************************************************************/

/********************************************************* Functions implementations section ***********************************/
void KPAD_voidInit(void){
	/*set rows as pull up*/
	DIO_voidSetPinAsPullUp(KPAD_PORT , ROW0);
	DIO_voidSetPinAsPullUp(KPAD_PORT , ROW1);
	DIO_voidSetPinAsPullUp(KPAD_PORT , ROW2);
	DIO_voidSetPinAsPullUp(KPAD_PORT , ROW3);
	/*set coulmn as output high*/
	DIO_voidSetPinDirection(KPAD_PORT , COL0 , OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT , COL1 , OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT , COL2 , OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT , COL3 , OUTPUT);
	DIO_voidSetPinValue(KPAD_PORT , COL0 , HIGH);
	DIO_voidSetPinValue(KPAD_PORT , COL1 , HIGH);
	DIO_voidSetPinValue(KPAD_PORT , COL2 , HIGH);
	DIO_voidSetPinValue(KPAD_PORT , COL3 , HIGH);
}

u8 KPAD_u8GetPressed    (void)  
{
    u8 Local_u8RetrunedValue = 255 ;
    u8 Local_u8GetPressed   ;
    u8 Local_u8Col            ;
    u8 Local_u8Row          ;

    for(Local_u8Col = 0 + KPAD_COL_INIT ; Local_u8Col < KPAD_COL_END + 1 ; Local_u8Col++ )
    {
        DIO_voidSetPinValue(KPAD_PORT , Local_u8Col , LOW);
        for(Local_u8Row = 0 + KPAD_ROW_INIT ; Local_u8Row < KPAD_ROW_END + 1 ; Local_u8Row++)
        {

           Local_u8GetPressed = DIO_u8GetPinValue(KPAD_PORT , Local_u8Row);
           if(Local_u8GetPressed == 0)
           {
            /*  Debouncing */
            _delay_ms(50);
            Local_u8GetPressed = DIO_u8GetPinValue(KPAD_PORT , Local_u8Row);
            if(Local_u8GetPressed == 0)
            {
                Local_u8RetrunedValue = KPAD_Au8Values[Local_u8Row - KPAD_ROW_INIT][Local_u8Col - KPAD_COL_INIT];
            }
            while(Local_u8GetPressed ==0 )
            {
                Local_u8GetPressed = DIO_u8GetPinValue(KPAD_PORT , Local_u8Row);

            }

           }

        }

        DIO_voidSetPinValue(KPAD_PORT , Local_u8Col , HIGH);
    }    


    return Local_u8RetrunedValue ;
}
/*******************************************************************************************************************************/






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
