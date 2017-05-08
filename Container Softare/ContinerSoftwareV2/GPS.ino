void setupGPS()
{
  Serial.begin(19200);
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);   // 1 Hz update rate
}

//updates GPS data
void callGPS()
{
      TeleArray[TeleLat] = GPS.latitudeDegrees;
      TeleArray[TeleLong] = GPS.longitudeDegrees;
}
