void setup() {
  Serial.begin(9600);
  Serial.println("MiCS-5524 demo!");
}
 
void loop() {
  float reading = analogRead(A0);
  reading = ((reading - 3) / 1024 * 500) ;
  Serial.print("CO2 PPM: ");
  Serial.println(reading);
 
  delay(500);
}

// For this one you'll want to to publish the raw output,
// and use grafana to calculate the implied other values

