#include <Servo.h>
#include <IBusBM.h>

// Reading from receiver? https://medium.com/@werneckpaiva/how-to-read-rc-signal-with-arduino-using-flysky-ibus-73448bc924eb
// https://www.instructables.com/RC-Control-and-Arduino-A-Complete-Works/

// Outputting to Victors: https://github.com/FRC4014/SRTester/blob/master/SRTester.ino

int pwmLeft = 6;
int pwmRight = 5;
Servo controllers[2];
int vals[2];
int analogInR2 = A0;
int analogInL3 = A1;
int valL = 0;
int valR = 0;
int digitalInR2 = 9;
int digitalInL3 = 10;

void setup() {
    Serial.begin(115200);
    pinMode(pwmLeft, OUTPUT);
    pinMode(pwmRight, OUTPUT);
    pinMode(digitalInL3, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(digitalInR2, INPUT);
    controllers[0].attach(pwmLeft);
    controllers[1].attach(pwmRight);
    // Serial.println("T-minus 20 seconds");
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    // delay(20000);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
    Serial.println("------");
    vals[0] = pulseIn(digitalInL3, HIGH);
    vals[1] = pulseIn(digitalInR2, HIGH);
    Serial.println("Pin 7 right channel 2 "); Serial.println(valR);
    Serial.println("Pin 8 left channel 3 "); Serial.println(valL);
    Serial.println("------");
    for (int i = 0; i < 2; i++) {
      if (vals[i] > 1450 && vals[i] < 1550) {
        vals[i] = 1500;
      } 
      if (vals[i] > 1815) {
        vals[i] = 2000;
      }
      if (vals[i] < 1105) {
        vals[i] = 1000;
      }
      if (vals[i] > 1500) {
        controllers[i].write(ceil(vals[i]*1.1));
      }
      else {
        controllers[i].write(floor(vals[i]/1.1));
      }
    }
}
