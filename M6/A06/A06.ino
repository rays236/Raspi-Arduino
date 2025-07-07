#define BUTTON_PIN 7
#define GREEN_ONE_PIN 9
#define GREEN_TWO_PIN 11
#define YELLOW_PIN 10

unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDelay = 50;
byte previousButtonState;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);
  pinMode(GREEN_ONE_PIN, OUTPUT);
  pinMode(GREEN_TWO_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  
  previousButtonState = digitalRead(BUTTON_PIN);

  Serial.begin(115200);
  while (!Serial) {}
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow = millis();
  if(timeNow - lastTimeButtonChanged >= debounceDelay) {
    byte buttonState = digitalRead(BUTTON_PIN);
    if(buttonState != previousButtonState) {
      lastTimeButtonChanged = timeNow;
      previousButtonState = buttonState;
      if(buttonState == HIGH) {
        Serial.println("button_pressed");
      }
    }
  }
  if(Serial.available() > 0){
    String cmd = Serial.readStringUntil('\n');
    if(cmd.startsWith("green1")){
      digitalWrite(GREEN_ONE_PIN, HIGH);
    }
    else if (cmd.startsWith("green2")){
      digitalWrite(GREEN_TWO_PIN, HIGH);
    }
    else if (cmd.startsWith("yellow")){
      digitalWrite(YELLOW_PIN, HIGH);
    }
    else {
      digitalWrite(GREEN_ONE_PIN, LOW);
      digitalWrite(GREEN_TWO_PIN, LOW);
      digitalWrite(YELLOW_PIN , LOW);
    }
  }
}