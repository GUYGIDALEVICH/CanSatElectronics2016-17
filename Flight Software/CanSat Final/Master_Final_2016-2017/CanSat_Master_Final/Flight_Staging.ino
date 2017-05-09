void initialize()  //Starts all the sensors
{
  if (flightState == 1)
  {
    Wire.begin();
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
  if (flightState != 3)
  {
    flightState = 3; //Need to add the read function. no idea how though
  }
  else
  {

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

