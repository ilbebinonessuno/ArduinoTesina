#define PULSANTE1   11                          //Definsce il primo pulsante per l'illuminazione della zona giorno
#define PULSANTE2   12                          //Definsce il secondo pulsante per l'illuminazione della zona notte
#define LED1        2                           //Definsce i LED della zona giorno
#define LED2        3                           //Definsce i LED della zona notte

bool LED1;
bool LED2;

void setup() {
    pinMode(LED1, OUTPUT);                      //Imposta il pin di LED1 su OUTPUT 
    pinMode(LED2, OUTPUT);                      //Imposta il pin di LED2 su OUTPUT
    pinMode(PULSANTE1, INPUT);                  //Imposta il pin di PULSANTE1 su INPUT
    pinMode(PULSANTE2, INPUT);                  //Imposta il pin di PULSANTE2 INPUT
    LED1 = 0;                                   //Imposta la variabile LED1 a 0
    LED2 = 0;                                   //Imposta la variabile LED2 a 0
    digitalWrite(LED1, LOW);                    //Spegne LED1
    digitalWrite(LED2, LOW);                    //Spegne LED2
}

void loop() {
    if (digitalRead(PULSANTE1) == HIGH) {       //Se PULSANTE1 viene premuto imposta variabile LED1 sul contrario della variabile LED1
        varled1 = !varled1;
        delay(200);
    }

    if (varled1 == 1) {                         //Se la variabile LED1 è vera accendi LED1
        digitalWrite(LED1, HIGH);
    }
    else {                                      //Se la variabile LED1 non è vera spengi LED1
        digitalWrite (LED1, LOW);
    }

    if (digitalRead(PULSANTE2) == HIGH) {       //Se PULSANTE2 viene premuto imposta variabile LED2 sul contrario della variabile LED2
        varled2 = !varled2;
        delay(200);
    }

    if (varled2 == 1) {                         //Se la variabile LED2 è vera accendi LED2
        digitalWrite(LED2, HIGH);
    }
    else {                                      //Se la variabile LED2 è vera accendi LED2
        digitalWrite (LED2, LOW);
    }
}
