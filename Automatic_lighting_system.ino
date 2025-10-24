#define LDR_PIN A0       
#define RELAY_PIN 8      
#define THRESHOLD 500   

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // start with relay OFF
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // Read LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // If it's dark, turn ON the relay (light ON)
  if (ldrValue < THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("It's dark -> Light ON");
  } 
  // If it's bright, turn OFF the relay (light OFF)
  else {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("It's bright -> Light OFF");
  }

  delay(500); // small delay for stability
}