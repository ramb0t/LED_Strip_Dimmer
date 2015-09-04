/*
 * pinDefines.h
 *
 *  Created on: 04 Apr 2015
 *      Author: RobThePyro
 */

#ifndef PINDEFINES_H_
#define PINDEFINES_H_



#define LED_DDR			DDRD
#define LED_PORT		PORTD
#define LED_S1			PD4
#define LED_S2			PD5
#define LED_OFF(led)	LED_PORT |= (1<<led)
#define LED_ON(led)		LED_PORT &= ~(1<<led)
#define LED_FLIP(led)	LED_PORT ^= (1<<led)



#endif /* PINDEFINES_H_ */
