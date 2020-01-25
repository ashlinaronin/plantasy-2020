/*macro definitions of Rotary angle sensor and LED pin*/
/* borrowed from https://github.com/Seeed-Studio/Rotary_Angle_Sensor/blob/master/examples/ControlLEDBrightness/ControlLEDBrightness.ino */
#define ROTARY_ANGLE_SENSOR A0
#define LED 3 //the Grove - LED is connected to D3 of Arduino
#define ADC_REF 5 //reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
//board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5 //VCC of the grove interface is normally 5v
#define FULL_ANGLE 300 //full value of the rotary angle is 300 degrees

#define MOTOR_WRITE_PIN 16
#define KNOB_READ_PIN 14

int knobValue;
int degrees;
int speed;

void setup() {
  Serial.begin(9600);
  pinMode(KNOB_READ_PIN, INPUT);
  pinMode(MOTOR_WRITE_PIN, OUTPUT);
}

void loop() {
  degrees = getDegrees();

  // map to output range
  speed = map(degrees, 0, FULL_ANGLE, 0, 255);
  controlFan(speed);

  // send value from knob over serial to processing
  Serial.println(speed);

  delay(250);
}

void controlFan(int speed) {
  analogWrite(MOTOR_WRITE_PIN, speed);  
}

/************************************************************************/
/* Function: Get the angle between the mark and the starting position   */
/* Parameter: void                                                      */
/* Return: int, the range of degrees is 0~300                           */
int getDegrees()
{
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  float voltage = (float)sensor_value * ADC_REF / 1023;
  return (voltage * FULL_ANGLE) / GROVE_VCC;
}
