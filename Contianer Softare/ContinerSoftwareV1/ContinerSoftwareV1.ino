void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

// Converts the input data to string so it can be exported to the Xbee If questions ask: Sapir Sosnovsky
String transmitTelemetry (int teamID, unsigned long missionTime, int packetCount, int alt, int tempContainer, float vBatt, int softwareState){
  
 String R = String(teamID)+","+String(missionTime)+","+String(packetCount)+","+String(alt)+","+String(tempContainer)+","+String(vBatt)+","+String(softwareState);
 return (R);
}
