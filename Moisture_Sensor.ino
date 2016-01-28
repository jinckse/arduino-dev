// Created by Jarrod Nix on January 10, 2016

// Sensor value description
// 0   ~ 300 dry soil
// 300 ~ 700 humid soil
// 700 ~ 950 saturated

void setup() {
  // Start serial connection
  Serial.begin(57600);
}

void loop() {
  // Diplay bare results from analog pin 0 (range from 0 to 1023)
  Serial.print("Moisture Sensor Value: ");
  Serial.println(analogRead(A0));

  // Wait
  delay(100);
} 
