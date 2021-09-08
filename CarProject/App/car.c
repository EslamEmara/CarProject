/*
 * car.c
 *
 * Created: 9/7/2021 1:53:21 PM
 *  Author: Farouk
 */ 

#include "car.h"

ST_MOTORconfig_t MOTOR_1_config = {portA,0,portA,1,PWM1};
ST_MOTORconfig_t MOTOR_2_config = {portA,2,portA,3,PWM2};


void car_init(void)
{
	/* init motor1 */
	Motor_init(	MOTOR_1_config );
	/* init motor2 */
	Motor_init(	MOTOR_2_config );
	
	/* init buttons */
	Button_init(BUTTON_G); // button 1 (G -> speed and direction)
	Button_init(BUTTON_M); // button 2 (MOVE)
	Button_init(BUTTON_L); // button 3 (left)
	Button_init(BUTTON_R); // button 4 (right)
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
	static uint8 speed = 0;
	
	if (Button_read_one_press(BUTTON_G,PULLUP_RES) == HIGH){
		speed +=10;
		car_moveForward(speed);
	}

}
