 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Amr Essam
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_



#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SELECTION_REGISTER ADMUX
#define STATUS_REGISTER	   ADCSRA
#define ADC_Data_Regiser   ADC
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE  2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/



typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_2,F_CPU_4=2,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver as it takes the refrence
 * voltage and prescaler as inputs
 */
void ADC_init(const ADC_ConfigType* Config_Ptr);

/*
 * Description :
 * Function responsible for reading the ADC driver result according to the
 * required channel.
 */
uint16 ADC_readChannel(uint8 channel);


#endif /*ADC_H_ */
