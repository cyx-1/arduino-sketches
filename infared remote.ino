#include <IRremote.h>

const int RECV_PIN = 7;
boolean lightOn = false;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    irrecv.resume();
    if (results.value == 0xF7C03F) {
      Serial.println("You have pressed the ON button");
      lightOn = true;
    } else if (results.value == 0xF740BF) {
      Serial.println("You have pressed the OFF button");
      lightOn = false;
    }
  }

  if (lightOn) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
