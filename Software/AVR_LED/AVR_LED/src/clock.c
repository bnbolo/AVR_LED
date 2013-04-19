/*
 * clock.c
 *
 * Created: 2013/4/2 11:46:21
 *  Author: Benjamin Chen
 */ 
#include <avr/io.h>

#include "AVR_LED.h"
#include "clock.h"

#define COUNT_PER_US_16MHZ 16 // (16000000/1000000)
#define COUNT_PER_US_8MHZ 8  // (8000000/1000000)

// switch to 16MHz
void AVR_LED_pllconfig()
{
	
	
}

void AVR_LED_delay_at_8MHz(uchar us)
{
	int i = us * COUNT_PER_US_8MHZ;
	
	do{
		
	} while(i--);
}