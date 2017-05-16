void initialize()  //Starts all the sensors
{
  if (flightState == 1)
  {
    Wire.begin();
    bmpBegin();
    compassBegin();
    RTCBegin(); //comment this out when the groundbutton is ready.
    radioBegin();
    cameraBegin();
    telemetry[teleCount] = count;
  }
  flightState = 2;
}

void boot()  //Checks eeprom for packet count, flight state and other variables if we have any.
{
  //Pulls data from EEPROM. Updates the value of packet count. Checks flightState and updates the one on storage.
  extEEPROMRead(fsAddress, &flightState);
  if (flightState != 3)
  {
    extEEPROMRead(ctAddress, &telemetry[teleCount]);
    flightState = 3; 
  }
}

void dpwait()  //Keeps the arduino in a lower power state awaiting deployment
{

}

void descent()  //Collects the telemetry and transmits it every time its called. also takes pictures. fun right?
{
  updateTelemetry();
  takePicture();
  transmitXB();
  if (abs(telemetry[teleAlt]) <= 20)
  {
    flightState = 4;
  }
}

void land()
{
  Serial.print("Final data sent. Buzzer turning on now");
  //Buzzer hahahaha
}

