void setup() {
  Serial.begin(9600);
  delay(5000);
  checkDeviceStatus();

  float alt0Array[5];
  float sumAlt0 = 0;

  for (int i = 0; i < 5; i++) {
    alt0Array[i] = global.bmp.readAltitude(1013);

    sumAlt0 += alt0Array[i];
  }

  global.alt0 = (float)sumAlt0 / 5;
  global.flightStartTime = (float)millis() / 1000;
}