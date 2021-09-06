/*
 * Motor.c
 *
 * Created: 9/5/2021 3:40:07 PM
 *  Author: Eslam Emara
 */ 

#include "Motor.h"

/*
 *Function to initialize motor 
 *Inputs ST_MOTORconfig_t config (see Motor.h for definition)
 *ST_MOTORconfig_t Members:: {uint8_t DIR_PORT,uint8_t DIR_PIN,uint8_t PWM_PORT,uint8_t PWM_PIN}
 *direction pin is the pin connected to the direction pin in the motor driver.
 *PWM pin the pin connected to speed pin in the motor driver.
 *void return.
 *EXAMPLE:
 *  ST_MOTORconfig_t MOTOR_1_config = {PORTA,0,PORTB,3};
	Motor_init(	MOTOR_1_config );
 * Expected OUTPUT: Setting Pins of PWM and Direction as output.
					Initializing PWM.
 */

void Motor_init(ST_MOTORconfig_t config)
{
	pwm_init(NON_INVERTING_MODE,PRESCALAR);
	if (config.DIR_PIN <= 7 && config.PWM_PIN <=7)
	{
		DIO_SetPinDirection(config.DIR_PORT,config.DIR_PIN,OUT);
		DIO_SetPinDirection(config.PWM_PORT,config.PWM_PIN,OUT);
	}

	
}
/*
 *	Function to move the motor clockwise 
 *	Inputs ST_MOTORconfig_t motor ID config , uint8_t speed percentage from 0 to 100
 *	void return. 
 *	Expected output: Motor rotate clockwise if inputs are valid 
 */
void Motor_moveForward(ST_MOTORconfig_t config,uint8_t speed)
{
	DIO_SetPinValue(config.DIR_PORT,config.DIR_PIN,LOW);
	if (speed>=0 && speed <=100)
		pwm_SetSpeed(speed);
}

/*
 *	Function to move the motor anti-clockwise 
 *	Inputs ST_MOTORconfig_t motor ID config , uint8_t speed percentage from 0 to 100
 *	void return. 
 *	Expected output: Motor rotate anti-clockwise if inputs are valid 
 */

void Motor_moveBackwards(ST_MOTORconfig_t config,uint8_t speed)
{
	DIO_SetPinValue(config.DIR_PORT,config.DIR_PIN,HIGH);
	if (speed>=0 && speed <=100)
		pwm_SetSpeed(speed);
}