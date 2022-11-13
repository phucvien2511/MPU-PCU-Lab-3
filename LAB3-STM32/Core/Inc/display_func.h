/*
 * manage_func.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Phuc
 */

#ifndef INC_DISPLAY_FUNC_H_
#define INC_DISPLAY_FUNC_H_

#include "global.h"

void setStateForLEDs(int s1, int s2, int s3, int s4, int s5, int s6);
void blinkLED(int color);
void display7SEG(int index);
void setBuffer7SEG(int b1, int b2, int b3, int b4);
void update7SEG();
#endif /* INC_DISPLAY_FUNC_H_ */
