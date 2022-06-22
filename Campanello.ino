#define BUZZ 12
#define BUTTON 11
#define LEDSORDI 13

void setup(){

  pinMode(BUZZ, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(LEDSORDI, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LEDSORDI, HIGH);
    tone(BUZZ, 587, 200);
    delay(600);
    tone(BUZZ, 466, 200);
    delay(600);
    tone(BUZZ, 523, 200);
    delay(600);
    tone(BUZZ, 349, 400);
    delay(500);
    tone(BUZZ, 349, 200);
    delay(600);
    tone(BUZZ, 523, 200);
    delay(600);
    tone(BUZZ, 587, 200);
    delay(600);
    tone(BUZZ, 466, 500);
    delay(500);
    digitalWrite(LEDSORDI, LOW);
  }
}