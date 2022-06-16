#define triggerPort 2
#define echoPort    3
#define buzz        4
#define bottone1    5
#define bottone2    6
bool stato;

void setup() {
    pinMode(triggerPort, OUTPUT);
    pinMode(echoPort,    INPUT);
    pinMode(buzz,        OUTPUT);
    pinMode(bottone1,    INPUT);
    pinMode(bottone2,    INPUT);
    Serial.begin(9600);
    stato = false;
}

void loop() {
    digitalWrite(triggerPort, LOW);
    digitalWrite(triggerPort, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPort, LOW);

    long durata     = pulseIn(echoPort, HIGH);
    long distanza   = 0.034 * durata / 2;
    Serial.print  ("distanza: ");
    Serial.print  (distanza);
    Serial.println(" cm        ");
    delay(200);

    if (distanza <= 15 && stato == true) {
        tone(buzz, 466, 500);
    }

    if (digitalRead(bottone1) == HIGH && digitalRead(bottone2) == HIGH) {
        if (stato == true) {
            stato = false;
        }
        else {stato = true;}

        delay(500);
        tone(buzz, 466, 100);
        delay(200);
        tone(buzz, 466, 200);
    } 
}