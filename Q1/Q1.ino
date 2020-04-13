void setup()
{
  pinMode(7, OUTPUT);

}
int pm[12][4] = {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,1},{0,0,1,1},{0,0,1,0},{0,1,1,0},{0,1,0,0},{1,1,0,0}};
long previousMillis = 0;
long ledState = LOW;
long currentMillis;
long len = 100;
int j = 0;

void loop()
{
  currentMillis = millis();
  if(currentMillis-previousMillis >= len){
    for(int i = 0;i < 4;i++){
        digitalWrite(i+4,pm[j][i]);
      if(j ==1, j==3, j==5, j==7, j==9, j==11){
       
        len=300;
      }
    }
    j++;
    previousMillis = currentMillis;
  }
}
    
  
