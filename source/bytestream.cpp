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

ByteStream::ByteStream(uint8_t * pBuffer, uint32_t size)
{
    mBuffer = pBuffer;
    mCurrent = mBuffer;
    mEnd = mBuffer + size;
}

void ByteStream::reset()
{
    mCurrent = mBuffer;
}

bool ByteStream::isEnd()
{
    if (mCurrent == mEnd)
    {
        return true;
    }
    
    return false;
}

uint32_t ByteStream::size()
{
    return (uint32_t)(mCurrent - mBuffer);
}

void ByteStream::write8Bits(uint8_t data)
{
    *mCurrent = data;
    mCurrent++;
}

void ByteStream::write16Bits(uint16_t data)
{
    *mCurrent = (uint16_t)(data);
    *(mCurrent+1) = (data>>8UL);
    mCurrent += 2;
}

void ByteStream::write32Bits(uint32_t data)
{
    *mCurrent = (data);
    *(mCurrent+1) = (data>>8UL);
    *(mCurrent+2) = (data>>16UL);
    *(mCurrent+3) = (data>>24UL);
    mCurrent += 4;
}

void ByteStream::writeRawBytes(uint8_t * input, uint32_t size)
{
    memcpy(mCurrent, input,size);
    mCurrent += size;
}

uint8_t ByteStream::read8Bits()
{
    uint8_t data = *mCurrent;
    mCurrent++;
    
    return data;
}

uint16_t ByteStream::read16Bits()
{
    uint16_t integer = (mCurrent[1]<<8UL)| (mCurrent[0]);
    
    mCurrent +=2;
    return integer;
}

uint32_t ByteStream::read32Bits()
{
    uint32_t integer;
    uint32_t temp;

    temp = mCurrent[3];
    integer = temp << 24UL;

    temp = mCurrent[2];
    integer = (temp << 16UL) | integer;

    temp = mCurrent[1];
    integer = (temp << 8UL) | integer;    

    temp = mCurrent[0];
    integer = (temp) | integer;


    mCurrent +=4;
    return integer;
}

void ByteStream::readRawBytes(uint8_t * output, uint32_t size)
{
    memcpy(output, mCurrent,size);
    mCurrent += size;
}
