/* #include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h> */
//libraries used for this sensor

Adafruit_HMC5883_Unified mag;

void setupMag(void){
  
  //Initialize the sensor
  if(!mag.begin()){
    Serial.println("No HMC5883 detected (Magnometer)");
    while(1);
  }
  
}

void callMag(){
  sensors_event_t event;
  mag.getEvent(&event);

  float heading = atan2(event.magnetic.y, event.magnetic.x);
  float declinationAngle = 0.17; // declination angle for Toronoto only. needs to be adjusted for accuracy.

  heading += declinationAngle;

  //Correction for heading
  if(heading<0){
    heading += 2*PI;
  }
  if(heading>2*PI){
    heading -= 2*PI;
  }

  //Convert heading to degrees
  float headingDegrees = heading * 180/M_PI;
  Serial.println(headingDegrees);
}



