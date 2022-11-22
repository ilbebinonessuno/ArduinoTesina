//*****************************************************************************************
//****questo programma è stato creato solo per testare la comunicazione fra i 2 arduino****
//*****************************************************************************************

#include <SoftwareSerial.h>                     //include la libreria SoftwareSerial

#define SOFTRX    10                            //definisce che il SOFTRX è sul pin 10
#define SOFTTX    11                            //definisce che il SOFTTX è sul pin 11
#define SERIALLED LED_BUILTIN                   //definisce che il SERIALLED è il led integrato in arduino

SoftwareSerial seriale2(SOFTRX, SOFTTX);        //definisce i pin della porta software seriale

void setup() {
    pinMode(SOFTRX, INPUT);                     //imposta il pin SOFTRX su input
    pinMode(SOFTTX, OUTPUT);                    //imposta il pin SOFTTX su input
    pinMode(SERIALLED, OUTPUT);                 //imposta il pin SERIALLED su output
    delay(2000);
   
    Serial.begin(9600);                         //imposta la porta seriale su 9600 bauld
    digitalWrite(SERIALLED, HIGH);              //accende e spegne il led per notificare l'accensione
    delay(200);
    digitalWrite(SERIALLED, LOW);
    delay(400);
    digitalWrite(SERIALLED, HIGH);
    delay(200);
    digitalWrite(SERIALLED, LOW);

    seriale2.begin(9600);                       //imposta la porta seriale software su 9600 bauld
    delay(1000);                                //aspetta 1 secondo
}

void loop() {
    if (seriale2.available()) {                 //se sulla porta seriale software viene scritto qualcosa
        Serial.write(seriale2.read());          //scrivere il contenuto di essa sulla porta seriale
    }
}