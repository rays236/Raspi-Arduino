#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  // Comment out while(!Serial) for boards without native USB
  // while (!Serial);
  Serial.println("I2C Scanner...");
  
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Found device at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Done scanning.");
}

void loop() {
  // nothing here
}

