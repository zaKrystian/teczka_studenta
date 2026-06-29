void TelemetryFiled::checkBMP() {
  if (bmp.takeForcedMeasurement()) {
    BMPvalid = true;
    global.bmpStatus = 1;
  } else {
    if (bmp.begin(bmpAdress)) {
      global.bmpStatus = 1;
    } else {
      global.bmpStatus = 0;
      Serial.println("BMP is not responding");
    }
  }
}

void TelemetryFiled::readBMP() {
  altAbs = bmp.readAltitude(global.groundPressure);
  tmpAir = bmp.readTemperature();
  airPressure = bmp.readPressure();
}


void TelemetryFiled::checkMPU() {
  if (temp.temperature!=0) {
    MPUvalid = true;
    global.mpuStatus = 1;
  } else {
    global.mpuStatus = 0;
    Serial.println("MPU is not responding");
  }
}

void TelemetryFiled::readMPU() {

  mpu.getEvent(&a, &g, &temp);

  accelX = a.acceleration.x;
  accelY = a.acceleration.y;
  accelZ = a.acceleration.z;

  gyroX = g.gyro.x;
  gyroY = g.gyro.y;
  gyroZ = g.gyro.z;
}

void TelemetryFiled::readTelemetry(){
  readBMP();
  readMPU();
}