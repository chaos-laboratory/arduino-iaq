// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int ledPin = 13;                 // LED connected to digital pin 13

float sensorValue = 0;        // value read from the sensor




void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output

  Serial.println("CO Test!");
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  sensorValue = sensorValue / 1023 * 2000;

  // reads between 20-2000 ppm CO

  // print the results to the serial monitor:
  Serial.print("CO PPM = " );                       
  Serial.println(sensorValue);     

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(500);                     
}
