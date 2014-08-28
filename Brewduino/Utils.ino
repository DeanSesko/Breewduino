
void setTSAddr(byte sensor, byte addrB[8]) {
  memcpy(tSensor[sensor], addrB, 8);
  EEPROMwriteBytes(sensor * 8, addrB, 8);
 Serial.print("Sensor   ");
 Serial.print(sensor);
 Serial.print("  ");
 Serial.print("Wrote To Memmory   ");
 Printme(addrB);
}

void getDSAddr(byte addrRet[8]){
    byte scanAddr[8];
    ow.reset_search();
    byte limit = 0;
    while (limit <= 20) {
      if (!ow.search(scanAddr)) {
        ow.reset_search();
        return;
      }
      if (
          scanAddr[0] == 0x28 ||  //DS18B20
          scanAddr[0] == 0x10     //DS18S20
         ) 
      {
        boolean found = 0;
        for (byte i = 0; i <  NUM_TS; i++) {
          boolean match = 1;
          for (byte j = 0; j < 8; j++) {
            //Try to confirm a match by checking every byte of the scanned address with those of each sensor.
            if (scanAddr[j] != tSensor[i][j]) {
              match = 0;
              break;
            }
          }
          if (match) { 
            found = 1;
            break;
          }
        }
        if (!found) {
          for (byte k = 0; k < 8; k++) addrRet[k] = scanAddr[k];
          return;
        }
      }
      limit++;
    }      
  }
  
    boolean validAddr(byte* addrS) {
    for (byte i = 0; i < 8; i++) if (addrS[i]) return 1;
    return 0;
  }
  
  void Printme(byte MyBytes[]){
  MyString0 ="";
   for( i = 0; i < 8; i++) {
    MyString0 = String(MyString0 + String(MyBytes[i], HEX));
      }
   Serial.println(MyString0);
  
}
