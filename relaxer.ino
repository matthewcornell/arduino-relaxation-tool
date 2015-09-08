/*
 * Vibrating relaxer.
 * o two pots control tick duration and period
 * o one cycle LED that alternates state with each tick
 
 Enhancements:
 o use the map function to simplify calcuations: http://arduino.cc/en/reference/map

 Copyright 2015 Matthew Cornell
 */

// I/O pins
const int cycleLedPin = 13;     // toggles with each tick

const int pot1Pin = A0;         // duration pot
const int pot2Pin = A1;         // period pot
const int motor1Pin = 2;        // vibration motor transistor
const int motor2Pin = 3;        // ""

// LED state vars
boolean isCycleLedOn = false;   // whether LED is on or not. used by toggleCycleLed()

// tick vars
int vibePeriod = 0;         // how often the motor vibrates in ms: a range ~ [100 ms, 2000 ms]. set by adjustPeriodAndDurationBasedOnPots()
int vibeDuration = 500;     // how long the motor vibrates in ms: ""


void setup() {
    pinMode(cycleLedPin, OUTPUT);
    pinMode(motor1Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    adjustPeriodAndDurationBasedOnPots();
    cycleMotor(motor1Pin);

    adjustPeriodAndDurationBasedOnPots();
    cycleMotor(motor2Pin);
}

void cycleMotor(int motorPin) {
    // start vibration period, leaving on for duration pulse
    digitalWrite(motorPin, HIGH);
    toggleCycleLed();
    delay(vibeDuration);
  
    // stop vibrating, leaving off for remainder of period
    digitalWrite(motorPin, LOW);
    toggleCycleLed();
    int remainingDelay = vibePeriod - vibeDuration;
    delay(max(remainingDelay, vibeDuration));     // max ensures duration <= period. that case means the motor is always on
}

void adjustPeriodAndDurationBasedOnPots() {
    int periodValue = analogRead(pot1Pin);           // interval [0, 1023]
    int durationValue = analogRead(pot2Pin);         // ""
    int period = (1.8573 * periodValue) + 100;       // line equation to convert above to ~ [100 ms, 2000 ms]
    int duration = (1.8573 * durationValue) + 100;   // ""
    
    Serial.print("period: ");   Serial.print(periodValue);   Serial.print(", "); Serial.println(period);
    Serial.print("duration: "); Serial.print(durationValue); Serial.print(", "); Serial.println(duration);
    vibePeriod = period;
    vibeDuration = duration;
}

boolean toggleCycleLed() {
    isCycleLedOn = !isCycleLedOn;
    digitalWrite(cycleLedPin, isCycleLedOn);
}

