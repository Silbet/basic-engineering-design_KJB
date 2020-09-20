
#define PIN_LED 7 
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200); // Initialize serial port
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  Serial.println("Hello World!");
  count = toggle = 0;
  digitalWrite(PIN_LED, toggle); // turn on LED.
}

void loop() {
  Serial.println(++count);
  delay(1000); // wait for 1,000 milliseconds
  for (int i = 0; i <= 5; i++) {
    digitalWrite(PIN_LED, 0);
    delay(100);
    digitalWrite(PIN_LED, 1);
    delay(100);
  }
  
  while(1); // infinite loop
}
