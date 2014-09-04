/*  
  Routines used to read and write to the EEPROM
*/


// Routine to read Sensor addresses from the EEPROM
void EEPROMreadBytes(int addr, byte bytes[], byte numBytes) {
  
  for (byte i = 0; i < numBytes; i++) {
  bytes[i] = EEPROM.read(addr + i);
  }
}

//Function to write Sensor addresseses to the EEPROM
void EEPROMwriteBytes(int addr, byte bytes[], byte numBytes) {

  for (byte i = 0; i < numBytes; i++) {
  EEPROM.write(addr + i, bytes[i]);
  }
}



