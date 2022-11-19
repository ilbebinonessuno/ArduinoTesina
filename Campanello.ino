#define BUZZ 12                             //Definisce il buzz sul pin 12
#define BUTTON 11                           //Definisce il pulsante sul pin 11
#define LEDSORDI 13                         //Definisce il led sul pin 13

void setup(){

  pinMode(BUZZ, OUTPUT);                    //Definisce il buzz su come OUTPUT
  pinMode(BUTTON, INPUT);                   //Definisce il pulsante su come INPUT
  pinMode(LEDSORDI, OUTPUT);                //Definisce il LED su come OUTPUT
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {        //Se il pulsante viene premuto il buzz riproduce il suono del campanello e fa lampeggiare il led 
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
