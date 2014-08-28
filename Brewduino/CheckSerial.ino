void CheckSerialUpdate (){

if (Serial.available() > 0) {
  int inByte = Serial.read();
  switch (inByte) {
    case 'a':  
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
     
      
      break;
      case 'b':    
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
     
      
      break;
      case 'c':    
      digitalWrite(2, LOW);
      break;
      case 'd': 
      digitalWrite(3, LOW);
       
      break;
      case 'e': 
      digitalWrite(4, LOW);
       
      break;
      case 'f': 
      digitalWrite(5, LOW);
      break;
      
      case 'g':    
      digitalWrite(2, HIGH);
      break;
      case 'h': 
      digitalWrite(3, HIGH);
       
      break;
      case 'i': 
      digitalWrite(4, HIGH);
       
      break;
      case 'j': 
      digitalWrite(5, HIGH);      
 }
  Serial.flush() ;
  Serial.println(inByte);
 }
}
