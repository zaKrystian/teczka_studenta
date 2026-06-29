
void telemetryArray::telemetryWrite() {
  if (global.sendTelemetry == true) {
    Serial.println(data);
  }
  if (global.saveTelemetry == true) {
    global.telemetryFile = SD.open(global.telemetryFilePath, FILE_WRITE);
    global.telemetryFile.println(data);
    global.telemetryFile.close();
  }
  if (global.sendReadableTelemetry == true) {
    String dataToSend;
    dataToSend = "T: " + (String)timeFromLaunch + "/ ALT: " + (String)altitude + "/ RELALT: " + (String)relAltitude + " / DeltaT: " + (String)deltaTime + " / V: " + (String)velocity + "/ PRE: " + (String)pressure + " / TEMP" + (String)temperature;
    Serial.println(dataToSend);
  }
  delay(10);
}