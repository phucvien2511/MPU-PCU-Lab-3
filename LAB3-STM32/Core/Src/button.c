/*
 * button.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Phuc
 */


/*
 * button.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Phuc
 */


#include "button.h"
int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE};
int button_flag[NUM_BUTTONS] = {0};
int TimeOutForKeyPress[NUM_BUTTONS] = {0};

int isButtonPressed(int i) {
	if(button_flag[i] == 1) {
		button_flag[i] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int i) {
	button_flag[i] = 1;
}
void getKeyInput() {
	for (int i = 0; i < NUM_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON[i]);
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]) {		//Normal press
				  KeyReg3[i] = KeyReg2[i];
				  if (KeyReg2[i] == PRESSED_STATE) {
					  subKeyProcess(i);
					  TimeOutForKeyPress[i] = 2000/cycleTimer();	//Treat as long-press if you hold button in more than 2 seconds
				  }
			}
			else {	//Long press
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0)
					KeyReg3[i] = NORMAL_STATE;
			}
		}
	}
}
