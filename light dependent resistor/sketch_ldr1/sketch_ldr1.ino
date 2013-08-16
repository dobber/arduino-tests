const int ledPin = 13;    // LED connected to pin digital pin 13
const int sensorPin = 0;  // LDR sensor to A0

const int minDuration = 100;  // minimum wait between blinks
const int maxDuration = 1000;  // maximum wait between blinks

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); // enable output of the led pin
}

void loop() {
  // put your main code here, to run repeatedly: 
  int rate = analogRead(sensorPin);  // read the analog input
  // the next line scales the blink rate between the min and max values
  rate = map(rate, 200, 800, minDuration, maxDuration);  // convert the blink rate
  rate = constrain(rate, minDuration, maxDuration);  // constrain the value
  digitalWrite(ledPin,HIGH);  // set the LED on
  delay(rate);  // wait duration dependant on the light level
  digitalWrite(ledPin,LOW);  // set the LED off
  delay(rate);  
}
