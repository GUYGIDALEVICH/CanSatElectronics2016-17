void transmitAndSaveData() {
 
//transmits data via serial & saves data to SD
  
  radio.print(TeamID, DEC);
  radio.print(',');
  radio.print("GLIDER");
  radio.print(',');
  
  for (int telem = 1; telem < TeleArrayLength; telem++){
    radio.print(TeleArray(telem), DEC);
    radio.print(',');
  }
  
  

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

