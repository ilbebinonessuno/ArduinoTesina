#define TRIGGERPORT 2                                                                                           //Definisce che il pin trigger del sensore a ultra è sul pin 2
#define ECHOPORT    3                                                                                           //Definisce che il pin echo del sensore a ultra suoni è sul pin 3
#define BUZZ        4                                                                                           //Definisce che il buzz è sul pin 4
#define BOTTONE1    5                                                                                           //Definisce che il primo bottone per inserire il pin dell'allarme è sul pin 5
#define BOTTONE2    6                                                                                           //Definisce che il secondo bottone per inserire il pin dell'allarme è sul pin 6
#define LEDCONFERMA 7                                                                                           //Definisce che il LED della conferma dell'inserimento del carattere è sul pin 7

bool stato;                                                                                                     //crea una variabile di tipo booleano chiamata stato
bool carattere1;                                                                                                //crea una variabile di tipo booleano chiamata carattere1
bool carattere2;                                                                                                //crea una variabile di tipo booleano chiamata carattere2
bool carattere3;                                                                                                //crea una variabile di tipo booleano chiamata carattere3
bool carattere4;                                                                                                //crea una variabile di tipo booleano chiamata carattere4
int caratteriIn;                                                                                                //crea una variabile di tipo booleano chiamata caratteriIn

void setup() {                                  
    pinMode(TRIGGERPORT, OUTPUT);                                                                               //imposta il pin TRIGGERPORT su output
    pinMode(ECHOPORT,    INPUT);                                                                                //imposta il pin ECHOPORT su input
    pinMode(BUZZ,        OUTPUT);                                                                               //imposta il pin BUZZ su output
    pinMode(BOTTONE1,    INPUT);                                                                                //imposta il pin BOTTONE1 su input
    pinMode(BOTTONE2,    INPUT);                                                                                //imposta il pin BOTTONE2 su input
    pinMode(LEDCONFERMA, OUTPUT);                                                                               //imposta il pin LEDCONFERMA su output
    Serial.begin(9600);                                                                                         //imposta la porta seriale su 9600 bauld
    stato = false;                                                                                              //imposta la variabile stato su falso
    caratteriIn = 0;                                                                                            //imposta la variabile caratteriIn su 0
    digitalWrite(LEDCONFERMA, HIGH);                                                                            //accende LEDCONFERMA
}

