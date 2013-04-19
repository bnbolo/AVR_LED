/*
 * PWM.c
 *
 * Created: 2013/4/19 10:20:53
 *  Author: Benjamin Chen
 */ 
#include "pwm.h"

void pwm_init()
{
	// pwm pins init, PB0, PB3, PB5 set to output
	DDRB = (0x1<<DDB1 | 0x1<<DDB3 | 0x1<<DDB5);
	
	//16M / 16384 = 0x3D0, fits in 10bit register
	TCCR1A = (0x2<<COM1A0 | 0x2<<COM1B0 | 0x1<<PWM1A | 0x1<<PWM1B); //Clear on Match, Set when 0
	TCCR1B = 0x0; //Prescaler CK/16384, but not started
	TCCR1C |= (0x2<<COM1D0 | 0x1<<PWM1D); //Clear on Match, Set when 0
	TCCR1D = (0x0); // Fast PWM mode
	TCCR1E = (0x1<<OC1OE1 | 0x1<<OC1OE3 | 0x1<<OC1OE5); // Enable PWM pins
	//PLLCSR already configured using fuse
	
	//Use PLL as timer1 clock source
	PLLCSR |= (0x1<<PCKE);
	
	//TC1H = 0x0;
	TCNT1 = 0x0; // Start from 0
	
	//TC1H = 0x1;
	OCR1A = 0x7F;	// Set 50%
	//TC1H = 0x1;
	OCR1B = 0x7F;	// Set 50%
	//TC1H = 0x1;
	OCR1D = 0x7F;	// Set 50%
}

void pwm_start()
{
	//TCCR1B = (TCCR1B&0xF0) | 0x0F; //Prescaler CK/16384
	//Use High frequency
	TCCR1B = (TCCR1B&0xF0) | 0x1;
}