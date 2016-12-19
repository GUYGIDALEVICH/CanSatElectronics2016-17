void transmitAndSaveData() {
 
//transmits data via serial & saves data to SD

teleTime = millis();
timeDelay();
//
//TeleArray[0] = data.teamID;
//TeleArray[1] = data.missionTime;
//TeleArray[2] = data.packetCount;
//TeleArray[3] = data.altitidue
//TeleArray[4] = data.pressure;
//TeleArray[5] = data.vspeed;
//TeleArray[6] = data.temperature;
//TeleArray[7] = data.voltage;
//TeleArray[8] = data.heading; 
//TeleArray[9] = data.softwareState;
//TeleArray[10] = data,bonus;


}


void receiveRadioData() {
//Receive single char that was transmitted by ground station

//If it is a certain char, ex '*', release the payload
}


void printLegend() {
  //Prints the order of the data that we're transmitting
  Serial.print("");;
  
}

void timeDelay(){
 while(millis() - teleTime < (long) 1000){}
}

