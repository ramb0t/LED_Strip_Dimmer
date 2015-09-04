/*
 * Timer1.c
 *
 *  Created on: 04 Apr 2015
 *      Author: RobThePyro
 */

#include "Timer1.h"

// Functions:
/*****************************************************************************/
void Timer1_init(void) {
	// Timer 1 A,B
	TCCR1A |= (1 << WGM10); /* Fast PWM mode, 8-bit */
	TCCR1B |= (1 << WGM12); /* Fast PWM mode, pt.2 */
	/* Prescaler settings:
	CS12	CS11	CS10	Descrip
	0		0		0		No Source (stopped)
	0		0		1		clk/1
	0		1		0		clk/8
	0		1		1		clk/64
	1		0		0		clk/256
	1		0		1		clk/1024
	1		1		0		etc clk fall edge on T1
	1		1		1		etc clk rise edge on T1
	*/
	TCCR1B |= (0<<CS12)|(1<<CS11)|(0<<CS10); /* PWM Freq = F_CPU/8/256 ~488Hz @ 1mhz clk */
	TCCR1A |= (1 << COM1A1); /* PWM output on OCR1A */
	TCCR1A |= (1 << COM1B1); /* PWM output on OCR1B */

}

void Timer1_PWM_Off(void){
	// Disconnect Clock!
	TCCR1B &= ~((1<<CS12)|(1<<CS11)|(1<<CS10));
}

void Timer1_PWM_On(void){
	// Connect Clock!
	TCCR1B |= (0<<CS12)|(1<<CS11)|(0<<CS10);
}

void Timer1_Set_PWM_1A(uint8_t PWM_Value){
	OCR1A = PWM_Value;
}

void Timer1_Set_PWM_1B(uint8_t PWM_Value){
	OCR1B = PWM_Value;
}
