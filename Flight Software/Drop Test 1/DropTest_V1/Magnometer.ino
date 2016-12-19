/* #include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h> */
//libraries used for this sensor
#define declinationAngle 0.17 // declination angle for Toronto only, needs to be adjusted for different locations.

Adafruit_HMC5883_Unified mag;

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
  //Serial.println(heading); // change to store heading in the array that contains all info
}

void callMagDecline(){
  sensors_event_t event;
  mag.getEvent(&event);

  float decline = atan2(event.magnetic.z, event.magnetic.x);

  //Convert to degrees
  decline = decline * 180/M_PI;
  TeleArray[TeleDecline] = decline;
  //Serial.println(decline); //this is extra just for team knowledge so maybe just print to serial?
  
}



