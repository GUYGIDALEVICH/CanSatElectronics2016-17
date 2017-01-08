
void transmitData() {
  Serial.print(TeamID);
  Serial.print(',');
  Serial.print("CONTAINER");
  Serial.print(',');
  
  for (int telem = 1; telem < TeleArrayLength; telem++){
    Serial.print(TeleArray[telem]);
    Serial.print(',');
  }

  Serial.println();
  

teleTime = millis();
}


void receiveSerialData() {
//Receive single char that was transmitted by ground station

//If it is a certain char, ex '*', release the payload
}




void timeDelay(){
 while(millis() - teleTime < (long) 1000){}
}
