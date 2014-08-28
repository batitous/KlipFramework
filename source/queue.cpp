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
#include <Arduino.h>
#include "../klipframework.h"

Queue::Queue(uint8_t * pBuffer, uint16_t size)
{
    reset();
    mSize = size;
    mPending = pBuffer;
}

void Queue::reset()
{
    mHead = 0;
    mTail = 0;
}

int Queue::available()
{
    if (mHead == mTail)
    {
        return 0;
    }

    if (mHead <= mTail)
    {
        return mTail - mHead;
    }

    return (mSize - mTail + mHead);
}

bool Queue::write(uint8_t data)
{
    uint32_t size = mSize-1;
    if ( ((mTail+1) & (size)) == ((mHead) & (size)) )
    {
        return false;
    }
  
    mPending[mTail & (size)] = data;
    mTail++;
    
    return true;
}

bool Queue::read(uint8_t * data)
{
    if (mHead == mTail)
    {
        return false;
    }
    
    *data = mPending[mHead & (mSize-1)];
    mHead++;
    
    return true;
}
