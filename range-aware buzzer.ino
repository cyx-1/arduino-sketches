const int triggerPin = 2, echoPin = 3, piezoPin = 8;
long duration, Distanceincm;


void setup() {
  Serial.begin(9600);          // setup a window to receive program output
  pinMode(triggerPin, OUTPUT); // set the arduino pin #2 as a pin used for sending signal as output
  pinMode(echoPin, INPUT);     // set the arduino pin #3 as a pin used for receiving signal as input
}

void loop() {
  // send a signal using ultra-sonic sensor and receive it
  digitalWrite(triggerPin, HIGH);                 // send an electronic signal of HIGH to the trigger pin
  delay(15);                                      // pause for 15 msecs
  digitalWrite(triggerPin, LOW);                  // send an electronic signal of LOW to the trigger pin
  duration = pulseIn(echoPin, HIGH);              // populate the variable duration with the input value recevied from echo pin

  
  Distanceincm = duration / 58;                   // divide the time it took for sound wave to travel by a constant (58), to convert into cm  
  Serial.print("Distance in cm = ");              // print a String to the serial window
  Serial.println(Distanceincm);                   // print the distance to the serial window
  if (Distanceincm < 20) {                        // if distance is less than 20, then do a constant beep at frequency 1500
    tone(piezoPin, 1500);
  } else if (Distanceincm < 40) {                 // if distance is more than 20, but less than 40, then do a beep at frequency 1500, and duration of 100 msecs
    tone(piezoPin, 1500, 100);
  } else if (Distanceincm < 70) {                 // if distance is more than 40, but less than 70, then do a beep at frequency 1000, and duration of 100 msecs
    tone(piezoPin, 1000, 100);
  } else {
    noTone(piezoPin);                             // OTHER WISE--NO TONE
  }
  delay(500);                                     // Pause for 500 msecs
}
