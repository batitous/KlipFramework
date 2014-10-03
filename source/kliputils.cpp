/*
 The MIT License (MIT)
 
 Copyright (c) 2014 Baptiste Burles, Kliplab
 
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
#include "../klipframework.h"

static uint32_t m_z = 12434 ;
static uint32_t m_w = 33254;

void setRandomSeed(uint32_t s)
{
	m_z = s;
}

uint32_t getRandom(void)
{
    m_z = 36969 * (m_z & 65535) + (m_z >>16);
    m_w = 18000 * (m_w & 65535) + (m_w >>16);
    return ((m_z <<16) + m_w);
}

int32_t getRandomBetween(int32_t lowBoundary, int32_t highBoundary)
{
	return (getRandom() % (highBoundary - lowBoundary + 1) + lowBoundary);
}

uint32_t read32bitsFromBuffer(uint8_t *buffer)
{
	uint32_t integer;
    uint32_t temp;
    
    temp = buffer[3];
    integer = temp << 24UL;
    
    temp = buffer[2];
    integer = (temp << 16UL) | integer;
    
    temp = buffer[1];
    integer = (temp << 8UL) | integer;
    
    temp = buffer[0];
    integer = (temp) | integer;
    
    return integer;
}

void write32bitsToBuffer(uint8_t *buffer, uint32_t integer)
{
	buffer[0] = (uint8_t)(integer & 0xFF);
    buffer[1] = (uint8_t)((integer>>8UL) & 0xFF);
    buffer[2] = (uint8_t)((integer>>16UL) & 0xFF);
    buffer[3] = (uint8_t)((integer>>24UL) & 0xFF);
}

void write16bitsToBuffer(uint8_t * buffer, uint16_t integer)
{
    buffer[0] = (uint8_t)(integer);
    buffer[1] = (integer>>8UL);
}

uint16_t read16bitsFromBuffer(const uint8_t * buffer)
{
    uint16_t integer = (buffer[1]<<8UL)| (buffer[0]);
    
    return integer;
}