//#include <SoftwareSerial.h>
//#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified compass = Adafruit_HMC5883_Unified(12345);

float rollOffset;
float pitchOffset;

void setup() {
  Serial.begin(9600);
  compass.begin();
  if (compass.begin()) {
    Serial.println("Magnometer Setup");
  }
  else {
    Serial.println("Magnometer not setup");
  }

  sensors_event_t event;
  compass.getEvent(&event);
  rollOffset = atan2(event.magnetic.z,event.magnetic.y);
  pitchOffset = atan2(event.magnetic.z,event.magnetic.x);
  
}


void loop() {
  sensors_event_t event;
  compass.getEvent(&event);

  //Just for testing and calibration purposes
  //Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print("  ");
  //Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  //Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.print("  "); Serial.println("uT");

  float heading = atan2(event.magnetic.y, event.magnetic.x);
  float pitch = atan2(event.magnetic.z,event.magnetic.x);   //Adjustments need to be made according to how the hmc is placed on the PCB, but its not a big thing, its mainly just
  float roll = atan2(event.magnetic.z,event.magnetic.y);    //changing pitch to roll and roll to pitch

  heading -= 0.175;
  roll -= rollOffset;
  pitch -= pitchOffset;
  
  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  if (pitch < 0)
  {
    pitch += 2 * PI;
  }
  if (pitch > 2 * PI)
  {
    pitch -= 2 * PI;
  }
  if (roll < 0)
  {
    roll += 2 * PI;
  }
  if (roll > 2 * PI)
  {
    roll -= 2 * PI;
  }


  float HeadingDegree = heading * (180 / PI);
  float PitchDegree = pitch * (180 / PI);
  float RollDegree = roll  * (180 / PI);
  
  //Serial.println(HeadingDegree);
  //Serial.println(PitchDegree);
  Serial.println(RollDegree);
  delay(250);
}
