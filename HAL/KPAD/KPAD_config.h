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
#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define KPAD_PORT     PORTB

u8 KPAD_Au8Values[4][4] ={
                            {'7','8','9','/'}, //Row 0
                            {'4','5','6','x'}, //Row 1
                            {'1','2' ,'3','-'}, //Row 2
                            {'C','0','=','+'}  //Row 3
                            };


#define KPAD_ROW_INIT       PIN0
#define KPAD_ROW_END        PIN3

#define KPAD_COL_INIT       PIN4
#define KPAD_COL_END        PIN7


#define KPAD_R0             PIN0
#define KPAD_R1             PIN1       
#define KPAD_R2             PIN2
#define KPAD_R3             PIN3

#define KPAD_C0             PIN4
#define KPAD_C1             PIN5       
#define KPAD_C2             PIN6
#define KPAD_C3             PIN7

#define ROW0             PIN0
#define ROW1             PIN1       
#define ROW2             PIN2
#define ROW3             PIN3

#define COL0             PIN4
#define COL1             PIN5
#define COL2             PIN6
#define COL3             PIN7


#endif /* KPAD_CONFIG_H_ */


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
