void telemetryArray::sampleData() {

  packageID = global.telemetryID;
  timeFromLaunch = ((float)millis() / 1000) - global.flightStartTime;
  global.timeFromLauch = timeFromLaunch;
  altitude = global.bmp.readAltitude(1013);
  pressure = global.bmp.readPressure();
  temperature = global.bmp.readTemperature();
  relAltitude = altitude - global.alt0;

  global.flightAltitude[0] = global.flightAltitude[1];
  global.flightAltitude[1] = altitude;
  deltaAltitude = global.flightAltitude[1] - global.flightAltitude[0];

  global.flightTime[0] = global.flightTime[1];
  global.flightTime[1] = timeFromLaunch;
  deltaTime = global.flightTime[1] - global.flightTime[0];



  velocity = deltaAltitude / deltaTime;  //not defined, calculated based on sensor data
  distanceInTime = -1;                   // not defined, calculated based on sensor data
  distanceToLaunchpad = -1;
}

void telemetryArray::createTelemetryPackage() {
  data = "~" + (String)packageID + ":" + (String)packageType + ":" + (String)timeFromLaunch + ":" + (String)deviceStatusInTime[0] + "/" + (String)deviceStatusInTime[1] + ":" + (String)altitude + ":" + (String)relAltitude + ":" + (String)velocity + ":" + (String)distanceInTime + ":" + (String)distanceToLaunchpad + ":" + (String)pressure + ":" + (String)temperature + ":" + (String)checksum + "#";
}
