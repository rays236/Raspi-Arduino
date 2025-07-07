#define BUZZER_PIN 8

void setup() {
	pinMode(BUZZER_PIN, OUTPUT);
	tone(BUZZER_PIN, 200, 2000);  // port, tone, time in millisec
}

void loop() {
}
