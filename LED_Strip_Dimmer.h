/*
 * LED_Strip_Dimmer.h
 *
 *  Created on: 11 Aug 2015
 *      Author: RobThePyro
 */

#ifndef LED_STRIP_DIMMER_H_
#define LED_STRIP_DIMMER_H_

// Standard AVR includes
/*********************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <string.h>					// strcat etc
#include <stdio.h>
#include <stdlib.h>        			// itoa etc

// Project Specific
/*********************************************/
#include "../AVR_Lib/lib/UART/uart.h"
#include "Timer1.h"

#include "pinDefines.h"

#define 	UART_BAUD_RATE 	9600	// USART Baud Rate



#endif /* LED_STRIP_DIMMER_H_ */
