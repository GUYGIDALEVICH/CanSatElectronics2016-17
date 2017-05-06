void setupGPS()
{
  Serial.begin(19200);
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);   // 1 Hz update rate
}

void callGPS()
{
      LocationArray[Latitude] = GPS.latitudeDegrees;
      LocationArray[Longitude] = GPS.longitudeDegrees;
      
//      Serial.print(LocationArray[Latitude]);          Uncomment to see lat/long data in serial monitor (for testing)
//      Serial.print(", ");                             
//      Serial.println(GPS.longitudeDegrees,4);    
}
