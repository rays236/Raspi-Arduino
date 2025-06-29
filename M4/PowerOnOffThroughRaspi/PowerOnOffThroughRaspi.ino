#define LED_PIN 13
void setup() {
	Serial.begin(115200);
	while(!Serial){}
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
if(Serial.available() > 0){
	String status = Serial.readStringUntil('\n');
	if(status=="on"){
		digitalWrite(LED_PIN, HIGH);
	} else if (status=="off"){
		digitalWrite(LED_PIN, LOW);
	} else {
		digitalWrite(LED_PIN, HIGH);
		delay(1000);
		digitalWrite(LED_PIN, LOW);
		}	
	}
}
