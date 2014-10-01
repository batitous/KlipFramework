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
#ifndef KLIP_FRAMEWORK_UTILS_H
#define KLIP_FRAMEWORK_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

// set value at specified position
#define BITS(position,value) 	((value)<<(position))

// set 1 at specified position
#define BIT(position) 		(1<<(position))

// set 1 into register at position
#define SETBIT(reg,position)    reg |= (1<<((unsigned int)position))

// clear one bit of register at position
#define CLRBIT(reg,position)  reg &= ~(1<<((unsigned int)position))

// clear multiple bits of register
#define CLRBITS(reg,mask)     reg &= ~(mask)

// like printf, for embedded system
extern void kPrint(const char*	str,	...);


// fast random
extern void setRandomSeed(uint32_t s);
extern uint32_t getRandom(void);
extern int32_t getRandomBetween(int32_t lowBoundary, int32_t highBoundary);



// read / write 32 bits from a buffer
extern uint32_t read32bitsFromBuffer(uint8_t *buffer);
extern void write32bitsToBuffer(uint8_t *buffer, uint32_t result);

// read / write 16 bits from a buffer
extern void write16bitsToBuffer(uint8_t * buffer, uint16_t integer);
extern uint16_t read16bitsFromBuffer(const uint8_t * buffer);

#ifdef	__cplusplus
}
#endif

#endif

