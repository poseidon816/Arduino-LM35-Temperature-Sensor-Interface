# Arduino-LM35-Temperature-Sensor-Interface
Problem statement: Develop the code in Arduino to interface an LM35 temperature sensor (Assume the sensor is connected to Arduino Analog pin A0) with an Arduino Uno and control the onboard LED based on temperature readings: 
1.	Interface the LM35 temperature sensor with an Arduino Uno. 
2.	When the temperature falls below 30 degrees Celsius, make the onboard LED blink every 250 milliseconds.
3.	If the temperature rises above 30 degrees Celsius, make the onboard LED blink every 500 milliseconds.


In this code:

1. We begin by defining constants for pin assignments, the temperature threshold, and variables to store temperature readings and track the temperature state.
2. In the setup() function, we initialize serial communication for debugging and set the LED pin as an output.
3. The loop() function continuously reads the temperature from the LM35 sensor and checks if it is above or below the specified threshold. Based on the temperature state, it calls the startBlinking() function to control the LED blink rate.
4. The readLM35Temperature() function reads the analog value from the LM35 sensor, converts it to degrees Celsius, and returns the temperature.
5. The startBlinking() function controls the LED blink rate without using delay().
  This code follows coding standards and includes comments for clarity and maintainability.
