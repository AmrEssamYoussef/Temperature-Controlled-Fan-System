/************************************************************************
 * Module: Timer0 PWM mode
 *
 * File Name: PWM.c
 *
 * Description: Source file for the ATmega32 Timer0 PWM mode driver
 *
 * Author: Amr Essam
 *
 *
 ***********************************************************************/

#include "PWM.h"
#include "gpio.h"
#include <avr/io.h>



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void PWM_Timer0_Start(uint8 duty_cycle)
{
	duty_cycle = (uint8)((((uint16)duty_cycle * MAX_ANALOG_OUTPUT)/MAX_SPEED));
	TCNT0 = 0;
	OCR0  = duty_cycle;
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID ,PIN_OUTPUT);
	CONTROL_REGISTER = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
