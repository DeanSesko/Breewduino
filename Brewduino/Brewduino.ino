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
  Serial.begin(57600);
    pinMode(8, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);

   }
 

 
void loop(void) {

 if (loopcount  < 10) {
   loopcount = loopcount +1;
 }
   else{
   loopcount=0;
 }
Serial.println (loopcount);
float temp;
float tmp2;
tmp2 = getTemperature(HL);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",HL");
delay(10);
if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    case 'a':  
      digitalWrite(8, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      
      break;
      case 'b':    
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      
      break;
      case 'c':    
      digitalWrite(8, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);

 }
  Serial.flush() ;
  Serial.println(inByte);

 }

tmp2 = getTemperature(Kettle);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",Kettle");
delay(10);
if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    case 'a':  
      digitalWrite(8, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      
      break;
      case 'b':    
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      
      break;
      case 'c':    
      digitalWrite(8, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);

 }
  Serial.flush() ;
  Serial.println(inByte);

 }
 tmp2 = getTemperature(OverHeatTemp);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",OverHeatTemp");
delay(10);
if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    case 'a':  
      digitalWrite(8, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      
      break;
      case 'b':    
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      
      break;
      case 'c':    
      digitalWrite(8, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);

 }
  Serial.flush() ;
  Serial.println(inByte);

 }
tmp2 = getTemperature(Mash);
temp = c2f(tmp2);
Serial.print(temp);
Serial.println(",Mash");
delay(10);
if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    case 'a':  
      digitalWrite(8, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      
      break;
      case 'b':    
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      
      break;
      case 'c':    
      digitalWrite(8, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);

 }
  Serial.flush() ;
  Serial.println(inByte);

 }
tmp2 = getTemperature(RimTemp);
temp = c2f(tmp2);

Serial.print(temp);
Serial.println(",RimTemp");

delay(10);
if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    case 'a':  
      digitalWrite(8, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      
      break;
      case 'b':    
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      
      break;
      case 'c':    
      digitalWrite(8, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);

 }
  Serial.flush() ;
  Serial.println(inByte);

 }
}
