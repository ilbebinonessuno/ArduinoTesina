#include <SoftwareSerial.h>

#define SOFTRX    10
#define SOFTTX    11
#define SERIALLED LED_BUILTIN

SoftwareSerial seriale2(SOFTRX, SOFTTX);

void setup() {
    pinMode(SOFTRX, INPUT);
    pinMode(SOFTTX, OUTPUT);
    pinMode(SERIALLED, OUTPUT);
    delay(2000);
   
    Serial.begin(9600);
    digitalWrite(SERIALLED, HIGH);
    delay(200);
    digitalWrite(SERIALLED, LOW);
    delay(400);
    digitalWrite(SERIALLED, HIGH);
    delay(200);
    digitalWrite(SERIALLED, LOW);

    seriale2.begin(9600);
    delay(1000);
}

void loop() {
    if (seriale2.available()) {
        Serial.write(seriale2.read());
    }
}