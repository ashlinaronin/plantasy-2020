// trying to use the velleman vma409 motor driver to drive the dc brushless fan
// fan - DC 12V 1.5A, DFS923212MD0T

#define ROTARY_ANGLE_SENSOR 14
#define FULL_ANGLE 300 //full value of the rotary angle is 300 degrees
#define ADC_REF 5 //reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
//board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5 //VCC of the grove interface is normally 5v

// todo use #define?
int in1 = 11;
int in2 = 12;
int knobReadPin = 14;
int speedPinA = 6;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(speedPinA, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  //_mRight(in1, in2);
  int deg = getMappedDegrees();
  Serial.println(deg);
  
  _mSetSpeed(speedPinA, deg);
  delay(20);
}

void _mRight(int pin1, int pin2) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);  
}

void _mLeft(int pin1, int pin2) {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);  
}

void _mStop(int pin1, int pin2) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
}

void _mSetSpeed(int pinPWM, int speedValue) {
  analogWrite(pinPWM, speedValue);  
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
  int sensor_value = analogRead(knobReadPin);
  float voltage = (float)sensor_value * ADC_REF / 1023;
  return (voltage * FULL_ANGLE) / GROVE_VCC;
}
