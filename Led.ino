#define PULSANTE1   11
#define PULSANTE2   12
#define LED1        2
#define LED2        3

bool LED1;
bool LED2;

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(PULSANTE1, INPUT);
    pinMode(PULSANTE2, INPUT);
    LED1 = 0;
    LED2 = 0;
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
}

void loop() {
if (digitalRead(PULSANTE1) == HIGH) {
        varled1 = !varled1;
        delay(200);
    }

    if (varled1 == 1) {
        digitalWrite(LED1, HIGH);
    }
    else {
        digitalWrite (LED1, LOW);
    }

    if (digitalRead(PULSANTE2) == HIGH) {
        varled2 = !varled2;
        delay(200);
    }

    if (varled2 == 1) {
        digitalWrite(LED2, HIGH);
    }
    else {
        digitalWrite (LED2, LOW);
    }
}