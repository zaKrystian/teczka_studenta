
void ledBlink(char r, char g, char b, int time) {

  if (r == 'r') digitalWrite(led_r, HIGH);
  if (g == 'g') digitalWrite(led_g, HIGH);
  if (b == 'b') digitalWrite(led_b, HIGH);

  delay(time);

  if (r == 'r') digitalWrite(led_r, LOW);
  if (g == 'g') digitalWrite(led_g, LOW);
  if (b == 'b') digitalWrite(led_b, LOW);
}

void ledBlink(String colors, int time) {
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, HIGH);

  delay(time);

  digitalWrite(led_r, LOW);
  digitalWrite(led_g, LOW);
  digitalWrite(led_b, LOW);
}

void ledBlinkTest() {
  delay(100);
  ledBlink(0, 0, 'b', 200);
}

void ledBlinkTestGood(int b) {
  ledBlink(0, 'g', 0, b);
}

void ledBlinkTestError(int b) {
  ledBlink('r', 0, 0, b);
}

void ledON(char color) {
  if (color == 'r') digitalWrite(led_r, HIGH);
  if (color == 'g') digitalWrite(led_g, HIGH);
  if (color == 'b') digitalWrite(led_b, HIGH);
}

void ledON(String all) {
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, HIGH);
}

void ledOFF(char color) {
  if (color == 'r') digitalWrite(led_r, LOW);
  if (color == 'g') digitalWrite(led_g, LOW);
  if (color == 'b') digitalWrite(led_b, LOW);
}

void ledOFF(String all) {
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, HIGH);
}
