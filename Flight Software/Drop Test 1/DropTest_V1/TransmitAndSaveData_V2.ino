void transmitAndSaveData() {
//transmits data via serial & saves data to SD
}


void receiveRadioData() {
//Receive single char that was transmitted by ground station

//If it is a certain char, ex '*', release the payload
}


void printLegend() {
  //Prints the order of the data that we're transmitting
  Serial.print("temp\n pressure\n magnometer\n altitude\n RTC");
  
}

void timeDelay(){
  delay(1000); //Waits for a second
}

