// initial state of a button
volatile int state = LOW;

// dancing leds
byte ledArray[] = {8, 9, 10, 11, 12};
const int num_leds = (sizeof(ledArray) / sizeof(byte));

int count = 0; // a simple for (count)

// start/stop leds
int ledState=LOW;  // led state of stopLed
int stopLed=6; // red
int goLed=7; // green

// timer for blink
int danceTimer = 75;
int blinkTimer = 250;
unsigned long start_time;
static unsigned long current_time = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize leds
  for (count = 0; count < num_leds; count++) {
    pinMode(ledArray[count], OUTPUT);
  }

  // initialize stop/go leds
  pinMode(stopLed, OUTPUT);
  pinMode(goLed, OUTPUT);

  // initialize the button
  attachInterrupt(0, ledOnOff, RISING);
}

void loop() {
  // put your main code here, to run repeatedly: 

  // state power off
  // only red led should blink
  if (state == LOW) {
    // goLed should be off
    digitalWrite(goLed, LOW);
    
    // blink the red led
    ledState = blinkLed(ledState, stopLed);
    // dancing leds are off now
    for (count = 0; count < num_leds; count++) {
      digitalWrite(ledArray[count], LOW);
    }
  }
  // state power on
  // blink green led, dance all leds
  if (state == HIGH) {
    // stopLed should be off
    digitalWrite(stopLed, LOW);
    
    // blink the green led
    ledState = blinkLed(ledState, goLed);
    
    // start dancing the leds
    for (count = 0; count < num_leds; count++) {
      digitalWrite(ledArray[count], HIGH);
      delay(danceTimer);
    }
    for (count = 0; count < num_leds; count++) {
      digitalWrite(ledArray[count], LOW);
      delay(danceTimer);
    }
    // to fix the blink
    // da izkaram start_time=millis() izvun blinkLed function-a.
    // moje bi da go napravq persistent?
    // da promenq for (count=0 na if () esle (), taka che pri
    // vseki loop da proverqva samo edin ot ledovete
  }
}

// takes stop or go led and a state. blink
int blinkLed (int ledState, int ledNum) {
  // blink the led
  start_time = millis();
  if (start_time - current_time > blinkTimer) {
    current_time = start_time;
    if (ledState == LOW) {
      ledState=HIGH;
    } else {
      ledState=LOW;
    }
    digitalWrite(ledNum, ledState);
  }
  return ledState;
}

// initialize the button. change the state
void ledOnOff() {
  start_time = millis();
  if (start_time - current_time < 50) {
  } else {
    state=!state;
    current_time = start_time;
  }
}
