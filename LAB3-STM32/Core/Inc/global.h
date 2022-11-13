/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Phuc
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "display_func.h"
#include "button.h"
#include "software_timer.h"
#include "main.h"

#define NUM_7SEGS		4
#define NUM_BUTTONS 	3
#define NUM_LEDS		6
//Running automatically in mode 1
#define RG				10
#define RY				11
#define	GR				12
#define	YR				13
//4 modes of FSM
#define INIT			20
#define MODE1			21
#define MODE2			22
#define MODE3			23
#define MODE4			24
//Index for colors in traffic LED pin array
#define RED				3
#define YELLOW			4
#define GREEN			5
//Other variables
TIM_HandleTypeDef htim2;
int cycleTimer();			//Calculate timer interrupt period
extern int CYCLE;
void initSystem();			//Init all needed values for program
extern int status;			//Current state of FSM
extern int tempValue;		//Counter variable when you modify LED time
extern int TIME_RED;		//Red light time
extern int TIME_GREEN;		//Green light time
extern int TIME_YELLOW;		//Yellow light time
extern int TIME_7SEG;		//Scanning period for 7-seg LEDs
extern int TIME_BLINK;		//Blink period for traffic LEDs
extern int led_buffer[NUM_7SEGS];	//Buffer array for 7-seg LEDs
uint16_t BUTTON[NUM_BUTTONS];		//Pin of buttons
uint16_t LED[NUM_LEDS];				//Pin of traffic LEDs
#endif /* INC_GLOBAL_H_ */
