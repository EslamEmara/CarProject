/*
 * car.c
 *
 * Created: 9/7/2021 1:53:21 PM
 *  Author: Farouk
 */ 

#include "Std_Types.h"
#include "Bit_Math.h"

#include "Button.h"
#include "Motor.h"

ST_MOTORconfig_t MOTOR_1_config = {PORTA,0,PORTB,3};
ST_MOTORconfig_t MOTOR_2_config = {PORTA,1,PORTD,7};

void car_init(void)
{
	/* init motor1 */
	Motor_init(	MOTOR_1_config );
	/* init motor2 */
	Motor_init(	MOTOR_2_config );
	
	/* init buttons */
	Button_init(PORTC,0); // button 1 (forward)
	Button_init(PORTC,1); // button 2 (backward)
	Button_init(PORTC,2); // button 3 (right)
	Button_init(PORTC,3); // button 4 (left)
}


void car_moveRight(uint8 speed)
{
	/* move the 2 motors right at the same desired speed */
	Motor_moveBackwards(MOTOR_1_config,speed);
	Motor_moveForward(MOTOR_2_config,speed);
}


void car_moveLeft(uint8 speed)
{
	/* move the 2 motors left at the same desired speed */
	Motor_moveForward(MOTOR_1_config,speed);
	Motor_moveBackwards(MOTOR_2_config,speed);
}
void car_moveForward(uint8 speed)
{
	/* move the 2 motors forward at the same desired speed */
	Motor_moveForward(MOTOR_1_config,speed);
	Motor_moveForward(MOTOR_2_config,speed);
}


void car_moveBackward(void)
{
	/* move the 2 motors backward at the same speed 30 */
	Motor_moveBackwards(MOTOR_1_config,30);
	Motor_moveBackwards(MOTOR_2_config,30);
}


void car_updateState(void)
{
	
	
}
