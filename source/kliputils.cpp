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

static unsigned int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;

void setRandomSeed(uint32_t s)
{
	z1 = s;
	z2 = s;
	z3 = s;
	z4 = s;
}

uint32_t getRandom(void)
{
   unsigned int b;
   b  = ((z1 << 6) ^ z1) >> 13;
   z1 = ((z1 & 4294967294U) << 18) ^ b;
   b  = ((z2 << 2) ^ z2) >> 27; 
   z2 = ((z2 & 4294967288U) << 2) ^ b;
   b  = ((z3 << 13) ^ z3) >> 21;
   z3 = ((z3 & 4294967280U) << 7) ^ b;
   b  = ((z4 << 3) ^ z4) >> 12;
   z4 = ((z4 & 4294967168U) << 13) ^ b;
   return (z1 ^ z2 ^ z3 ^ z4);
}

int32_t getRandomBetween(int32_t lowBoundary, int32_t highBoundary)
{
	return (getRandom() % (highBoundary - lowBoundary + 1) + lowBoundary);
}

uint32_t get4FromBuffer(byte *buffer)
{
	uint32_t result = 0;
	uint32_t temp;

	temp = buffer[0];
	result =  (temp << 24UL);

	temp = buffer[1];
	temp = (temp << 16UL);
	result = result | temp;

	temp = buffer[2];
	temp = (temp << 8UL);
	result = result | temp;

	temp = buffer[3];
	result = result | temp;

	return result;
}

void set4ToBuffer(byte *buffer, uint32_t result)
{
	buffer[0] = (result>>24UL);
	buffer[1] = (result>>16UL);
	buffer[2] = (result>>8UL);
	buffer[3] = (result);
}
