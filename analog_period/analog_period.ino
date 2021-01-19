unsigned long pushTime, pushFreeTime;
int modeReturn;
int analogValue;
bool stateChange;
int butonType;
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop() {
  if (analogRead(A0) < 1000 && stateChange == 0) {
    butonType = analogRead(A0);
    pushTime = millis();
    stateChange = 1;
  }

  if (analogRead(A0) > 1000 && stateChange == 1) {
    pushFreeTime = millis();
    stateChange = 0;
  }
  int period = pushFreeTime - pushTime;
  if (period > 20) {
    Serial.println("**********************");
    Serial.print("Period Time = ");
    Serial.println(period);
    Serial.print("Analog Value = ");
    Serial.println(butonType);
    period = 0;
    pushFreeTime = pushTime;
  }

}
