void setup() {
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);delay(500);
  double d = analogRead(A0);
  d = map(d, 0, 1024, 100, 0);
  Serial.print(d);Serial.println("%");
}
