#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int counter = 0;

unsigned long lastTimeCounterSent = millis();
unsigned long sendCounterDelay = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial) {}
  lcd.init();
	lcd.backlight();
	lcd.setCursor(0,0);
	lcd.print("Hello, World!");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();
  if(timeNow - lastTimeCounterSent >= sendCounterDelay) {
    lastTimeCounterSent = timeNow;
    Serial.println(counter);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sent counter: ");
    lcd.setCursor(0, 1);
    lcd.print(counter);
    counter++;
  }
  if(Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(cmd);
    if (cmd == "reset_counter") {
      counter = 0;
    }
    else {

    }
  }

}
