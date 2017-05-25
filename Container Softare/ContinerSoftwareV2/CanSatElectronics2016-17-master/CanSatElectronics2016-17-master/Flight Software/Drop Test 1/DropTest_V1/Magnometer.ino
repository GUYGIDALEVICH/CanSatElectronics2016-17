void setupMag(void){
  
  //Initialize the sensor
  if(!compass.begin()){
    Serial.println("No HMC5883 detected (Magnometer)");
  }

compass.setRange(HMC5883L_RANGE_1_3GA);
compass.setMeasurementMode(HMC5883L_CONTINOUS);
compass.setDataRate(HMC5883L_DATARATE_30HZ);
compass.setSamples(HMC5883L_SAMPLES_8);
compass.setOffset(0, 0);  
}

void callMagHeading(){

  Vector norm = compass.readNormalize();
  float heading = atan2((double) norm.YAxis, (double) norm.XAxis);
  
  TeleArray[TeleHeading] = heading;
  float declinationAngle = (GLOBE_DEG + (GLOBE_MIN / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  //Convert to degrees
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



