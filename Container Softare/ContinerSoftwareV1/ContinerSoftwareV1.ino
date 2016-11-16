#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure; //Pressure object created
double baseline;

void setup() {
  // put your setup code here, to run once:
    baseline = getPressure(); // Get baseline pressure initially
}

void loop() {
  // put your main code here, to run repeatedly:

}


// potential switch function for GPS by: Sapi rSosnovsky
void gpsSwitch(int alt) {
  
  if (alt < 100){
  // some code to tell the gps to start working
  // some xbee code which will be sent to ground when the alt is close enough to the ground
  }else{
  // do nothing if the alt is not close enough to the ground
  }
  
}

// Converts the input data to string so it can be exported to the Xbee If questions ask: Sapir Sosnovsky
String transmitTelemetry (int teamID, unsigned long missionTime, int packetCount, int alt, int tempContainer, float vBatt, int softwareState){
// pushes the parameter for the gps switch 
  gpsSwitch (alt);
  
//Converts all input into string which are gonna be sent trough xbee code things
  String R = String(teamID)+","+String(missionTime)+","+String(packetCount)+","+String(alt)+","+String(tempContainer)+","+String(vBatt)+","+String(softwareState);
    
  return (R);
}

//Temperature Function by Dan Stingaciu
int tempContainer(void){
  double temp;
  char status;
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, Message pops up
  status = pressure.startTemperature();
  //Checks to make sure that sensor is reading temperature value, if not then notifies serial monitor
  if(status!=0){ 
    delay(status); //Wait for calculations to finsish
    status = pressure.getTemperature(temp); //After waiting for calculations use temp variable
  }else{
    Serial.println("Something's wrong with the temperature!");   
  }
  return temp; //returns temp 
}


// Voltage converter function by Dan Stingaciu

float vBatt(int analogPin, float lowScale, float highScale){
  int mapped; //Mapped value variable
  mapped = map(analogPin, 0, 1023, lowScale, highScale); //Maps the value of your input between whatever values it needs. 
  return mapped;
}

//Altitude function by Dan Stingaciu
int altContainer(void){
  int alt,p;
  p = getPressure(); //Get pressure
  alt = pressure.altitude(p,baseline); //Measure altitude using baseline pressure vs current pressure
  return alt; //returns pressure
}

//Pressure function by Dan Stingaciu
double getPressure(){ 
  char status;
 // Start a pressure measurement:
 // If request is successful, the number of ms to wait is returned.
 // If request is unsuccessful, error message is returned.
  status = pressure.startPressure(3);
  double p; //Pressure
  double t = tempContainer(); //Get current temperature
  if(status!=0){ //checks if reading was successful
    delay(status); //Delay for proper reading
    status = pressure.getPressure(p,t); //Get the pressure which assigns it to variable p according to library
  }else{
    Serial.println("ERROR READING PRESSURE"); 
  }
  return p; //Returns pressure
}

