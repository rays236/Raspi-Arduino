int counter = 0;
void setup() {
Serial.begin(115200);
while(!Serial){
}
}

void loop() {
//println sends data to raspi so be careful about that alternatively you can use lcd screen
//Serial.println("Hello from Arduino");
// receives data from rasppi
if(Serial.available() > 0){
	String message = Serial.readStringUntil('\n');
	message = message + " " + String(counter);
	counter++;
	Serial.println(message); // bilateral communication i.e. reply the message as soon as it receives it
}
delay(1000);
}
