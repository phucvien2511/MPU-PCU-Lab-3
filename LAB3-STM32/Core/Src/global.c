/*
 * global.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Phuc
 */

#include "global.h"

int cycleTimer() {
	return (1000*(htim2.Init.Prescaler+1)*(htim2.Init.Period+1))/8e6;
}
int status = INIT;

uint16_t BUTTON[NUM_BUTTONS] = {B1_Pin, B2_Pin, B3_Pin};
uint16_t LED[NUM_LEDS] = {R1_Pin, Y1_Pin, G1_Pin, R2_Pin, Y2_Pin, G2_Pin};
int led_buffer[NUM_7SEGS] = {8};
//Init time values at milliseconds
int TIME_RED = 8000;
int TIME_YELLOW = 2000;
int TIME_GREEN = 6000;
int TIME_7SEG = 245;
int TIME_BLINK = 250;
int tempValue = 1;

