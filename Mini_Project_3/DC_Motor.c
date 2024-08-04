/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Motor.c
 *
 * Description: Source file for the DC Motor
 *
 * Author: Amr Essam
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "DC_Motor.h"
#include "common_macros.h"
#include "PWM.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID ,PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1_ID , LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN2_ID , LOGIC_LOW);
}

void DcMotor_rotate(DcMotor_State state,uint8 speed)
{
	 PWM_Timer0_Start(speed);


	 switch (state)
	 {
	 case STOP:
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1_ID , LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN2_ID , LOGIC_LOW);
	 break;
	 case CW:
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1_ID , LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN2_ID , LOGIC_LOW);
	 break;
	 case A_CW:
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1_ID , LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN2_ID , LOGIC_HIGH);
	 break;
	 }


}
