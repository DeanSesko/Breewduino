#include <OneWire.h>
#include <Stdio.h>
#include <EEPROM.h>


#define NUM_TS 9
byte tSensor[9][8];
int RunOnce = 0;
OneWire  ow(10);
int address = 0;
byte value;
int i;
int a;

 byte Tempaddr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
String MyString0;

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
   EEPROMreadBytes(0, *tSensor, 72);
   }
 
void loop(void) {
  
if (RunOnce == 1) { 
RunOnce = 0;
EEPROMreadBytes(0, *tSensor, 72);
for (int i = 0; i < 72; i++){
  EEPROM.write(i, 0);
}

for (int a = 0; a < NUM_TS; a++){
byte addr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
getDSAddr(addr);
setTSAddr(a, addr);
EEPROMreadBytes(0, *tSensor, 72);
}
}
for( i = 0; i < NUM_TS; i++) {

float temp;
float tmp2;
if (validAddr(tSensor[i])){
tmp2 = getTemperature(tSensor[i]);
temp = c2f(tmp2);
Serial.print(temp);
Serial.print(",Sensor");
Serial.println(i);

delay(10);
CheckSerialUpdate();
}
}


}
