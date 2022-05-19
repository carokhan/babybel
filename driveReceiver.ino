#include <Servo.h>
#include <IBusBM.h>
// int pwmLeft = 5;
// int pwmRight = 6;
// int pwm = 2000;

// Reading from receiver? https://medium.com/@werneckpaiva/how-to-read-rc-signal-with-arduino-using-flysky-ibus-73448bc924eb
// https://www.instructables.com/RC-Control-and-Arduino-A-Complete-Works/

// Outputting to Victors: https://github.com/FRC4014/SRTester/blob/master/SRTester.ino

// IBusBM ibus;
int pwmPins[] = {5, 6};
Servo controllers[2];
int analogInR2 = A0;
int analogInL3 = A1;
int valL = 0;
int valR = 0;
// HardwareSerial& ibusRcSerial = Serial1;
// HardwareSerial& debugSerial = Serial;
int digitalInR2 = 9;
int digitalInL3 = 10;

int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
//   return map(ch, 1000, 2000, minLimit, maxLimit);
  int good = 100;
  return good;
}
 
// Read the channel and return a boolean value
// bool readSwitch(byte channelInput, bool defaultValue) {
//   int intDefaultValue = (defaultValue) ? 100 : 0;
//   int ch = readChannel(channelInput, 0, 100, intDefaultValue);
//   return (ch > 50);
// }

void setup() {
    // pinMode(pwmLeft, OUTPUT);
    // pinMode(pwmRight, OUTPUT);
    Serial.begin(115200);
    // Serial.println("Hi");
    pinMode(pwmPins, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(digitalInL3, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(digitalInR2, INPUT);
    for (int i=0; i<2; i++) {
        controllers[i].attach(pwmPins[i]);
    }
    ibus.begin(Serial);
    // Serial.println("Test");
    // debugSerial.begin(115200);
    // ibusRc.begin(ibusRcSerial);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("------");
    Serial.println("Test");
    valL = pulseIn(digitalInL3, HIGH);
    valR = pulseIn(digitalInR2, HIGH);
    // Serial.println("----------------");
    Serial.println("Pin 7 right channel 2 "); Serial.println(valR);
    Serial.println("Pin 8 left channel 3 "); Serial.println(valL);
    // Serial.println("----------------");
    // int valL = readChannel(digitalInL3, -100, 100, 0);
    // uint16_t chL = ibus.readChannel(digitalInL3);
    // Serial.println("Ch 3 - left "); Serial.println(valL);
    // int valR = readChannel(digitalInR2, -100, 100, 0);
    // uint16_t chR = ibus.readChannel(digitalInR2);
    // Serial.println("Ch 2 - right "); Serial.println(valR);
    Serial.println("------");
    // digitalWrite(LED_BUILTIN, HIGH);
    // for (int i = 0; i < 2; i++) {
    //     controllers[i].writeMicroseconds(pwm);
    // }
    // delay(500);
    // for (int i = 0; i < 2; i++) {
    //     controllers[i].writeMicroseconds(100);
    // }
}
