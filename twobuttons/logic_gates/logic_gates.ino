const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int ledPin = 13;

int buttonState1=0;
int buttonState2=0;
// add analog switcher (potentiometer)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);  
  // setup analog switcher
}

void ANDgate (boolean a, boolean b) { 
  if (a == HIGH && b == HIGH) {
    // button 1 pressed, button 2 pressed
    digitalWrite(ledPin, HIGH);
  } else if (a == HIGH && b == LOW) {
    // button 1 pressed, button 2 free
    digitalWrite(ledPin, LOW);
  } else if (a == LOW && b == HIGH) {
    // button 1 free, button 2 pressed
    digitalWrite(ledPin, LOW);
  } else {
    // button 1 free, button 2 free
    digitalWrite(ledPin, LOW);
  }
}

void ORgate (boolean a, boolean b) {
  if (a == HIGH && b == HIGH) {
    // button 1 pressed, button 2 pressed
    digitalWrite(ledPin, HIGH);
  } else if (a == HIGH && b == LOW) {
    // button 1 pressed, button 2 free
    digitalWrite(ledPin, HIGH);
  } else if (a == LOW && b == HIGH) {
    // button 1 free, button 2 pressed
    digitalWrite(ledPin, HIGH);
  } else {
    // button 1 free, button 2 free
    digitalWrite(ledPin, LOW);
  }
}

// invertor
void NOTgate (boolean a, boolean b) {
  if ( a == HIGH ) {
    digitalWrite(ledPin,LOW);
  }
  if (b == HIGH) {
    digitalWrite(ledPin,LOW);
  }
}

void NANDgate (boolean a, boolean b) {
  if (a == HIGH && b == HIGH) {
    // button 1 pressed, button 2 pressed
    digitalWrite(ledPin, LOW);
  } else if (a == HIGH && b == LOW) {
    // button 1 pressed, button 2 free
    digitalWrite(ledPin, HIGH);
  } else if (a == LOW && b == HIGH) {
    // button 1 free, button 2 pressed
    digitalWrite(ledPin, HIGH);
  } else {
    // button 1 free, button 2 free
    digitalWrite(ledPin, HIGH);
  }
}

void NORgate (boolean a, boolean b) {
  if (a == HIGH && b == HIGH) {
    // button 1 pressed, button 2 pressed
    digitalWrite(ledPin, LOW);
  } else if (a == HIGH && b == LOW) {
    // button 1 pressed, button 2 free
    digitalWrite(ledPin, LOW);
  } else if (a == LOW && b == HIGH) {
    // button 1 free, button 2 pressed
    digitalWrite(ledPin, LOW);
  } else {
    // button 1 free, button 2 free
    digitalWrite(ledPin, HIGH);
  }
}

void XORgate (boolean a, boolean b) {
  if (a == HIGH && b == HIGH) {
    // button 1 pressed, button 2 pressed
    digitalWrite(ledPin, LOW);
  } else if (a == HIGH && b == LOW) {
    // button 1 pressed, button 2 free
    digitalWrite(ledPin, HIGH);
  } else if (a == LOW && b == HIGH) {
    // button 1 free, button 2 pressed
    digitalWrite(ledPin, HIGH);
  } else {
    // button 1 free, button 2 free
    digitalWrite(ledPin, LOW);
  }
}

void XNORgate (boolean a, boolean b) {
  if (a == HIGH && b == HIGH) {
    // button 1 pressed, button 2 pressed
    digitalWrite(ledPin, HIGH);
  } else if (a == HIGH && b == LOW) {
    // button 1 pressed, button 2 free
    digitalWrite(ledPin, LOW);
  } else if (a == LOW && b == HIGH) {
    // button 1 free, button 2 pressed
    digitalWrite(ledPin, LOW);
  } else {
    // button 1 free, button 2 free
    digitalWrite(ledPin, HIGH);
  }
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // read analog switcher  

  ANDgate(buttonState1, buttonState2);
  ORgate(buttonState1, buttonState2);
  NOTgate(buttonState1, buttonState2);
  NANDgate(buttonState1, buttonState2);
  NORgate(buttonState1, buttonState2);
  XORgate(buttonState1, buttonState2);
  XNORgate(buttonState1, buttonState2);
}
