const int IN = A0;
void setup() {
  pinMode(IN, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(IN));
  delay(5000);

}
