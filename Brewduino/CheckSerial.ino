void CheckSerialUpdate (){

if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    // Turns Relay on for RIMS tube
    case 'a':  
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);   
      break;
      
      // Turns Relay Off for RIMS tube
      case 'b':    
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);   
      break;
      
      // Turns HL Pump ON
      case 'c':   
      digitalWrite(2, LOW);
      break;
      
      // Turns Mash Pump ON
      case 'd': 
      digitalWrite(3, LOW);
      break;

         // Turns HL Pump Off
      case 'g':    
      digitalWrite(2, HIGH);
      break;
      
       // Turns Mash Pump Off
      case 'h': 
      digitalWrite(3, HIGH); 
      break;
      
      
      // Places Arduino into setup mode to find all One Wire Addresses
      case 's':
      RunOnce=1;
   
 }
  Serial.flush() ;
  Serial.println(inByte);
 }
}
