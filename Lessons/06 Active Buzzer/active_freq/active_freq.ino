
const int buzzer = 8;  //the pin of the active buzzer

void setup() {
  pinMode(buzzer, OUTPUT);  //initialize the buzzer pin as an output
}
void loop() {
  //output an frequency
  for (int i = 0; i < 80; i++) {
    digitalWrite(buzzer, HIGH);
    delay(1);  //wait for 1ms
    digitalWrite(buzzer, LOW);
    delay(1);  //wait for 1ms
  }
  
  //output another frequency
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzer, HIGH);
    delay(2);  //wait for 2ms
    digitalWrite(buzzer, LOW);
    delay(2);  //wait for 2ms
  }
}
