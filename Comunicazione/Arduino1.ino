//*****************************************************************************************
//****questo programma è stato creato solo per testare la comunicazione fra i 2 arduino****
//*****************************************************************************************

int v = 0;                //imposta la variabile v su 0

void setup() {
   Serial.begin(9600);    //imposta il monitor seriale su 9600 bauld
}

void loop() {
  Serial.println(v);      //scrivi sul monitor setiale il valore di v
  delay(500);             //aspetta 0.5 secondi
  v++;                    //aggiunge 1 a v
}