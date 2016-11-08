void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


// potential switch function for GPS by: Sapi rSosnovsky
Void gpsSwitch(int alt) {
  
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
