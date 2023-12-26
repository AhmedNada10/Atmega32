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

/********************************************************* Include section ****************************************************/
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"

/*******************************************************************************************************************************/

/********************************************************* Functions implementations section ***********************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Direction){
    switch (Copy_u8Direction)
    {
    case INPUT: 
        switch (Copy_u8PortId)
        {
        case PORTA:
            clr_bit(DDRA_REG , Copy_u8PinId);
            break;
        case PORTB:
            clr_bit(DDRB_REG , Copy_u8PinId);
            break;
        case PORTC:
            clr_bit(DDRC_REG , Copy_u8PinId);
            break;
        case PORTD:
            clr_bit(DDRD_REG , Copy_u8PinId);
            break;
        
        default:
            break;
        } break;
    case OUTPUT: 
        switch (Copy_u8PortId)
        {
        case PORTA:
            set_bit(DDRA_REG , Copy_u8PinId);
            break;
        case PORTB:
            set_bit(DDRB_REG , Copy_u8PinId);
            break;
        case PORTC:
            set_bit(DDRC_REG , Copy_u8PinId);
            break;
        case PORTD:
            set_bit(DDRD_REG , Copy_u8PinId);
            break;
        
        default:
            
            break;
        }
        break;
    
    default:
        break;
    }
}

void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Value){
switch (Copy_u8Value)
    {
    case LOW: 
        switch (Copy_u8PortId)
        {
        case PORTA:
            clr_bit(PORTA_REG , Copy_u8PinId);
            break;
        case PORTB:
            clr_bit(PORTB_REG , Copy_u8PinId);
            break;
        case PORTC:
            clr_bit(PORTC_REG , Copy_u8PinId);
            break;
        case PORTD:
            clr_bit(PORTD_REG , Copy_u8PinId);
            break;
        
        default:
            break;
        } break;
    case HIGH: 
        switch (Copy_u8PortId)
        {
        case PORTA:
            set_bit(PORTA_REG , Copy_u8PinId);
            break;
        case PORTB:
            set_bit(PORTB_REG , Copy_u8PinId);
            break;
        case PORTC:
            set_bit(PORTC_REG , Copy_u8PinId);
            break;
        case PORTD:
            set_bit(PORTD_REG , Copy_u8PinId);
            break;
        
        default:
            
            break;
        }
        break;
    
    default:
        break;
    }
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId ){
    u8 Loc_u8ReturnValue;
    switch (Copy_u8PortId)
    {
    case PORTA:
        Loc_u8ReturnValue= get_bit(PINA_REG , Copy_u8PinId);
        break;
    case PORTB:
        Loc_u8ReturnValue= get_bit(PINB_REG , Copy_u8PinId);
        break;
    case PORTC:
        Loc_u8ReturnValue= get_bit(PINC_REG , Copy_u8PinId);
        break;
    case PORTD:
        Loc_u8ReturnValue= get_bit(PIND_REG , Copy_u8PinId);
        break;
    default:
        break;
    }
    return Loc_u8ReturnValue;
}
void DIO_voidToggelPin(u8 Copy_u8PortId , u8 Copy_u8PinId )
{
    switch (Copy_u8PortId)
    {
    case PORTA:
        if(get_bit(PORTA_REG , Copy_u8PinId)== LOW) set_bit(PORTA_REG , Copy_u8PinId);
        else clr_bit(PORTA_REG , Copy_u8PinId);
        break;
    case PORTB:
        if(get_bit(PORTB_REG , Copy_u8PinId)== LOW) set_bit(PORTB_REG , Copy_u8PinId);
        else clr_bit(PORTB_REG , Copy_u8PinId);
        break;
    case PORTC:
        if(get_bit(PORTC_REG , Copy_u8PinId)== LOW) set_bit(PORTC_REG , Copy_u8PinId);
        else clr_bit(PORTC_REG , Copy_u8PinId);
        break;
    case PORTD:
        if(get_bit(PORTD_REG , Copy_u8PinId)== LOW) set_bit(PORTD_REG , Copy_u8PinId);
        else clr_bit(PORTD_REG , Copy_u8PinId);
        break;
    
    default:
        break;
    }
}
void DIO_voidSetPinAsPullUp(u8 Copy_u8PortId , u8 Copy_u8PinId){
	DIO_voidSetPinDirection(Copy_u8PortId , Copy_u8PinId , INPUT);
	DIO_voidSetPinValue(Copy_u8PortId , Copy_u8PinId , HIGH);
}
void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction){
    switch (Copy_u8Direction)
    {
    case INPUT :
        switch (Copy_u8PortId)
        {
        case PORTA:
            DDRA_REG = 0;
            break;
        case PORTB:
            DDRB_REG = 0;
            break;
        case PORTC:
            DDRC_REG = 0;
            break;
        case PORTD:
            DDRD_REG = 0;
            break;
        
        default:
            break;
        }
        break;
    case OUTPUT :
        switch (Copy_u8PortId)
        {
        case PORTA:
            DDRA_REG = 255;
            break;
        case PORTB:
            DDRB_REG = 255;
            break;
        case PORTC:
            DDRC_REG = 255;
            break;
        case PORTD:
            DDRD_REG = 255;
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}
void DIO_voidSetPortValue(u8 Copy_u8PortId , u8 Copy_u8Value)
{
    switch (Copy_u8PortId)
    {
    case PORTA:
        DDRA_REG=255;
        PORTA_REG= Copy_u8Value;
        break;
    case PORTB:
        DDRB_REG=255;
        PORTB_REG= Copy_u8Value;
        break;
    case PORTD:
        DDRD_REG=255;
        PORTD_REG= Copy_u8Value;
        break;
    

    default:
        break;
    }
}
void DIO_voidToggelPort(u8 Copy_u8PortId ){
    switch (Copy_u8PortId)
    {
    case PORTA:
        for(int i=PIN0 ; i<=PIN7 ; i++){
            if(get_bit(PORTA_REG , i )== LOW) set_bit(PORTA_REG , i );
            else clr_bit(PORTA_REG , i );
        }
        break;
    case PORTB:
        for(int i=PIN0 ; i<=PIN7 ; i++){
            if(get_bit(PORTB_REG , i )== LOW) set_bit(PORTB_REG , i );
            else clr_bit(PORTB_REG , i );
        }
        break;
    case PORTC:
        for(int i=PIN0 ; i<=PIN7 ; i++){
            if(get_bit(PORTC_REG , i )== LOW) set_bit(PORTC_REG , i );
            else clr_bit(PORTC_REG , i );
        }
        break;
    case PORTD:
        for(int i=PIN0 ; i<=PIN7 ; i++){
            if(get_bit(PORTD_REG , i )== LOW) set_bit(PORTD_REG , i );
            else clr_bit(PORTD_REG , i );
        }
        break;
    
    default:
        break;
    }
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
