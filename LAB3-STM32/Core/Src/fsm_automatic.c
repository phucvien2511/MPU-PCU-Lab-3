/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Phuc
 */


#include "fsm_automatic.h"


void fsm_automatic_run() {
	switch (status) {
	case INIT:
		status = RG;
		setStateForLEDs(1,1,1,1,1,1);	//Turn off all traffic LEDs
		HAL_GPIO_WritePin(GPIOB, S0_Pin | S1_Pin | S2_Pin |		//Turn off all 7SEG LEDs
				 	 S3_Pin | S4_Pin | S5_Pin | S6_Pin, SET);
		setTimer1(TIME_RED);	//1st timer is used for set time value of 1st route
		setTimer2(TIME_GREEN);	//2nd timer is used for set time value of 2nd route
		setTimer3(TIME_7SEG);	//3rd timer is used for 7-segment LEDs scanning
		setTimer4(TIME_BLINK);	//4th timer is used for LED blinking
		break;
	case RG:
		update7SEG();
		setStateForLEDs(0,1,1,1,1,0);
		if (timer2_flag == 1) {
			status = RY;
			setTimer2(TIME_YELLOW);
		}
		if (isButtonPressed(0) == 1) {	//When button 1 is pressed, stop auto mode and
			status = MODE2;				//change to modify TIME_RED mode
			tempValue = 1;
			setStateForLEDs(1,1,1,1,1,1);	//Turn off all LEDs
		}
		break;
	case RY:
		update7SEG();
		setStateForLEDs(0,1,1,1,0,1);
		if (timer2_flag == 1 || timer1_flag == 1) {
			status = GR;
			setTimer1(TIME_GREEN);
			setTimer2(TIME_RED);
		}
		if (isButtonPressed(0) == 1) {
			status = MODE2;
			tempValue = 1;
			setStateForLEDs(1,1,1,1,1,1);	//Turn off all LEDs
		}
		break;
	case GR:
		update7SEG();
		setStateForLEDs(1,1,0,0,1,1);
		if (timer1_flag == 1) {
			status = YR;
			setTimer1(TIME_YELLOW);
		}
		if (isButtonPressed(0) == 1) {
			status = MODE2;
			tempValue = 1;
			setStateForLEDs(1,1,1,1,1,1);	//Turn off all LEDs
		}
		break;
	case YR:
		update7SEG();
		setStateForLEDs(1,0,1,0,1,1);
		if (timer2_flag == 1 || timer1_flag == 1) {
			status = RG;
			setTimer1(TIME_RED);
			setTimer2(TIME_GREEN);
		}
		if (isButtonPressed(0) == 1) {
			status = MODE2;
			tempValue = 1;
			setStateForLEDs(1,1,1,1,1,1);	//Turn off all LEDs
		}
	default:
		break;
	}

}

