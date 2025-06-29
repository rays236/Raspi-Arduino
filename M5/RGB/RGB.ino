#define YELLOW_PIN 11
#define GREEN_ONE_PIN 10
#define GREEN_TWO_PIN 9
void setup() {
	pinMode(YELLOW_PIN, OUTPUT);
	pinMode(GREEN_ONE_PIN, OUTPUT);
	pinMode(GREEN_TWO_PIN, OUTPUT);

//	digitalWrite(YELLOW_PIN, HIGH);
//	digitalWrite(GREEN_ONE_PIN, HIGH);
//	digitalWrite(GREEN_TWO_PIN, LOW);

	analogWrite(GREEN_ONE_PIN, 180);  // 0-255 brightness level
	analogWrite(YELLOW_PIN, 180);
	analogWrite(GREEN_TWO_PIN, 255);
}

void loop() {
}
