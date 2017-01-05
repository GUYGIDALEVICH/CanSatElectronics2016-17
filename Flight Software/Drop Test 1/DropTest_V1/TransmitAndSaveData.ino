void transmitData() {
 
//transmits data via serial & saves data to SD
  
  radio.print(TeamID);
  radio.print(',');
  radio.print("GLIDER");
  radio.print(',');
  
  for (int telem = 1; telem < TeleArrayLength; telem++){
    radio.print(TeleArray[telem]);
    radio.print(',');
  }

  Serial.println();
  

teleTime = millis();
}

void transmitData_Serial() {
 
//transmits data via serial & saves data to SD
  
  Serial.print(TeamID);
  Serial.print(',');
  Serial.print("GLIDER");
  Serial.print(',');
  
  for (int telem = 1; telem < TeleArrayLength; telem++){
    Serial.print(TeleArray[telem]);
    Serial.print(',');
  }

  Serial.println();
  

teleTime = millis();
}

void receiveRadioData() {

  //Checks to see if commands have come in via radio
  if (radio.available()){
    String RadioRecieve = Serial.readString();
    //Preform Task
  }

}




void timeDelay(){
 while(millis() - teleTime < (long) 1000){}
}

