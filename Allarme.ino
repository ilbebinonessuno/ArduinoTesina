#define TRIGGERPORT 2
#define ECHOPORT    3
#define BUZZ        4
#define BOTTONE1    5
#define BOTTONE2    6
#define LEDCONFERMA 7

bool stato;
bool carattere1;
bool carattere2;
bool carattere3;
bool carattere4;
int caratteriIn;

void setup() {
    pinMode(TRIGGERPORT, OUTPUT);
    pinMode(ECHOPORT,    INPUT);
    pinMode(BUZZ,        OUTPUT);
    pinMode(BOTTONE1,    INPUT);
    pinMode(BOTTONE2,    INPUT);
    pinMode(LEDCONFERMA, OUTPUT);
    Serial.begin(9600);
    stato = false;
    caratteriIn = 0;
    digitalWrite(LEDCONFERMA, HIGH);

}

void loop() {
    digitalWrite(TRIGGERPORT, LOW);
    digitalWrite(TRIGGERPORT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGERPORT, LOW);

    long durata     = pulseIn(ECHOPORT, HIGH);
    long distanza   = 0.034 * durata / 2;
    //Serial.print  ("distanza: ");
    //Serial.print  (distanza);
    //Serial.println(" cm        ");
    delay(200);

    if (distanza <= 15 && stato == true) {
        tone(BUZZ, 466, 500);
    }

    if (digitalRead(BOTTONE1) == HIGH && digitalRead(BOTTONE2) == HIGH) {
        if (stato == true) {
            caratteriIn = 0;
        }
        else {stato = true;digitalWrite(LEDCONFERMA, LOW);}
        delay(500);
        tone(BUZZ, 466, 200);
        delay(200);
        tone(BUZZ, 466, 200);
    } 

    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 0) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere1 = 0;
        caratteriIn = 1;
        Serial.println("0");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 0) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere1 = 1;
        caratteriIn = 1;
        Serial.println("1");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }

    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 1) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere2 = 0;
        caratteriIn = 2;
        Serial.println("0");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }
    
    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 1) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere2 = 1;
        caratteriIn = 2;
        Serial.println("1");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }


    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 2) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere3 = 0;
        caratteriIn = 3;
        Serial.println("0");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 2) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere3 = 1;
        caratteriIn = 3;
        Serial.println("1");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }

    if (digitalRead(BOTTONE1) == HIGH && caratteriIn == 3) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere4 = 0;
        caratteriIn = 4;
        Serial.println("0");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }

    if (digitalRead(BOTTONE2) == HIGH && caratteriIn == 3) {
        digitalWrite(LEDCONFERMA, HIGH);
        carattere4 = 1;
        caratteriIn = 4;
        Serial.println("1");
        delay(200);
        digitalWrite(LEDCONFERMA, LOW);
    }

    if (caratteriIn == 4 &&(carattere1 == 1 && (carattere2 == 1 && (carattere3 == 0 && carattere4 == 1)))) {
        stato = false;
        
        delay(500);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 587, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 587, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 493, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 523, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 493, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 587, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);
        tone(BUZZ, 587, 500);
        pinMode(LEDCONFERMA, LOW);
        delay(400);
        pinMode(LEDCONFERMA, HIGH);

        carattere1 = 0;
        carattere2 = 0;
        carattere3 = 0;
        carattere4 = 0;
    }
    else{
        carattere1 = 0;
        carattere2 = 0;
        carattere3 = 0;
        carattere4 = 0;
        tone(BUZZ, 587, 500);
        delay(300);
        tone(BUZZ, 392, 1500);
        caratteriIn = 0
    }
}