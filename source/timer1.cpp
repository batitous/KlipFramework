/*
 The MIT License (MIT)
 
 Copyright (c) 2013 Baptiste Burles, Kliplab
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <Arduino.h>
#include "klipframework.h"


//----------------------------- private functions & variables


static volatile uint32_t timer1Counter;

TimerIrqCallback timer1IrqCallback;


ISR (TIMER1_COMPA_vect)
{
	timer1Counter++;

	timer1IrqCallback();
}

uint32_t getPrescalerDiv(TIMER_PRESCALER prescaler)
{
	uint32_t div = 1;
	
	switch(prescaler)
	{
		default :
		case PRESCALER_1:
			div = 1;
			break;
		case PRESCALER_8:
			div = 8;
			break;
		case PRESCALER_64:
			div = 64;
			break;
		case PRESCALER_256:
			div = 256;
			break;
		case PRESCALER_1024:
			div = 1024;
			break; 
	}

	return div;
}


//----------------------------- public functions


void initTimer1(uint32_t timeInUs, TIMER_PRESCALER prescaler, TimerIrqCallback callback)
{
	timer1Counter = 0;
	timer1IrqCallback = callback;

	TCCR1A = 0;

	// clear previous prescaler
	CLRBITS(TCCR1B, 0x7);

	// set prescaler 
	SETBIT(TCCR1B, prescaler);

	// mode CTC
	SETBIT(TCCR1B, 3);

	// enable IRQ on match
	SETBIT(TIMSK1, 1);

	OCR1A = US_TO_TICK(timeInUs, getPrescalerDiv(prescaler));
}

uint32_t getTimer1Counter(void)
{
	uint32_t temp;

	//TODO protect it ?	
	temp = timer1Counter;

	return temp;
}

