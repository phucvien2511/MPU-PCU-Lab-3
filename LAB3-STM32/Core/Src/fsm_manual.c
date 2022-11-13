/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Phuc
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status) {
	case MODE2:
			update7SEG();
			blinkLED(RED);
	  //1st button pressed, switch to modify yellow mode
			if (isButtonPressed(0) == 1) {
				status = MODE3;
				tempValue = 1;
				setStateForLEDs(1,1,1,1,1,1);	//Turn off all LEDs
			}
	  //2nd button pressed, increase current value by 1 (back to 0 if bigger than 99)
			if (isButtonPressed(1) == 1) {
				tempValue = tempValue + 1;
				if (tempValue == 100)
					tempValue = 1;
			}
	  //3rd button pressed, save the value to red time
			if (isButtonPressed(2) == 1) {
				TIME_RED = tempValue*1000;
			}
			break;
	case MODE3:
		update7SEG();
		blinkLED(YELLOW);
		if (isButtonPressed(0) == 1) {
			status = MODE4;
			tempValue = 1;
			setStateForLEDs(1,1,1,1,1,1);	//Turn off all LEDs
		}
		if (isButtonPressed(1) == 1) {
			tempValue = tempValue + 1;
			if (tempValue == 100)
				tempValue = 1;
		}
		if (isButtonPressed(2) == 1) {
			TIME_YELLOW = tempValue * 1000;
		}
		break;
	case MODE4:
		update7SEG();
		blinkLED(GREEN);
		if (isButtonPressed(0) == 1) {
			status = INIT;	//Back to INIT mode to start again with new time values
			tempValue = 1;
		}
		if (isButtonPressed(1) == 1) {
			tempValue = tempValue + 1;
			if (tempValue == 100)
				tempValue = 1;
		}
		if (isButtonPressed(2) == 1) {
			TIME_GREEN = tempValue * 1000;
		}
	default:
		break;
	}
}

