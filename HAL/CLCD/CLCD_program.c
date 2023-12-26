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
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"
#include"CLCD_config.h"
#include"DIO_interface.h"
#include<util/delay.h>
/*******************************************************************************************************************************/

/********************************************************* Functions implementations section ***********************************/
void CLCD_voidInit(void){

    DIO_voidSetPinDirection(CLCD_CTR_PORT , RS_PIN , OUTPUT);
    DIO_voidSetPinDirection(CLCD_CTR_PORT , RW_PIN , OUTPUT);
    DIO_voidSetPinDirection(CLCD_CTR_PORT , E_PIN , OUTPUT);
    DIO_voidSetPortDirection(CLCD_DAT_PORT , OUTPUT);
    _delay_ms(1);
    CLCD_voidSendCommand(FUNCTION_SET);
    _delay_ms(1);

    CLCD_voidSendCommand(DISPLAY_ON_OFF);
    _delay_ms(1);
    CLCD_voidSendCommand(DISPLAY_CLR);
    _delay_ms(2);
    CLCD_voidSendCommand(ENTRY_MODE);
    _delay_ms(50);

}

void CLCD_voidEnable(void){
    DIO_voidSetPinDirection(CLCD_CTR_PORT , E_PIN , OUTPUT);
    DIO_voidSetPinValue(CLCD_CTR_PORT , E_PIN , HIGH);
    DIO_voidSetPinValue(CLCD_CTR_PORT , E_PIN , LOW);
    _delay_ms(3);
    DIO_voidSetPinValue(CLCD_CTR_PORT , E_PIN , HIGH);
}

void CLCD_voidSetPostion(u8 Copy_u8Row , u8 Copy_u8Coulmn){
	if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN0){
        CLCD_voidSendCommand(0x80);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN1){
        CLCD_voidSendCommand(0x81);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN2){
        CLCD_voidSendCommand(0x82);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN3){
        CLCD_voidSendCommand(0x83);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN4){
        CLCD_voidSendCommand(0x84);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN5){
        CLCD_voidSendCommand(0x80);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN0){
        CLCD_voidSendCommand(0x85);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN5){
        CLCD_voidSendCommand(0x85);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN6){
        CLCD_voidSendCommand(0x86);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN7){
        CLCD_voidSendCommand(0x87);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN8){
        CLCD_voidSendCommand(0x88);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN9){
        CLCD_voidSendCommand(0x89);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN10){
        CLCD_voidSendCommand(0x8A);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN11){
        CLCD_voidSendCommand(0x8B);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN12){
        CLCD_voidSendCommand(0x8C);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN13){
        CLCD_voidSendCommand(0x8D);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN14){
        CLCD_voidSendCommand(0x8E);
    }
	else if(Copy_u8Row==ROW0 && Copy_u8Coulmn==COULMN15){
        CLCD_voidSendCommand(0x8F);
    }
	
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN0){
        CLCD_voidSendCommand(0xC0);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN1){
        CLCD_voidSendCommand(0xC1);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN2){
        CLCD_voidSendCommand(0xC2);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN3){
        CLCD_voidSendCommand(0xC3);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN4){
        CLCD_voidSendCommand(0xC4);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN5){
        CLCD_voidSendCommand(0xC0);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN0){
        CLCD_voidSendCommand(0xC5);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN5){
        CLCD_voidSendCommand(0xC5);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN6){
        CLCD_voidSendCommand(0xC6);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN7){
        CLCD_voidSendCommand(0xC7);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN8){
        CLCD_voidSendCommand(0xC8);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN9){
        CLCD_voidSendCommand(0xC9);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN10){
        CLCD_voidSendCommand(0xCA);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN11){
        CLCD_voidSendCommand(0xCB);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN12){
        CLCD_voidSendCommand(0xCC);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN13){
        CLCD_voidSendCommand(0xCD);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN14){
        CLCD_voidSendCommand(0xCE);
    }
	else if(Copy_u8Row==ROW1 && Copy_u8Coulmn==COULMN15){
        CLCD_voidSendCommand(0xCF);
    }
}

void CLCD_voidSendCommand(u8 Copy_u8Command){


    DIO_voidSetPinValue(CLCD_CTR_PORT , RS_PIN , LOW);
    DIO_voidSetPinValue(CLCD_CTR_PORT , RW_PIN , LOW);
    DIO_voidSetPinValue(CLCD_CTR_PORT , E_PIN , HIGH);          // ensure the enble is deactivated
    DIO_voidSetPortValue(CLCD_DAT_PORT , Copy_u8Command);
    CLCD_voidEnable();
    _delay_ms(10);
}

void CLCD_voidSendData(u8 Copy_u8Data){
    DIO_voidSetPinValue(CLCD_CTR_PORT , RS_PIN , HIGH);
    DIO_voidSetPinValue(CLCD_CTR_PORT , RW_PIN , LOW);
    DIO_voidSetPortValue(CLCD_DAT_PORT , Copy_u8Data);
    CLCD_voidEnable();
    _delay_ms(10);
}


void CLCD_voidSendString(u8* Copy_u8String){
    u8 * Loc_ptr = Copy_u8String;
    u8 Loc_iterator=0;
    while (Loc_ptr[Loc_iterator] != '\0')
    {
        CLCD_voidSendData(Loc_ptr[Loc_iterator]);
        Loc_iterator++;
    }
    
}

void CLCD_voidSendNumber(u32 Copy_u32Number){
    u32 Loc_Reversed=1;
    u32 loc_Copy = Copy_u32Number;
    while(loc_Copy != 0){
        Loc_Reversed = (Loc_Reversed * 10) + (loc_Copy %10);
        loc_Copy /= 10;
    }
    while (Loc_Reversed != 1)
    {
        CLCD_voidSendData((Loc_Reversed % 10) + '0');
        Loc_Reversed /=10;
    }
    if(Copy_u32Number == 0)
    {
    	CLCD_voidSendData('0');
    }
    
}

void CLCD_voidSendCustomChar(u8 Copy_u8CharArray[8], u8 Copy_u8CGRAM_Location, u8 Copy_u8CLCD_ROW, u8 Copy_u8CLCD_Coulmn)
{
    /*Variable to put the ddram location into*/
	u8 loc_DDRAM_Location;
    /*go to CGRAM Location*/
    u8 loc_iterator = 0;
    CLCD_voidSendCommand(Copy_u8CGRAM_Location);
    while (loc_iterator < 8)
    {
        CLCD_voidSendData(Copy_u8CharArray[loc_iterator]);
        loc_iterator++;
    }
    CLCD_voidSetPostion(Copy_u8CLCD_ROW, Copy_u8CLCD_Coulmn);

	for(u8 i=0; i<8; i++)
	{
		if(Copy_u8CGRAM_Location == CGRAM_LOCATION0 + (i*8))
		{
			loc_DDRAM_Location = i;
			break;
		}
	}
/*******************************************************************************************************************************/




/********************************************************************************************************************************/




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


