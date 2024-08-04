 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Motor.h
 *
 * Description: header file for the DC Motor
 *
 * Author: Amr Essam
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_



#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT_ID    PORTB_ID

#define DC_MOTOR_PIN1_ID	4

#define DC_MOTOR_PIN2_ID	5


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	STOP, CW, A_CW
}DcMotor_State;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize DC Motor.
 */
void DcMotor_Init(void);

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value, and Send the
 * required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_rotate(DcMotor_State state,uint8 speed);

#endif /*DC_Motor_H*/
