// Calibrating HCHO
/*
  1.  Plug in Grove Sensor
  2.  Run this code
  3.  Wait for the Value to Stablize
  3.  Record R0
  4.  I got 30.97
  5.  Don't mess with the pot. anymore
  
*/
#define Vc 4.95

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int sensorValue=analogRead(A0);
    float R0=(1023.0/sensorValue)-1;
    Serial.print("R0 = ");
    Serial.println(R0);
    delay(500);
}
