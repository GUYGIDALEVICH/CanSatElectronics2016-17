void bmpBegin()
{
  //Setup
  bmp.begin();
  if (bmp.begin())
  {
    Serial.println("BMP Detected");
  }
  else
  {
    Serial.println("Error, BMP Not Detected");
  }
}

void callTemp()
{
  status = bmp.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp.getTemperature(T);
    if (status != 0)
    {
      telemetry[teleTemp] = (float)T;
    }
  }
}
void callBasePressure()
{
  status = bmp.startPressure(3);
  if (status != 0)
  {
    delay(status);
    status = bmp.getPressure(P, T);
    if (status != 0)
    {
      P0 = (float)P;
    }
  }
}
void callPressure()
{
  status = bmp.startPressure(3);
  if (status != 0)
  {
    delay(status);
    status = bmp.getPressure(P, T);
    if (status != 0)
    {
      telemetry[telePressure] = (float)P;
    }
  }
}
void callAlt()
{
  A = bmp.altitude(P, P0);
  telemetry[teleAlt] = (float)A;
}
