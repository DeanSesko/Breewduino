#include <OneWire.h>
#include <Stdio.h>

OneWire  ow(10);
 
byte HL[8] ={0x28, 0x54, 0x78, 0x7B, 0x02, 0x00, 0x00, 0xCC};


//byte Mash[8] ={0x28, 0x54, 0x72, 0x7B, 0x02, 0x00, 0x00, 0x71};
byte Mash[8] ={0x28, 0x9F, 0xA0, 0x7B, 0x02, 0x00, 0x00, 0xCB};
byte Kettle[8] ={0x28, 0x2C, 0x35, 0x81, 0x02, 0x00, 0x00, 0x9A};
byte RimTemp[8]= {0x28, 0x7F, 0x71, 0x7B, 0x02, 0x00, 0x00, 0x71};
byte OverHeatTemp[8]= {0x28, 0xAD, 0xAC, 0x7B, 0x02, 0x00, 0x00, 0x69};
int loopcount = 0;
void setup(void) {
  Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);

   }
 

 
void loop(void) {

float temp;
float tmp2;
tmp2 = getTemperature(HL);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",HL");
delay(10);
CheckSerialUpdate();
tmp2 = getTemperature(Kettle);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",Kettle");
delay(10);
CheckSerialUpdate();
 tmp2 = getTemperature(OverHeatTemp);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",OverHeatTemp");
delay(10);
CheckSerialUpdate();
tmp2 = getTemperature(Mash);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",Mash");
delay(10);
CheckSerialUpdate();
tmp2 = getTemperature(RimTemp);
temp = c2f(tmp2);

Serial.print(temp);
Serial.println(",RimTemp");

delay(10);
CheckSerialUpdate();
}
