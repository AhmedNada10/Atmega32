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

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/********************************************************* MACROS section *******************************************************/
#define CLCD_4BIT_MODE     0
#define CLCD_8BIT_MODE     1
#define SEND_COMMAND       0x01

#define ROW0               0  
#define ROW1               1  
#define COULMN0            0
#define COULMN1            1
#define COULMN2            2
#define COULMN3            3
#define COULMN4            4
#define COULMN5            5
#define COULMN6            6
#define COULMN7            7
#define COULMN8            8
#define COULMN9            9
#define COULMN10            10
#define COULMN11            11
#define COULMN12            12
#define COULMN13            13
#define COULMN14            14
#define COULMN15            15

#define CGRAM_LOCATION0       64
#define CGRAM_LOCATION1       72
#define CGRAM_LOCATION2       80
#define CGRAM_LOCATION3       88
#define CGRAM_LOCATION4       96
#define CGRAM_LOCATION5       104
#define CGRAM_LOCATION6       112
#define CGRAM_LOCATION7       120
/*******************************************************************************************************************************/


/********************************************************* Global variables section **********************************************/

/*******************************************************************************************************************************/


/********************************************************* Function prototypes section ******************************************/
void CLCD_voidEnable(void);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSendString(u8* Copy_u8String);
void CLCD_voidSendNumber(u32 Copy_u32Number);
void CLCD_voidSetPostion(u8 Copy_u8Row , u8 Copy_u8Coulmn);    // options --> (ROW0 , ROW1) , (COULMN0 ..............COULMN15)
void CLCD_voidSendCustomChar(u8 Copy_u8CharArray[8] , u8 Copy_u8CGRAM_Location , u8 Copy_u8CLCD_ROW , u8 Copy_u8CLCD_Coulmn);  // options --> (CGRAM_LOCATION0 ........... CGRAM_LOCATION7)
/*******************************************************************************************************************************/






#endif /* CLCD_INTERFACE_H_ */



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
