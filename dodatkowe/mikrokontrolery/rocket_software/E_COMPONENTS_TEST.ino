void testComponents() {
  int b = statusDefaultBlinkTime;
  Serial.begin(9600);


  ledBlink("rgb", 5000);  //wait to intialize serial communication

  bool bmpStatus, mpuStatus, radioStatus, servoStatus;
  Serial.println(" ");
  Serial.println("##################################");
  Serial.println("Initializing components...");

  //Testting bmp
  Serial.print("BMP280: ");
  bmpStatus = bmp.begin(bmpAdress);
  global.bmpStatus = bmpStatus;
  ledBlinkTest();
  if (bmpStatus == 0) {
    Serial.println("Not active");
    ledBlinkTestError(b);
  } else {
    Serial.println("Active");
    ledBlinkTestGood(b);
  }
  delay(200);


  //testting mpu
  Serial.print("MPU6050: ");
  mpuStatus = mpu.begin();
  global.mpuStatus = mpuStatus;
  ledBlinkTest();
  if (mpuStatus == 0) {
    Serial.println("Not active");
    ledBlinkTestError(b);
  } else {
    Serial.println("Active");
    ledBlinkTestGood(b);
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  }
  delay(200);

  //testing radio
  Serial.print("RADIO: ");
  radioStatus = radio.begin();
  global.radioStatus = radioStatus;
  ledBlinkTest();
  if (radioStatus == 0) {
    Serial.println("Not active");
    ledBlinkTestError(b);
  } else {
    Serial.println("Active");
    ledBlinkTestGood(b);
  }
  delay(200);


  //testting servo
  Serial.println("Servo: TESTING");
  servo_motor.attach(servoPin);
  delay(100);
  for (int i = 0; i < 180; i++) {
    servo_motor.write(i);
    delay(15);
  }
  servo_motor.write(0);
}
