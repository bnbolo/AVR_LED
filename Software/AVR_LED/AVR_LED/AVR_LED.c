/*
 * AVR_LED.c
 *
 * Created: 2013/3/27 22:27:48
 *  Author: Benjamin Chen
 */ 

#include "AVR_LED.h"

#include "ledsel.h"
#include "timer0.h"
#include "pwm.h"

void board_init(void);

int main(void)
{
	ushort i = 0;
	
	board_init();
	
    while(1)
    {
		ledsel(i);
		if(i++>19) i = 0;
		
        //TODO:: Please write your application code 
    }
}

void timer_cb(){
	volatile ushort j = 0;
	for(j=0; j<10; j++){}
}

void board_init(void)
{
	cli();
	
	
	// clock configuration
	// Programmable fuse could set system clock default to 16MHz
	
	
	// IO configuration
	ledsel_init();	
	
	// Timer configuration
	timer0_init(1);
	timer0_register_handle(timer_cb);
	timer0_start();
	
	
	// PWM configuration
	pwm_init();
	pwm_start();
	
	
	// interrupt cnofiguration
	
	
	
	// unused pin configuration
	
	
	
	sei();
}