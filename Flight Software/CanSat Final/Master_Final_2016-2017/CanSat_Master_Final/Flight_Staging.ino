void initialize()  //Starts all the sensors
{
  if (flightState == 1)
  {
    bmpBegin();
    compassBegin();
    RTCBegin();
    radioBegin();
    cameraBegin();
    telemetry[teleCount] = count;
  }
  else
  {
  //Nothing happens
  }
  flightState = 2;
}

void updateTelemetry()  //Just takes readings
{
  callTemp();
  callPressure();
  callAlt();
  getHeading();
  getTime();
}

void boot()  //Checks eeprom for packet count, flight state and other variables if we have any.
{
  //Eeprom check and update all the saved internal telemetry data if needed
  flightState = 3;
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
    flightState = 5;
  }
}

void land()
{
  //Buzzer hahahaha
}

