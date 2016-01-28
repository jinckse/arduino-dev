// Created by Jarrod Nix on January 10, 2016

//TMP36 Pin Variables

// The analog pin the TMP36's Vout (sense) pin is connected to 
// the resolution is 10 mV / degree centigrade with a 
// 500 mV offset to allow for negative temperatures
int sensorPin = 0; 

// setup() - This function runs once when you turn your Arduino on.
// We initialize the serial connection with the computer

void setup() {
  // Start the serial connection with the computer to view the 
  // results on the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Get voltage reading from the sensor
  int reading = analogRead(sensorPin);
  
  // Convert the reading to a voltage. For 3.3v Arduino use 3.3
  float voltage = reading * 5.0;
  voltage /= 1024.0;

  // Print voltage
  Serial.print(voltage);
  Serial.println(" volts");

  // Print temperature
  // Converting from 10 mV per degree with 500 mV offset to 
  // degrees ((voltage - 500 mV) * 100)
  float tempC = (voltage - 0.5) * 100;

  Serial.print(tempC);
  Serial.println(" degrees C");

  // Now convert centigrade to  fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  Serial.print(tempF);
  Serial.println(" degrees F");

  // Wait for a second
  delay(1000);
} 
