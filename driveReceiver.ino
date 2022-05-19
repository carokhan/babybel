#include <Servo.h>
#include <IBusBM.h>
// int pwmLeft = 5;
// int pwmRight = 6;
// int pwm = 2000;

// Reading from receiver? https://medium.com/@werneckpaiva/how-to-read-rc-signal-with-arduino-using-flysky-ibus-73448bc924eb
// Outputting to Victors: https://github.com/FRC4014/SRTester/blob/master/SRTester.ino

IBusBM ibusRc;
int pwmPins[] = {5, 6};
int leftIn = 3;
int rightIn = 2;
Servo controllers[2];
int pingPin = 7;
int analogInR2 = A0;
int analogInL3 = A1;
int valL = 0;
int valR = 0;

void setup() {
    // pinMode(pwmLeft, OUTPUT);
    // pinMode(pwmRight, OUTPUT);
    pinMode(pwmPins, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    for (int i=0; i<2; i++) {
        controllers[i].attach(pwmPins[i]);
    }
    Serial.begin(115200);   
}

void loop() {
    Serial.println("Test");
    valL = analogRead(analogInL3);
    valR = analogRead(analogInR2);
    Serial.println("----------------");
    Serial.println("Left "); Serial.println(valL);
    Serial.println("Right "); Serial.println(valR);
    Serial.println("----------------");
    // digitalWrite(LED_BUILTIN, HIGH);
    // for (int i = 0; i < 2; i++) {
    //     controllers[i].writeMicroseconds(pwm);
    // }
    // delay(500);
    // for (int i = 0; i < 2; i++) {
    //     controllers[i].writeMicroseconds(100);
    // }
}
