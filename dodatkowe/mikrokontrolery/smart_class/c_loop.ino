void loop() {
  if (global.arrayIndex == 100) {
    global.arrayIndex = 0;
  }
  
 if(Serial.available()>0){
   readCommand();
 }
  
  Serial.println(global.arrayIndex);
  telemetryDataArray[global.arrayIndex].sampleData();
  telemetryDataArray[global.arrayIndex].createTelemetryPackage();
  telemetryDataArray[global.arrayIndex].telemetryWrite();


  global.arrayIndex++;
  global.telemetryID++;
  delay(100);
}