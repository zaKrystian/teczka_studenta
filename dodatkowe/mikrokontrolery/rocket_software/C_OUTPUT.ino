void statusLEDControl() {
  if (global.bmpStatus == 0 || global.mpuStatus == 0) {
    global.fatalError == true;
    ledON('r');
  } else {
    global.fatalError == false;
    ledOFF('r');
  }
}

void TelemetryFiled::convertTelemetryData() {

  telemetryString = "ID: " + (String)global.messageID + " / ALT: " + (String)altAbs + " / AccelX: " + (String)accelX + " / GyroX: " + (String)gyroX + ">";
}

void TelemetryFiled::writeSerialTelemetry() {
  if (global.sendSerialTelemetry == true) {
    Serial.println(telemetryString);
  }
}