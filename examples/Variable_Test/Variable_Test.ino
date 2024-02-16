// Include the Variable library
#include "Variable.h"

// Create a Variable object
Variable<float> Data;

// Setup
void setup() {

	// Start Serial
	Serial.begin(115200);

	// Add some data
	Data.Add(_Data_PCB_T_, 30.2);
	Data.Add(_Data_PCB_H_, 40.3);

	// Update some data
	Data.Add(_Data_PCB_H_, 60.5);

	// Get some data
	const uint16_t keys[] = {_Data_PCB_T_, _Data_PCB_H_};
  
	// Print the data
	for (uint16_t key : keys) {

		// Get the value
	    const float* value = Data.Get(key);

		// Check if the value is null
		if (value != nullptr) {
			Serial.print(F("Key "));
			Serial.print(key);
			Serial.print(F(" has value: "));
			Serial.println(*value);
		} else {
			Serial.print(F("Key "));
			Serial.print(key);
			Serial.println(F(" not found."));
		}

	}

}

// Loop
void loop() {

}
