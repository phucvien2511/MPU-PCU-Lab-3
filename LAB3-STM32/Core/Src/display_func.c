/*
 * manage_func.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Phuc
 */

#include <display_func.h>

int led_index = 0;
void setStateForLEDs(int s1, int s2, int s3, int s4, int s5, int s6) {	//Setup on/off sequences for traffic LEDs
	HAL_GPIO_WritePin(GPIOA, LED[0], s1);
	HAL_GPIO_WritePin(GPIOA, LED[1], s2);
	HAL_GPIO_WritePin(GPIOA, LED[2], s3);
	HAL_GPIO_WritePin(GPIOA, LED[3], s4);
	HAL_GPIO_WritePin(GPIOA, LED[4], s5);
	HAL_GPIO_WritePin(GPIOA, LED[5], s6);
}
void display7SEG(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}
void setBuffer7SEG(int b1, int b2, int b3, int b4) {
	led_buffer[0] = b1;
	led_buffer[1] = b2;
	led_buffer[2] = b3;
	led_buffer[3] = b4;
}
void update7SEG(){
	if (status == RG || status == RY || status == GR || status == YR) {
		//Divide for time cycle to get time value in second
		int scaleTimer1 = timer1_counter/100, scaleTimer2 = timer2_counter/100;
		setBuffer7SEG(scaleTimer1 / 10, scaleTimer1 % 10, scaleTimer2 / 10, scaleTimer2 % 10);
	}
	else if (status == MODE2) {
		setBuffer7SEG(tempValue / 10, tempValue % 10, 0, 2);
	}
	else if (status == MODE3) {
		setBuffer7SEG(tempValue / 10, tempValue % 10, 0, 3);
	}
	else if (status == MODE4) {
		setBuffer7SEG(tempValue / 10, tempValue % 10, 0, 4);
	}
	if (timer3_flag == 1) {
			switch (led_index) {
			case 0:	//Display 1st 7SEG LED
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
				display7SEG(led_buffer[0]);
				led_index = 1;
				break;
			case 1: //Display 2nd 7SEG LED
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
				display7SEG(led_buffer[1]);
				led_index = 2;
				break;
			case 2:
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
				display7SEG(led_buffer[2]);
				led_index = 3;
				break;
			case 3:
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
				display7SEG(led_buffer[3]);
				led_index = 0;
				break;
			default:
				break;
			}
			setTimer3(TIME_7SEG);
	}
}


void blinkLED(int color) {

	if (timer4_flag == 1) {
		HAL_GPIO_TogglePin(GPIOA, LED[color]);
		HAL_GPIO_TogglePin(GPIOA, LED[color%3]);
		setTimer4(250);
	}
}
