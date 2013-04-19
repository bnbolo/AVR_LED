/*
 * ledsel.c
 *
 * Created: 2013/4/2 21:33:13
 *  Author: Benjamin Chen
 */ 

#include "ledsel.h"

// PA1, PA2, PA3 as LEDSEL1~3
// PA4, PA5, PA6 as LEDSEL4~6
// Selecting LED 1 ~ 20:
// 0b001000 - 0b001111 x8 
// 0b010000 - 0b010111 x8
// 0b100000 - 0b100011 x4

uchar ledsel_index[] = {
	0x08<<1, 0x09<<1, 0x0a<<1, 0x0b<<1, 0x0c<<1, 0x0d<<1, 0x0e<<1, 0x0f<<1,
	0x10<<1, 0x11<<1, 0x12<<1, 0x13<<1, 0x14<<1, 0x15<<1, 0x16<<1, 0x17<<1,
	0x20<<1, 0x21<<1, 0x22<<1, 0x23<<1
};

void ledsel_init()
{
	DDRA = DDRA | (0x1<<DDA1 | 0x1<<DDA2 | 0x1<<DDA3 | 0x1<<DDA4 | 0x1<<DDA5 | 0x1<<DDA6);		
}

void ledsel(uchar i)
{
	PORTA = ledsel_index[i];
}

