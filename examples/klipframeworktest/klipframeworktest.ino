// Arduino Leonardo code test

#include <Arduino.h>
#include <avr/wdt.h> 
#include <klipframework.h>


VirtualTimer timerTest;

uint8_t queueBuffer[8];

Queue queueTest(queueBuffer,8);


void setup()
{
	Serial.begin(115200);

    // wait USB CDC connection   
    while (Serial==false)
    {
    }


    kPrint("Hello world from Kliplab !\n\r");
   	ERROR("wtf, we are testing the framework ?");

   	Serial.println("Type size: int long float double");
   	Serial.println(sizeof(int));
   	Serial.println(sizeof(long));
   	Serial.println(sizeof(float));
   	Serial.println(sizeof(double));


   	Serial.println("Test of byte stream:");
   	
	ByteStream stream(new uint8_t[16], 16);
    
    
    uint8_t buffer[8];
    uint32_t data1;
    uint16_t data2;
    
    stream.write16Bits(0x1234);
    stream.write32Bits(0xAABBCCDD);
    
    stream.reset();
    stream.readRawBytes(buffer, 6);
    
    for (int i=0;i<6;i++)
    {
        Serial.print(buffer[i], HEX);
        Serial.print(' ');
    }
    
    Serial.println();
    
    data2 = *(uint16_t *)buffer;
    data1 = *(uint32_t *)(buffer+2);

    Serial.print(data2, HEX);
    Serial.print(' ');
    Serial.println(data1, HEX);
    
    stream.reset();
    data2 = stream.read16Bits();
    data1 = stream.read32Bits();
    
    Serial.print(data2, HEX);
    Serial.print(' ');
    Serial.println(data1, HEX);


   	timerTest.start(1000);

   	//enable watchdog
   	wdt_enable(WDTO_500MS);
}

void loop()
{
	uint8_t data;

	// reset the watchdog
    wdt_reset();


    if ( Serial.available() != 0)
    {
        data = Serial.read();
        
        Serial.println("Test !");
        
        
    }
    
    // check the virtual timer, and reload it if expired
    if ( timerTest.isExpired()==true)
    {
        timerTest.start(100);
        
        LOG(("kikoo\r\n"));
        
    }
}
