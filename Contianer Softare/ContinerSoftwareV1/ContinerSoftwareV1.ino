void setup() {das
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

String transmitTelemetry (int teamID, unsigned long missionTime, int packetCount, int alt, int tempContainer, float vBatt, int softwareState){
  
 String R = String(teamID)+","+String(missionTime)+","+String(packetCount)+","+String(alt)+","+String(tempContainer)+","+String(vBatt)+","+String(softwareState);
 return (R);
}
