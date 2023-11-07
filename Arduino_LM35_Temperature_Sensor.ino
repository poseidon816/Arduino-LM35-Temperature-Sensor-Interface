// Arduino LM35 Temperature Sensor Interface

// Define constants
const int lm35Pin = A0;   // Analog pin A0 for LM35 sensor
const int ledPin = 13;    // Onboard LED connected to digital pin 13
const int belowThreshold = 30;  // Temperature threshold in degrees Celsius

// Define variables
int temperature;  // To store temperature reading
bool isBelowThreshold = false;  // To track temperature state

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read temperature from LM35 sensor
  temperature = readLM35Temperature();
  
  // Check if temperature is below the threshold
  if (temperature < belowThreshold) {
    if (!isBelowThreshold) {
      // Temperature has just fallen below the threshold
      isBelowThreshold = true;
      startBlinking(250);  // Blink LED every 250 milliseconds
    }
  } else {
    if (isBelowThreshold) {
      // Temperature has just risen above the threshold
      isBelowThreshold = false;
      startBlinking(500);  // Blink LED every 500 milliseconds
    }
  }
  
  // Print temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}

int readLM35Temperature() {
  // Read the analog value from LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  
  // Convert the analog value to temperature in degrees Celsius
  float voltage = (sensorValue / 1023.0) * 5.0;
  float degreesCelsius = (voltage - 0.5) * 100.0;
  
  return int(degreesCelsius);
}

void startBlinking(int interval) {
  // Function to start blinking the LED at the specified interval
  digitalWrite(ledPin, HIGH);
  delay(interval);
  digitalWrite(ledPin, LOW);
  delay(interval);
}
