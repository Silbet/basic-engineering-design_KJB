// Arduino pin assignment
#include <Servo.h>
#define PIN_SERVO 10
#define PIN_IR A0

Servo myservo;
int a, b; // unit: mm

void setup() {
// initialize serial port
  myservo.attach(PIN_SERVO);
  Serial.begin(57600);
  a = 90;
  b = 280;
}
float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  return val;
}
void loop() {
  float raw_dist = ir_distance();
  float dist_cali = 100 + 300.0 / (b - a) * (raw_dist - a);
  if (dist_cali >= 300) {
    myservo.writeMicroseconds(1230);
  }
  else {
    myservo.writeMicroseconds(1630);
  }
}
