void readCommand(){
  String line;
  line=Serial.readString();
  //Serial.println(line);
  String command, parametr;
 
  command = line.substring(0, 3);
  parametr = line.substring(4, 7);

  //Serial.println(command);
  //Serial.println(parametr);
}