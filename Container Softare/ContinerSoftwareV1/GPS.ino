//boolean usingInterrupt = false;
//void useInterrupt(boolean);
//
//void setupGPS(){
//  GPS.begin(9600);
//  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
//  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
//  useInterrupt(true);
//}
//
//SIGNAL(TIMER0_COMPA_vect) {
//  char c = GPS.read();
//  // if you want to debug, this is a good time to do it!
//#ifdef UDR0
//  if (GPSECHO)
//    if (c) UDR0 = c;  
//    // writing direct to UDR0 is much much faster than Serial.print 
//    // but only one character can be written at a time. 
//#endif
//}
//

