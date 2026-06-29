#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>
#include "RF24.h"


//led definition
#define led_r 0
#define led_g 25
#define led_b 1
#define led_ring 2

//servo definition
#define servoPin 6

//addres definition
#define bmpAdress 0x76

//radio bus pins
#define CE 15
#define CSN 14

//default led blink time definition
#define statusDefaultBlinkTime 500


Adafruit_BMP280 bmp;   //bmp sensor
Adafruit_MPU6050 mpu;  //mpu sensor
Servo servo_motor;     //servo motor
RF24 radio(CE, CSN);   //radio communication

void statusLEDControl();

struct GlobalVariables {
  bool stopProgram = false, standby, fatalError = false;
  bool saveTelemetry = true, sendSerialTelemetry = true, sendRadioTelemetry = true;  //varialbles to set if telemetry is saved and send
  int flightStage;                                                                   //the stage of flight
  bool parachuteDeployed;                                                            //variable to determine if parachute was deployed
  bool mpuStatus, bmpStatus, radioStatus;                                            //status variables
  int arrayID;                                                                       //id for an array
  long unsigned messageID;
  float altRel0;                //alt 0, from this point relative alitude is calvulated
  float groundPressure = 1013;  //groud pressure
  String date, time;            //datre and time strings
};

class TelemetryFiled {
public:
  void readBMP();
  void checkBMP();
  void readMPU();
  void checkMPU();
  void readTelemetry();
  void convertTelemetryData();
  void writeSerialTelemetry();
private:
  int id;
  //basic varialbles
  float time;
  float altAbs, altRel;          //altitude
  float tmpAir, tmpCPU;          //temperatures
  float accelX, accelY, accelZ;  //acceleration
  float gyroX, gyroY, gyroZ;     //gyro
  float verSpeed;                //vertical speed
  float airPressure;             //air pressure
  bool BMPvalid, MPUvalid;       //variables to store if reading are valid
  sensors_event_t a, g, temp;    //mpu6050 sensorEvent
  String telemetryString;
};

GlobalVariables global;

TelemetryFiled *TelemetryArray = new TelemetryFiled[100];

void setup() {

  pinMode(led_r, OUTPUT);     //green led
  pinMode(led_g, OUTPUT);     //red led
  pinMode(led_b, OUTPUT);     //blue led
  pinMode(led_ring, OUTPUT);  //blue led
  delay(50);
  testComponents();
}

void loop() {

  if (global.arrayID == 100) global.arrayID = 0;  //reseting global array to not waste memory

  /*if (global.arrayID % 10 == 0) {

    TelemetryArray[global.arrayID].checkBMP();
    TelemetryArray[global.arrayID].checkMPU();
  }*/

  TelemetryArray[global.arrayID].readTelemetry();
  TelemetryArray[global.arrayID].convertTelemetryData();
  TelemetryArray[global.arrayID].writeSerialTelemetry();
  statusLEDControl();
  global.arrayID++;
  global.messageID++;
  ledBlink(0, 0, 'b', 10);
  delay(10);
}
