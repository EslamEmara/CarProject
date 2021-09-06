/*
 * Motor.h
 *
 * Created: 9/5/2021 3:40:22 PM
 *  Author: Eslam Emara
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_


#include "DIO_Config.h"
#include "pwm.h"

#define		PRESCALAR	1024

#define		LOW			0
#define		HIGH		1

typedef struct motor {
	uint8_t DIR_PORT;
	uint8_t DIR_PIN;
	uint8_t PWM_PORT;
	uint8_t PWM_PIN;
	}ST_MOTORconfig_t;

void Motor_init(ST_MOTORconfig_t config);
void Motor_moveForward(ST_MOTORconfig_t config,uint8_t speed);
void Motor_moveBackwards(ST_MOTORconfig_t config,uint8_t speed);


#endif /* MOTOR_H_ */