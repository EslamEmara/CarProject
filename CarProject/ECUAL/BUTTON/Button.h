/*
 * Button.h
 *
 * Created: 9/3/2021 3:23:22 PM
 *  Author: 20109
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO_Config.h"

#define	 DEBOUNCTING_TIME	 200

typedef enum {
	PULLUP_RES,
	PULLDOWN_RES,
}EN_CONN_t;

void Button_init(uint8_t port,uint8_t pin);
uint8_t Button_read(uint8_t port,uint8_t pin,EN_CONN_t conn);

#endif /* BUTTON_H_ */
