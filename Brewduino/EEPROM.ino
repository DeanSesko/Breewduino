
void EEPROMreadBytes(int addr, byte bytes[], byte numBytes) {
  for (byte i = 0; i < numBytes; i++) {
    bytes[i] = EEPROM.read(addr + i);
   
   }
   
   
}
void EEPROMwriteBytes(int addr, byte bytes[], byte numBytes) {
  //if (!(bytes =Tempaddr)){
  for (byte i = 0; i < numBytes; i++) {
    EEPROM.write(addr + i, bytes[i]);
    }
}
//}

void EEPROMreadBytes2(int addr, byte bytes[], byte numBytes) {
  for (byte i = 0; i < numBytes; i++) {
    bytes[i] = EEPROM.read(addr + i);
    Serial.print(bytes[i],HEX);
    }
Serial.println("");
}
