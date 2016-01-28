const int pingPin = 11;
float duration, inches, meters;

void setup() {
  Serial.begin(9600);
}

void loop() {
  pinMode(pingPin, OUTPUT);          // Set pin to OUTPUT
  digitalWrite(pingPin, LOW);        // Ensure pin is low
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);       // Start ranging
  delayMicroseconds(5);              //   with 5 microsecond burst
  digitalWrite(pingPin, LOW);        // End ranging
  pinMode(pingPin, INPUT);           // Set pin to INPUT
  duration = pulseIn(pingPin, HIGH); // Read echo pulse
  inches = duration / 74 / 2; // Convert to inches 
  meters = inches * 0.0254; // Convert inches to meters
  
  Serial.print(meters);
  Serial.print("m ");
  
  for(int i = 0; i < (meters*30); i++)
  {
    Serial.print("="); 
  }
  
  Serial.print("|");
  Serial.println();
  delay(100);		             // Short delay
}
