const int pingPin = 11;
const int t = 7;
float duration, inches, meters1, meters2, v;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{                           
    pinMode(pingPin, OUTPUT);          // Set pin to OUTPUT
    digitalWrite(pingPin, LOW);        // Ensure pin is low
  
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);       // Start ranging
    delayMicroseconds(5);              //   with 5 microsecond burst
    digitalWrite(pingPin, LOW);        // End ranging
    pinMode(pingPin, INPUT);           // Set pin to INPUT
  
    duration = pulseIn(pingPin, HIGH); // Read echo pulse
    inches = duration / 74 / 2;        // Convert to inches 
    
    meters1 = inches * 0.0254;          // Convert inches to meters
    
    delay(1000);
    
    pinMode(pingPin, OUTPUT);          // Set pin to OUTPUT
    digitalWrite(pingPin, LOW);        // Ensure pin is low
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);       // Start ranging
    delayMicroseconds(5);              //   with 5 microsecond burst
    digitalWrite(pingPin, LOW);        // End ranging
  
    pinMode(pingPin, INPUT);           // Set pin to INPUT
  
    duration = pulseIn(pingPin, HIGH); // Read echo pulse
    inches = duration / 74 / 2;        // Convert to inches 
    
    meters2 = inches * 0.0254; 
    
    v = (meters1 - meters2) / 1;
   
    Serial.print("x_0 = ");
    Serial.print(meters1);
    Serial.print("m ");
    Serial.println("\n");
    Serial.print("x = ");
    Serial.print(meters2);
    Serial.print("m ");
    Serial.println("\n");
    Serial.print("t = 1s");
    Serial.println("\n");
    Serial.print("v = ");
    Serial.print(v);
    Serial.print(" m/s");
    Serial.println("\n*************************\n\n"); 
    
    // Short delay
    delay(1000);	
  }
   
  	             

