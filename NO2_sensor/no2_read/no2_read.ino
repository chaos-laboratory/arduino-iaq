
int read_pin = A0;
int resistor = 9910;

double ppm = 0;

double _delay = 500;
double voltage = 0;

void setup() {
    
    Serial.begin(9600);
    Serial.println("Measuring Vout!");
}

void loop() {
    voltage = analogRead(read_pin); // reads the analog voltage
    Serial.print("ADC Reading: ");
    Serial.print(voltage);
    Serial.print(" Vout: ");
    ppm = 9910/(1023/voltage - 1);
    Serial.println(ppm);
    delay(_delay);
}
