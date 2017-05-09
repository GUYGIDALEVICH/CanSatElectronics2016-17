void compassBegin()
{
  //Setup
  compass.begin();
  if (compass.begin()) {
    Serial.println("Magnometer Setup");
  }
  else {
    Serial.println("Magnometer not setup");
  }
}

void getHeading() {
  sensors_event_t event;
  compass.getEvent(&event);

  float heading = atan2(event.magnetic.y, event.magnetic.x);
  //adding the declination correction for toronto
  heading += 0.07301;

  if (heading < 0) heading += 2 * PI;
  if (heading > 2 * PI) heading -= 2 * PI;

  float degree = heading * (180 / PI);
  telemetry[teleHeading] = degree;
}
