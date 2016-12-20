void setupMag(void){
  
  //Initialize the sensor
  if(!mag.begin()){
    Serial.println("No HMC5883 detected (Magnometer)");
    while(1);
  }
  
}

void callMagHeading(){
  sensors_event_t event;
  mag.getEvent(&event);

  float heading = atan2(event.magnetic.y, event.magnetic.x);
  heading += declinationAngle;

  //Correction for heading
  if(heading<0){
    heading += 2*PI;
  }
  if(heading>2*PI){
    heading -= 2*PI;
  }

  //Convert heading to degrees
  heading = heading * 180/M_PI;
  
  TeleArray[TeleHeading] = heading;

}

/*void callMagDecline(){   // function doesnt fully work yet
  sensors_event_t event;
  mag.getEvent(&event);

  float decline = atan2(event.magnetic.z, event.magnetic.x);

  //Convert to degrees
  decline = decline * 180/M_PI;
  TeleArray[TeleDecline] = decline;
  
}*/



