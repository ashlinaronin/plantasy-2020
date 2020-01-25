int knobValue; 
int MOTOR_WRITE_PIN = 16;
int KNOB_READ_PIN = 14;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int knobValue = analogRead(KNOB_READ_PIN);

  // send value from knob over serial to processing
  Serial.println(knobValue);

  // write value from knob to motor control
  // analog writes are in range 0-255,
  // analog ins are in range 0-1023
  analogWrite(MOTOR_WRITE_PIN, knobValue /4);

  delay(100);
}
