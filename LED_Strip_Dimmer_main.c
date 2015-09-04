/*
 * LED_Strip_Dimmer_main.c
 *
 *  Created on: 11 Aug 2015
 *      Author: RobThePyro
 */


#include "LED_Strip_Dimmer.h"


// Static Functions
/*********************************************/

// Sets up the IO...
static void	IOInit(void){
	/* Speed control setup */
	// PWM as output
	LED_DDR |= (1<<LED_S1)|(1<<LED_S2);
} // IOInit


int main(void)
{
	// Init Hardware
	IOInit();



	// Init Timer1 for PWM
	Timer1_init();

	Timer1_PWM_On();
	Timer1_Set_PWM_1A(0);
	Timer1_Set_PWM_1B(0);


	// Init UART
	uart_init( UART_BAUD_SELECT_DOUBLE_SPEED(UART_BAUD_RATE,F_CPU) );


	// Enable Interrupts
	sei();

	uart_puts("USART Initialised\n");

	// Loop for all the time ever!!! (Hopefully...)
    while(1) {
    	char buf[10]; // used for forming strings to pass to the display ??
    	char string[15];

    	if(uart_available() > 1){
    		uint8_t command_char = uart_getc();
    		uint8_t value = uart_getc();
    		if(command_char == 'a'){
    			Timer1_Set_PWM_1A(value);
    		}else if(command_char == 'b'){
    			Timer1_Set_PWM_1B(value);
    		}
    		uart_flush();
    		uart_puts("Cmd: ");
    		uart_putc(command_char);
    		uart_puts(" Val: ");
    		uart_putc(value);
    		uart_puts("\n");

    	}
    }

}// main
