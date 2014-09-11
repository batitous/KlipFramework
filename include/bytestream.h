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
#ifndef    KLIP_FRAMEWORK_BYTESTREAM_H
#define    KLIP_FRAMEWORK_BYTESTREAM_H

// A stream of bytes
class ByteStream
{
public:
    
    ByteStream(uint8_t * pBuffer, uint32_t size);
    
    void reset();
    
    bool isEnd();
    
    uint32_t size();
    
    void write8Bits(uint8_t data);
    void write16Bits(uint16_t data);
    void write32Bits(uint32_t data);
    void writeRawBytes(uint8_t * input, uint32_t size);
    
    uint8_t read8Bits();
    uint16_t read16Bits();
    uint32_t read32Bits();
    void readRawBytes(uint8_t * output, uint32_t size);
    

private:
    uint8_t *   mBuffer;
    uint8_t *   mCurrent;
    uint8_t *   mEnd;
};

#endif

