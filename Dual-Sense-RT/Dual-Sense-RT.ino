// Dual-Interface Reaction Time Tester Code
const int touchPin  = 2;  // TTP223 Touch Sensor (Active HIGH)
const int buttonPin = 3;  // Push Button (Active LOW with INPUT_PULLUP)

const int redLed    = 8;   // Warning Light
const int greenLed  = 9;   // Stimulus Light
const int yellowLed = 10;  // Standby Light

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  Serial.begin(9600);
  
  pinMode(touchPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  
  // Initial State: Standby Mode
  digitalWrite(yellowLed, HIGH);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  
  Serial.println("==========================================");
  Serial.println("   DUAL-INTERFACE REACTION TIME TESTER    ");
  Serial.println("==========================================");
  Serial.println("Touch Sensor ya Push Button daba kar start karein...");
}

bool isInputTriggered() {
  // Touch Sensor HIGH hota hai, Push Button LOW hota hai
  bool touchState  = (digitalRead(touchPin) == HIGH);
  bool buttonState = (digitalRead(buttonPin) == LOW);
  return (touchState || buttonState);
}

void loop() {
  // Step 1: Wait for initiation signal
  if (isInputTriggered()) {
    delay(200); // Debounce delay
    
    // Switch from Standby to Warning State
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    Serial.println("\n[SYSTEM] Ready! Standby LED OFF. Red LED ON.");
    Serial.println("[SYSTEM] Random delay active... Don't press yet!");
    
    // Step 2: Random delay generation (1.5 to 4 seconds)
    int randomDelay = random(1500, 4000);
    unsigned long delayStart = millis();
    bool falseStart = false;
    
    while (millis() - delayStart < randomDelay) {
      if (isInputTriggered()) {
        falseStart = true;
        break;
      }
    }
    
    // Handle Early Trigger / False Start
    if (falseStart) {
      Serial.println("[WARNING] False Start Detected! Pehle dabaney par penalty.");
      for (int i = 0; i < 5; i++) {
        digitalWrite(redLed, LOW);
        delay(100);
        digitalWrite(redLed, HIGH);
        delay(100);
      }
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, HIGH);
      return;
    }
    
    // Step 3: Stimulus Phase (Green LED ON)
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    startTime = millis();
    Serial.println("[ACTION] GREEN LED ON! REACT NOW!");
    
    // Step 4: Measure Reaction Time
    while (!isInputTriggered()) {
      // Waiting for reaction
    }
    reactionTime = millis() - startTime;
    digitalWrite(greenLed, LOW);
    
    // Step 5: Output Results to Serial Monitor
    Serial.print("[RESULT] Reaction Time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");
    
    if (reactionTime < 300) {
      Serial.println("[EVALUATION] Grade: Pro Gamer / Lightning Fast!");
    } else if (reactionTime < 400) {
      Serial.println("[EVALUATION] Grade: Average Human Reflexes.");
    } else {
      Serial.println("[EVALUATION] Grade: Slow Response. Try Again!");
    }
    
    delay(2000);
    digitalWrite(yellowLed, HIGH);
    Serial.println("\nSystem Reset. Touch or Press to test again...");
  }
}
