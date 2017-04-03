#include <Wire.h>

int i = 0;
static const int address = 0x15;  // I2C Sensor address
static const int MOD_READ[] = {
  0x04, /* Modbus function: Read Input Registers */
  0x13, /* Starting Address: 5003, MSB first */
  0x8B,
  0x00, /* # of registers to read: 1, MSB first */
  0x01,
  0x46, /* CRC, LSB then MSB */
  0x70
};

unsigned char buffer[6]; // this is to store the response
byte PWM_PIN = 2;

int pwm_value;

int ppm;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_PIN, INPUT);
  Wire.begin();
}

void loop() {
  pwm_value = pulseIn(PWM_PIN, HIGH);
  pwm_value = pwm_value / 1024 * 2000;
  // Send request to CO2 sensor
  Wire.beginTransmission(address);
  for (i = 0; i < 6; i++) {
    Wire.write(MOD_READ[i]);
  }
  Wire.endTransmission();

  Wire.requestFrom(address, 6);
  if (Wire.available()) {
    for (int i = 0; i < 6; i++) {
      buffer[i] = Wire.read();
    }
  }

  ppm = buffer[2] * 256 + buffer[3];
  Serial.print("PPM: ");
  Serial.print(ppm);
  Serial.print(" || PWM: ");
  Serial.print(" ");
  Serial.print((pwm_value-2)*2);
  Serial.print(" || ");
  Serial.print(" ");
  Serial.print(buffer[0]);
  Serial.print(" ");
  Serial.print(buffer[1]);
  Serial.print(" ");
  Serial.print(buffer[2]);
  Serial.print(" ");
  Serial.print(buffer[3]);
  Serial.print(" ");
  Serial.print(buffer[4]);
  Serial.print(" ");
  Serial.print(buffer[5]);  Serial.print(" ");
  Serial.println(buffer[6]);
  delay(5000);

}
