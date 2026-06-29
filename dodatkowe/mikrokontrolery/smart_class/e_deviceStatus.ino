
void checkDeviceStatus() {
  Serial.println("Checking devices status\n");
  unsigned statusBMP, statusSD;
  if (global.bmp.begin(0X76) != 0) statusBMP = 1;
  else statusBMP = 0;

  if (SD.begin(1) != 0) statusSD = 1;
  else statusSD = 0;

  global.deviceStatus[0] = statusBMP;
  global.deviceStatus[0] = statusSD;

  if (global.checkFirstTime == true) {
    Serial.print("BMP status: ");
    if (statusBMP == 0) Serial.println("NOT ACTIVE");
    else Serial.println("ACTIVE");

    Serial.print("SD status: ");
    if (statusSD == 0) Serial.println("NOT ACTIVE");
    else Serial.println("ACTIVE");
    global.checkFirstTime == false;
  }
}