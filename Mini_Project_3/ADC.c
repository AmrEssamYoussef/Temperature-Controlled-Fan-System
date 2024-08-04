/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Amr Essam
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "ADC.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType* Config_Ptr)
{
	SET_BIT(ADCSRA,ADEN);
	SELECTION_REGISTER = (SELECTION_REGISTER & 0x3F) | ((Config_Ptr->ref_volt)<<6);
	STATUS_REGISTER = (STATUS_REGISTER & ~(0x07)) | (Config_Ptr->prescaler);

}


uint16 ADC_readChannel(uint8 channel)
{
	SELECTION_REGISTER = (SELECTION_REGISTER & ~(0X07)) |(channel);
	SET_BIT(STATUS_REGISTER,ADSC);
	while(BIT_IS_CLEAR(STATUS_REGISTER,ADIF));
	SET_BIT(STATUS_REGISTER,ADIF);
	return ADC_Data_Regiser;
}
