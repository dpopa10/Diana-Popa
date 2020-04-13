void setup()
{
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
int pm[12][4] = {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
unsigned long previousMillis = 0;
long ledState = LOW;
unsigned long currentMillis;
long len = 100;

int j = 0;

void loop()
{
  int sensorValue = analogRead(A0);
  currentMillis = millis();
  if (currentMillis - previousMillis >= len) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(i + 4, pm[j][i]);
      if (j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11) {
        len = 300 + sensorValue;
      }
      else {
        len = 100;
      }
    } j++;
    if (j > 11)
    {
      j = 0;
    }previousMillis = currentMillis;
  }

  
}
