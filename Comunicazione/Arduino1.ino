int v = 0;

void setup() {
   Serial.begin(9600);
}

void loop() {
  Serial.println(v);
  delay(500);
  v++;
}