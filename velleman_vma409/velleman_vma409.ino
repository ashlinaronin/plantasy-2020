// trying to use the velleman vma409 motor driver to drive the dc brushless fan
// fan - DC 12V 1.5A, DFS923212MD0T


int in1 = 11;
int in2 = 12;
//int in3 = 22;
//int in4 = 23;

int speedPinA = 6;
int speedPinB = 5;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //pinMode(in3, OUTPUT);
  //pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  //digitalWrite(in3, HIGH);
  //digitalWrite(in4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  _mRight(in1, in2);
  //_mRight(in3, in4);

  _mSetSpeed(

  //int n = analogRead(14) / 4;
  //_mSetSpeed(speedPinA, n);
  //_mSetSpeed(speedPinB, n);
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
