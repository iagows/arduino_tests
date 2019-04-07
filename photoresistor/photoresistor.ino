const int photo = A0;
const int led = 3;


void setup() {
  pinMode(photo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int in = analogRead(photo);
  Serial.println(in);
  in = map(in, 0, 1023, 0, 255);
  analogWrite(led, 255-in);
}
