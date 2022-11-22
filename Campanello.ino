#define BUZZ 12                       //definisce che il buzz è sul pin 12 
#define BUTTON 11                     //definisce che il bottone è sul pin 11 
#define LEDSORDI 13                   //definisce che il led è sul pin 13

void setup(){
  pinMode(BUZZ, OUTPUT);              //imposta il pin BUZZ su output
  pinMode(BUTTON, INPUT);             //imposta il pin BUTTON su input
  pinMode(LEDSORDI, OUTPUT);          //imposta il pin LEDSORDI su output
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {  //se il pulsante è premuto
    digitalWrite(LEDSORDI, HIGH);     //accende il led
    tone(BUZZ, 587, 200);             //riproduce dei suoni con il buzz
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
    digitalWrite(LEDSORDI, LOW);      //spegne il led
  }
}