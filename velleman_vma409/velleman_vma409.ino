// trying to use the velleman vma409 motor driver to drive the dc brushless fan
// fan - DC 12V 1.5A, DFS923212MD0T

#define FULL_ANGLE 300 // full value of the rotary encoder is 300 degrees
#define ADC_REF 5 // reference voltage of ADC is 5v
#define GROVE_VCC 5 // VCC of the grove interface is normally 5v

#define KNOB_READ_PIN 14 // read the value from the knob
#define FAN_SPEED_PIN 6 // pwm output to the motor driver (ENA) speed input

void setup() {
  pinMode(KNOB_READ_PIN, INPUT);
  pinMode(FAN_SPEED_PIN, OUTPUT);
}

void loop() {
  int deg = getDegrees();
  Serial.println(deg);
  
  setFanSpeed(deg);
  delay(250);
}


void setFanSpeed(int speed) {
  analogWrite(FAN_SPEED_PIN, speed);  
}

int getMappedDegrees() {
  return map(getDegrees(), 0, FULL_ANGLE, 0, 255);
}


/************************************************************************/
/* Function: Get the angle between the mark and the starting position   */
/* Parameter: void                                                      */
/* Return: int, the range of degrees is 0~300                           */
int getDegrees()
{
  int sensor_value = analogRead(KNOB_READ_PIN);
  float voltage = (float)sensor_value * ADC_REF / 1023;
  return (voltage * FULL_ANGLE) / GROVE_VCC;
}
