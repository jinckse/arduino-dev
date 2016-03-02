// Credit to Wildblue (http://playground.arduino.cc/Profiles/Wildblue)

// Define analog input pin
int AnalogInputPin = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read analog value
  double Current = currentSensor(analogRead(AnalogInputPin)); 
  Serial.print(", VariationFromNull: ");
  printDouble(Current, 2);
  Serial.print(" A");
  Serial.println("");

  delay(1000);
}

// Print decimal numbers

void printDouble(double val, byte precision) {
  Serial.print(int(val));

  if (precision > 0) {
    Serial.print(".");
    unsigned long frac, mult = 1;
    byte padding = precision -1;
    while (precision--) mult *=10;
    if (val >= 0) frac = ( val-int(val) ) * mult; else frac = ( int(val) - val) * mult;
    unsigned long frac1 = frac;
    while (frac1 /= 10) padding--;
    while(padding--) Serial.print("0");
    Serial.print(frac, DEC);
  }
}

// Read 1.1V reference agains AVcc

long readInternalVcc() {
  long result;
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  
  // Wait for Vref to settle
  delay(2);
  
  // Convert
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA, ADSC));
  result = ADCL;
  result |= ADCH << 8;
  
  // Back-calculate AVcc in mV
  result = 1126400L / result;
  return result;
}

// Calculate current with Allegro ACS714

double currentSensor(int RawADC) {
  
  // mV/A
  int Sensitivity = 66;
  
  long InternalVcc = readInternalVcc();
  double ZeroCurrentVcc = InternalVcc / 2;
  double SensedVoltage = (RawADC * InternalVcc) / 1024;
  double Difference = SensedVoltage - ZeroCurrentVcc;
  double SensedCurrent = Difference / Sensitivity;
  
  Serial.print("ADC: ");
  Serial.print(RawADC);
  Serial.print("/1024");
  
  Serial.print(", Sensed Voltage: ");
  printDouble(SensedVoltage, 1);
  Serial.print("mV");
  
  Serial.print(", 0A at: ");
  printDouble(ZeroCurrentVcc, 1);
  Serial.print("mV");
  
  // Return the Current
  return SensedCurrent;
}
                
		
