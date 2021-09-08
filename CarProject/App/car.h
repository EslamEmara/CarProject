/*
 * car.h
 *
 * Created: 9/7/2021 1:53:51 PM
 *  Author: Farouk
 */ 


#ifndef CAR_H_
#define CAR_H_

#include "..\MCAL\DIO\Std_Types.h"
#include "..\MCAL\DIO\Bit_Math.h"

#include "..\ECUAL\BUTTON\Button.h"
#include "..\ECUAL\Motor\Motor.h"

// button config

#define BUTTON_G	portC,0
#define BUTTON_M	portC,1
#define BUTTON_L	portC,2
#define BUTTON_R	portC,3



/*******
	Function Description: Init the 2 motors and the 4 button to be ready for work
	parameter: none
	return: none
*/
void car_init(void);


/*******
	Function Description: move car to right by moving one motor forward and the other backward
	parameter: uint8 speed (0,30,60,90)
	return: none
*/
void car_moveRight(uint8 speed);

/*******
	Function Description: move car to right by moving one motor forward and the other backward
	parameter: uint8 speed (0,30,60,90)
	return: none
*/
void car_moveLeft(uint8 speed);

/*******
	Function Description: move car to right by moving one motor forward and the other backward
	parameter: uint8 speed (30,60,90)
	return: none
*/
void car_moveForward(uint8 speed);


/*******
	Function Description: move car backward by moving the 2 motors backward
	parameter: none (speed must be 30 only according to specs)
	return: none
*/
void car_moveBackward(void);

/* OMAR */
void car_updateState(void);



#endif /* CAR_H_ */