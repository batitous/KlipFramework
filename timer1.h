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
#ifndef KLIP_FRAMEWORK_TIMER1_H
#define KLIP_FRAMEWORK_TIMER1_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum _timer_prescaler_
{
	PRESCALER_1 	= 0x0,
	PRESCALER_8 	= 0x1,
	PRESCALER_64 	= 0x3,
	PRESCALER_256 	= 0x4,
	PRESCALER_1024	= 0x5
} TIMER_PRESCALER;

#define US_TO_TICK(u, prescaler)    (((u) * F_CPU) / (1000000UL * prescaler))

typedef void (*TimerIrqCallback)(void);


extern void initTimer1(unsigned long timeInUs, TIMER_PRESCALER prescaler, TimerIrqCallback callback);

extern unsigned int getTimer1Counter(void);


#ifdef	__cplusplus
}
#endif

#endif