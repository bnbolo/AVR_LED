/*
 * ledsel.h
 *
 * Created: 2013/4/2 21:33:29
 *  Author: Benjamin Chen
 */ 


#ifndef LEDSEL_H_
#define LEDSEL_H_

#include "AVR_LED.h"

void ledsel_init();
void ledsel(uchar); // Select 0~19

#endif /* LEDSEL_H_ */