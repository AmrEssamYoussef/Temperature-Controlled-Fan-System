/************************************************************************
 * Module: Timer0 PWM mode
 *
 * File Name: PWM.h
 *
 * Description: Header file for the ATmega32 Timer0 PWM mode driver
 *
 * Author: Amr Essam
 *
 *
 ***********************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define MAX_ANALOG_OUTPUT  255

#define MAX_SPEED    100

#define CONTROL_REGISTER TCCR0


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* PWM_H_ */
