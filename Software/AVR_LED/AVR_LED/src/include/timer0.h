/*
 * timer0.h
 *
 * Created: 2013/4/18 22:54:25
 *  Author: Benjamin Chen
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "AVR_LED.h"

#define TIMER0_PRESCALER 256
typedef void (*timer0_cb)(void);


void timer0_init(ushort hz);
void timer0_start();
void timer0_stop();

void timer0_register_handle(timer0_cb func);

#endif /* TIMER0_H_ */