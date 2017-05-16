void radioBegin()
{
  //Setup
  Serial.begin(19200);
  Serial.println("Xbee Detected");//not really
}

void transmitXB()
{
  Serial.print("Mission Time: ");
  Serial.print(telemetry[teleTime]);
  Serial.println("s");

  Serial.print("Temperature: ");
  Serial.print(telemetry[teleTemp], 2);
  Serial.println("deg C");

  Serial.print("Pressure: ");
  Serial.print(telemetry[telePressure], 2);
  Serial.println("mb");

  Serial.print("Altitude: ");
  Serial.print(telemetry[teleAlt], 2);
  Serial.println("m");

  Serial.print("Heading: ");
  Serial.print(telemetry[teleHeading], 2);
  Serial.println("degrees from magnetic N");

  Serial.print("Count: ");
  Serial.println(telemetry[teleCount]);
}
