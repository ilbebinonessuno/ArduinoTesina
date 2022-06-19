#define buzz 2
#define button 3
#define light 13



void setup(){

  pinMode(buzz, OUTPUT);
  pinMode(button, INPUT);
  pinMode(light, OUTPUT);
}

void loop() {
  if (digitalRead(button) == HIGH) {
    digitalWrite(light, HIGH);
    tone(buzz, 587, 200);
    delay(600);
    tone(buzz, 466, 200);
    delay(600);
    tone(buzz, 523, 200);
    delay(600);
    tone(buzz, 349, 400);
    delay(500);
    tone(buzz, 349, 200);
    delay(600);
    tone(buzz, 523, 200);
    delay(600);
    tone(buzz, 587, 200);
    delay(600);
    tone(buzz, 466, 500);
    delay(500);
    digitalWrite(light, LOW);
  }
}