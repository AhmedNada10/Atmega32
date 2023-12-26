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

#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"

/********************************************************* MACROS section *******************************************************/

/*******************************************************************************************************************************/

/********************************************************* Global variables section **********************************************/
u16 *data;
/*******************************************************************************************************************************/

/********************************************************* Function implementation section ******************************************/
/*                                                          ADMUX FUNCTIONS                                */
/*voltage reference (pin7 , pin6)*/
AdcErrorStatus ADC_AdcErrorStatusSetVoltageRefrance()
{
    AdcErrorStatus loc_return = ADC_NOK;
#if ADC_VoltageReferance == External_AREF
    clr_bit(ADMUX_REG, PIN7);
    clr_bit(ADMUX_REG, PIN6);
#elif ADC_VoltageReferance == Internal_AVCC
    clr_bit(ADMUX_REG, PIN7);
    set_bit(ADMUX_REG, PIN6);
#elif ADC_VoltageReferance == Internal_2_56
    set_bit(ADMUX_REG, PIN7);
    set_bit(ADMUX_REG, PIN6);
#endif
    loc_return = ADC_OK;
    return loc_return;
}
/* set data registers selection (PIN5)*/
AdcErrorStatus ADC_AdcErrorStatusDataRegDirection()
{
    AdcErrorStatus loc_return = ADC_NOK;
#if ADC_DataDirection == Left
    set_bit(ADMUX_REG, PIN5);
#elif ADC_DataDirection == Right
    clr_bit(ADMUX_REG, PIN5);
#endif
    loc_return = ADC_OK;
    return loc_return;
}
/*select channel (PIN4 : PIN0)*/
AdcErrorStatus ADC_AdcErrorStatusChannelSelection()
{
    AdcErrorStatus loc_return = ADC_NOK;
    ADMUX_REG |= ADC_ChannelSelection;
    loc_return = ADC_OK;
    return loc_return;
}

/*                                                            ADCSRA FUNCTIONS                                 */
/*ADC Enable (PIN7)*/
AdcErrorStatus ADC_AdcErrorStatusEnable()
{
    AdcErrorStatus loc_return = ADC_NOK;
    set_bit(ADCSRA_REG, PIN7);
    loc_return = ADC_OK;
    return loc_return;
}
/* ADC start conversion (PIN6)*/
AdcErrorStatus ADC_AdcErrorStatusStartConversion()
{
    AdcErrorStatus loc_return = ADC_NOK;
    set_bit(ADCSRA_REG, PIN6);
    loc_return = ADC_OK;
    return loc_return;
}
/*ADC auto trigger enable (PIN5)*/
AdcErrorStatus ADC_AdcErrorStatusAutoTriggerEnable()
{
    AdcErrorStatus loc_return = ADC_NOK;
    set_bit(ADCSRA_REG, PIN5);
    loc_return = ADC_OK;
    return loc_return;
}
/* ADC clear Interrupt flag (PIN4)*/
AdcErrorStatus ADC_AdcErrorStatusClearInterruptflag()
{
    AdcErrorStatus loc_return = ADC_NOK;
    set_bit(ADCSRA_REG, PIN4);
    loc_return = ADC_OK;
    return loc_return;
}
/* ADC Interrupt enable (PIN3)*/
AdcErrorStatus ADC_AdcErrorStatusInterruptEnable()
{
    AdcErrorStatus loc_return = ADC_NOK;
    set_bit(ADCSRA_REG, PIN3);
    loc_return = ADC_OK;
    return loc_return;
}
/*ADC prescaller*/
AdcErrorStatus ADC_AdcErrorStatusPrescaller()
{
    AdcErrorStatus loc_return = ADC_NOK;
    ADCSRA_REG |= ADC_prescaller;
    loc_return = ADC_OK;
    return loc_return;
}

/*                                                             SFIOR function                                 */

/*select trigger source*/
AdcErrorStatus ADC_AdcErrorStatusAutoTriggerSource()
{
    AdcErrorStatus loc_return = ADC_NOK;
    SFIO_REG |= ADC_AutoTriggerSource << 5;
    loc_return = ADC_OK;
    return loc_return;
}

/*                                                             main functions                           */
AdcErrorStatus ADC_AdcErrorStatusInit()
{
    AdcErrorStatus loc_return = ADC_NOK;

    ADC_AdcErrorStatusSetVoltageRefrance();
    ADC_AdcErrorStatusDataRegDirection();
    ADC_AdcErrorStatusChannelSelection();

    ADC_AdcErrorStatusEnable();
    ADC_AdcErrorStatusClearInterruptflag();
    ADC_AdcErrorStatusPrescaller();
    loc_return = ADC_OK;
    return loc_return;
}

u16 ADC_u16ConvertedValue(void)
{

    /*Declare Variable to get the converted value */
    u16 *Local_u16Value, x;
    /*Make Sure the Flag is cleared */
    ADC_AdcErrorStatusClearInterruptflag();
    /*Start Conversion*/
    ADC_AdcErrorStatusStartConversion();
    /* Wait until flag rasied , circuit finished the conversion  */
    while (get_bit(ADCSRA_REG, 4) == 0)
        ;
    /* Read the value  */
    x = ADCL_REG | ADCH_REG << 8;
    Local_u16Value = &x;
    /*Return the declared variable*/
    return Local_u16Value;
}

AdcErrorStatus ADC_AdcErrorStatusGetAdcData(u16 *Copy_u16Value)
{
    AdcErrorStatus loc_return = ADC_NOK;
    ADC_AdcErrorStatusClearInterruptflag();
    ADC_AdcErrorStatusStartConversion();
    while (get_bit(ADCSRA_REG, PIN4) == 0)
        ;
    *Copy_u16Value = ADCL_REG | ADCH_REG << 8;
    loc_return = ADC_OK;
    return loc_return;
}

/*******************************************************************************************************************************/

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
