/*
 * CarProject.c
 *
 * Created: 9/5/2021 12:29:52 PM
 * Author : EslamEmara
 */ 

#include "APP/car.h"


int main(void)
{
	/*ST_MOTORconfig_t motor1 = {portA,0,portA,1,PWM1};
	ST_MOTORconfig_t motor2 = {portA,2,portA,3,PWM2};
		
	Motor_init(motor1);
	Motor_init(motor2);
	*/
	car_init();
    /* Replace with your application code */
    while (1) 
    {
		car_updateState();

    }
}

