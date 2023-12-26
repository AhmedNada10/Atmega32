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

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Voltage Reference Selection*/
// Choices
#define External_AREF 0
#define Internal_AVCC 1 // with capacitor at AREF pin
#define Internal_2_56 2 // with capacitor at AREF pin
//! set the reference voltage
#define ADC_VoltageReferance Internal_AVCC

/*data registers direction*/
// Choices
#define Left 0
#define Right 1
//! set data register direction
#define ADC_DataDirection Right

/*Channel selection*/
//! based on the table provided at data sheet (page 215) put the channel values in bianry representation and complete the rest bits with zeros
#define ADC_ChannelSelection 0b00000000 // channel zero with gain 10x

/*ADC prescaller */
//! based on the table provided at data sheet (page 217) put the prescaller values in bianry representation and complete the rest bits with zeros
#define ADC_prescaller 0b00000011

/*select the auto trigger source*/
#define FreeRun 0
#define AnalogComparitor 1
#define ExtInterrupt 2
#define Timer0CompareMatch 3
#define Timer0CompareOverFlow 4
#define Timer1CompareMatch 5
#define Timer1CompareOverFlow 6
#define Timer1CaputureEvent 7
//! Selection
#define ADC_AutoTriggerSource FreeRun
/***************************************************ADMUX FUNCTIONS***************************************/
AdcErrorStatus ADC_AdcErrorStatusSetVoltageRefrance();
AdcErrorStatus ADC_AdcErrorStatusDataRegDirection();
AdcErrorStatus ADC_AdcErrorStatusChannelSelection();

/**************************************************ADCSRA FUNCTIONS***************************************/
AdcErrorStatus ADC_AdcErrorStatusPrescaller();
    /**************************************************SFIOR Functions****************************************/
    AdcErrorStatus ADC_AdcErrorStatusAutoTriggerSource();

#endif /* ADC_CONFIG_H_ */

/********************************************************* History Log ****************************************************
**
*******************************************************************************************************************************
*	User 							Date								Brief
*****************************************************************************************
*	Ahmed						21/11/2023							creating the drive
*
*
*********************************************************************************************************************************
**
*/
