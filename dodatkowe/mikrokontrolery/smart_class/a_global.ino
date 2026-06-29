#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

//funkcje

void checkDeviceStatus();

//klasy

class telemetryArray;

struct variables {
  bool checkFirstTime = true;
  int arrayIndex = 0;
  long unsigned telemetryID;
  int timeDelay = 100;  //co ile ms ma być wysyłana paczka
  float dataSendFrecurency = 1000 / (float)timeDelay;
  bool sendTelemetry = false, saveTelemetry = false, sendReadableTelemetry = false;
  float timeFromLauch;
  float alt0, distanceToLaunchpad;
  unsigned deviceStatus[2];  //0-SD status, 1-BMP280 status
  File telemetryFile;
  Adafruit_BMP280 bmp;
  String telemetryFilePath = "fdata.txt";
  int flightState = 1;

  float flightStartTime;
  float flightTime[2];

  float flightAltitude[2];
};

variables global;

void serialSend(telemetryArray data);
void sampleTelemetry(telemetryArray data);


class telemetryArray {
public:

  float timeFromLaunch, altitude, relAltitude, velocity, distanceInTime, distanceToLaunchpad, pressure, temperature, checksum;
  int state;
  byte packageType;
  long unsigned packageID;
  unsigned deviceStatusInTime[2];

  float deltaTime, deltaAltitude;
  String data;

  void sampleData();

  void createTelemetryPackage();

  void telemetryWrite();
};

telemetryArray telemetryDataArray[100];