void loop() {                                   
    digitalWrite(TRIGGERPORT, LOW);                                                                             //non da segnale sulla porta TRIGGERPORT
    digitalWrite(TRIGGERPORT, HIGH);                                                                            //da segnale sulla porta TRIGGERPORT
    delayMicroseconds(10);                                                                                      //aspetta 10 microsecondi
    digitalWrite(TRIGGERPORT, LOW);                                                                             //non da segnale sulla porta TRIGGERPORT

    long durata     = pulseIn(ECHOPORT, HIGH);                                                                  //conta quanto tempo impiega il suono a tornare al sensore
    long distanza   = 0.034 * durata / 2;                                                                       //calcola quanti cm ha fatto il suono
    //Serial.print  ("distanza: ");                                                                             scommentare se si vuole leggere la distanza percorsa dal suono sul monitor seriale
    //Serial.print  (distanza);                                                                                 scommentare se si vuole leggere la distanza percorsa dal suono sul monitor seriale
    //Serial.println(" cm        ");                                                                            scommentare se si vuole leggere la distanza percorsa dal suono sul monitor seriale
    delay(200);                                                                                                 //aspetta 0.2 secondi

    if (distanza <= 15 && stato == true) {                                                                      //se la distanza è minore di 15 cm fai zuonare il BUZZ
        tone(BUZZ, 466, 500);
    }

    if (digitalRead(BOTTONE1) == HIGH && digitalRead(BOTTONE2) == HIGH) {                                       //se entrambi i pulsanti vengono premuti

        if (stato == true) {                                                                                    //se stato è uguale a vero resetta i caratteri immessi
            caratteriIn = 0;
        }

        else {                                                                                                  //se no imposta stato su vero e spegni LEDCONFERMA
            stato = true;
            digitalWrite(LEDCONFERMA, LOW);
        }
        delay(500);                                                                                             //fa un suono con il buzz
        tone(BUZZ, 466, 200);
        delay(200);
        tone(BUZZ, 466, 200);
    }  

    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 0) {                                                    //se viene premuto il primo bottone e i caratteri immessi sono 0
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere1 = 0;                                                                                         //imposta il primo carattere su 0
        caratteriIn = 1;                                                                                        //imposta i caratteri immessi su 1
        Serial.println("0");                                                                                    //scrivi 0 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 0) {                                                    //se viene premuto il secondo bottone e i caratteri immessi sono 0
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere1 = 1;                                                                                         //imposta il primo carattere su 1
        caratteriIn = 1;                                                                                        //imposta i caratteri immessi su 1
        Serial.println("1");                                                                                    //scrivi 1 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }

    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 1) {                                                    //se viene premuto il primo bottone e i caratteri immessi sono 1
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere2 = 0;                                                                                         //imposta il secondo carattere su 0
        caratteriIn = 2;                                                                                        //imposta i caratteri immessi su 2
        Serial.println("0");                                                                                    //scrivi 0 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 1) {                                                    //se viene premuto il secondo bottone e i caratteri immessi sono 1
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere2 = 1;                                                                                         //imposta il secondo carattere su 1
        caratteriIn = 2;                                                                                        //imposta i caratteri immessi su 2
        Serial.println("1");                                                                                    //scrivi 1 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }


    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 2) {                                                    //se viene premuto il primo bottone e i caratteri immessi sono 2
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere3 = 0;                                                                                         //imposta il terzo carattere su 0
        caratteriIn = 3;                                                                                        //imposta i caratteri immessi su 3
        Serial.println("0");                                                                                    //scrivi 0 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 2) {                                                    //se viene premuto il secondo bottone e i caratteri immessi sono 2
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere3 = 1;                                                                                         //imposta il terzo carattere su 1
        caratteriIn = 3;                                                                                        //imposta i caratteri immessi su 3
        Serial.println("1");                                                                                    //scrivi 1 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }

    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 3) {                                                    //se viene premuto il primo bottone e i caratteri immessi sono 3
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere4 = 0;                                                                                         //imposta il quarto carattere su 0
        caratteriIn = 4;                                                                                        //imposta i caratteri immessi su 4
        Serial.println("0");                                                                                    //scrivi 0 sulla porta seriale
        delay(200);                                                                                             //aspetta 0.2 secondi
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 3) {                                                    //se viene premuto il secondo bottone e i caratteri immessi sono 3
        digitalWrite(LEDCONFERMA, HIGH);                                                                        //accendi il led di conferma
        carattere4 = 1;                                                                                         //imposta il quarto carattere su 1
        caratteriIn = 4;                                                                                        //imposta i caratteri immessi su 4
        Serial.println("1");                                                                                    //scrivi 1 sulla porta seriale
        digitalWrite(LEDCONFERMA, LOW);                                                                         //spegni il led di conferma
        delay(200);                                                                                             //aspetta 0.2 secondi
    }

    if (caratteriIn == 4 &&(carattere1 == 1 && (carattere2 == 1 && (carattere3 == 0 && carattere4 == 1)))) {    //se il pin corrispende a 1100
        stato = false;                                                                                          //spegni l'allarme
        

        carattere1 = 0;                                                                                         //resetta i caratteri
        carattere2 = 0;
        carattere3 = 0;
        carattere4 = 0;
    }
    else{
        carattere1 = 0;                                                                                         //resetta i caratteri
        carattere2 = 0;
        carattere3 = 0;
        carattere4 = 0;
        tone(BUZZ, 587, 500);                                                                                   //riproduce delle note con il buzz
        delay(300);
        tone(BUZZ, 392, 1500);
        caratteriIn = 0                                                                                         //resetta i caratteri immessi
    }
}