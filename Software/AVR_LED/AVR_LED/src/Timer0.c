/*
 * Timer0.c
 *
 * Created: 2013/4/18 22:53:53
 *  Author: Benjamin Chen
 */ 


#include "timer0.h"

static timer0_cb timer0_handle;

// 1HZ 16M / 256 = 0xF424, Normal, 16-bit Mode, 0xFFFF - 0xF424 = 0x0BDB
#define HZ_INIT_VALUE (0xFFFF-0xF424)
// 2HZ 16M / 2 / 256 = 0x7A12, Normal, 16-bit Mode, 0xFFFF - 0x7A12 = 0x85ED
#define HZ2_INIT_VALUE (0xFFFF-0x7A12)

void timer0_init(ushort hz)
{
	
	TCCR0A = (0x1<<TCW0);
	TCCR0B = (0x4);

	TCNT0H = 0x0B;
	TCNT0L = 0xDB;			// 
	
	TIFR |= (0x1<<TOV0);	// Clear in advance
	TIMSK = (0x1<<TOIE0);
	
}

void timer0_start()
{
	TCCR0A |= (0x1<<WGM00);
}

void timer0_stop()
{
	TCCR0A &= ~(0x1<<WGM00);
}


ISR(TIMER0_OVF_vect)
{
	TCNT0H = (HZ_INIT_VALUE & 0xFF00)>>8;
	TCNT0L = (HZ_INIT_VALUE & 0x00FF);
	
	(*timer0_handle)();
}


void timer0_register_handle(timer0_cb func)
{
	timer0_handle = func;	
}