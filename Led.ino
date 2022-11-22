#define PULSANTE1   11                          //definisce che il primo pulsante è sul pin 11
#define PULSANTE2   12                          //definisce che il secondo pulsante è sul pin 12
#define LED1        2                           //definisce che il primo LED è sul pin 2
#define LED2        3                           //definisce che il secondo LED è sul pin 3

bool varled1;                                   //crea una variabile di tipo booleano chiamata varled1
bool varled2;                                   //crea una variabile di tipo booleano chiamata varled2

void setup() {
    pinMode(LED1, OUTPUT);                      //imposta il pin LED1 su output
    pinMode(LED2, OUTPUT);                      //imposta il pin LED2 su output
    pinMode(PULSANTE1, INPUT);                  //imposta il pin PULSANTE1 su input
    pinMode(PULSANTE2, INPUT);                  //imposta il pin PULSANTE2 su input
    digitalWrite(LED1, LOW);                    //spegne LED1
    digitalWrite(LED2, LOW);                    //spegne LED2
}

void loop() {
if (digitalRead(PULSANTE1) == HIGH) {           //se PULSANTE1 viene premuto
    varled1 = !varled1;                         //imposta varled1 sul contrario di varled1
    delay(200);                                 //aspetta 0.2 secondi
}

if (varled1 == 1) {                             //se varled1 è uguale a 1
    digitalWrite(LED1, HIGH);                   //accendi LED1
}
else {                                          //se varled1 non è uguale a 1
    digitalWrite (LED1, LOW);                   //spegni LED1
}

if (digitalRead(PULSANTE2) == HIGH) {           //se PULSANTE2 viene premuto
    varled2 = !varled2;                         //imposta varled2 sul contrario di varled2
    delay(200);                                 //aspetta 0.2 secondi
}

if (varled2 == 1) {                             //se varled2 è uguale a 1
    digitalWrite(LED2, HIGH);                   //accendi LED2
}
else {                                          //se varled2 non è uguale a 1
    digitalWrite (LED2, LOW);                   //spegni LED2
}
}