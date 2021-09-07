/*
 * Button.c
 *
 * Created: 9/3/2021 3:23:04 PM
 *  Author: Eslam Emara
 */

#include "Button.h"

/*
 *	Function to initialize to Button pin
 *	Inputs:  uint8 port,uint8 pin
 *	void return.
 *	Expected Output: PIN of the button is set as input.
 */
void Button_init(uint8 port,uint8 pin)
{
	if (pin <= 7)
		DIO_SetPinDirection(port,pin,0);
}

/*
 *	Function to read to Button state
 *	Inputs:  uint8 port,uint8 pin,EN_CONN_t conn (See Button.h for definition)
 *	conn options (PULLUP_RES) or (PULLDOWN_RES) according to your desired connection
 *	Return: 1 if the button is pressed 0 otherwise.
 *	=================PS:: FUNCTION MUST BE CALLED PERIDOCALLY TO AVOID DEBOUNCING EFFECTS======================
 * change DEBOUNCING TIME macro in Button.h according to your app.
 */
uint8 Button_read(uint8 port,uint8 pin,EN_CONN_t conn)
{
	uint8 current_state =  0;
	static uint8 last_state = 0;
	static uint16 counter = 0;
	static uint8 return_state = 0;

	if (conn == PULLDOWN_RES){
		current_state =DIO_GetPinValue(port,pin);
	}
	else{
		current_state =!DIO_GetPinValue(port,pin);
	}

	if (current_state == last_state){
		counter++;
	}

	if (counter > DEBOUNCTING_TIME)
	{
		counter = 0;
		return_state = current_state;
	}

	last_state = current_state;

	return return_state;


}
