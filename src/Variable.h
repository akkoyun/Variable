/* *******************************************************************************
 *  Copyright (C) 2014-2022 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Variable
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *
 *********************************************************************************/

#ifndef __Variable__
#define __Variable__

	// Define Arduino Library
	#ifndef Arduino_h
		#include <Arduino.h>
	#endif

	// Include Data Type Library
	#ifndef __DataType__
		#include "DataType.h"
	#endif

	// KeyValue Class
	template<typename DataType> class Key_Value {

		// Public Context
		public:

			// Declare Key Variable
			uint16_t _Data_Key;

			// Declare Value Variable
			DataType _Data_Value;

			// Constractor
			Key_Value() : _Data_Key(0), _Data_Value() {}
			Key_Value(uint16_t _Key, DataType _Value) : _Data_Key(_Key), _Data_Value(_Value) {

			}

	};

	// Variable Class
	template<typename DataType> class Variable {

		// Private Context
		private:

			// Declare Data Container
			Key_Value<DataType>* Data_Container;
			
			// Declare Capacity
			uint16_t Capacity;
			
			// Declare Current Size
			uint16_t Current_Size;

			// Resize Function
			void Resize(void) {

				// Check Capacity
				Capacity = (Capacity == 0) ? 1 : Capacity * 2;

				// Create New Data
				Key_Value<DataType>* _New_Data = new Key_Value<DataType>[Capacity];

				// Copy Data
				for (uint16_t i = 0; i < Current_Size; i++) _New_Data[i] = Data_Container[i];

				// Delete Old Data
				delete[] Data_Container;

				// Set New Data
				Data_Container = _New_Data;

			}

		public:

			// Constractor
			Variable(void) : Data_Container(nullptr), Capacity(0), Current_Size(0) {

			}

			// Destructor
			~Variable() {

				// Delete Data
				delete[] Data_Container;

				// Reset pointers and counters
				Data_Container = nullptr;
				Capacity = 0;
				Current_Size = 0;

			}

			// Push Back Function
			void Add(uint16_t _Key, DataType _Value) {

				// Search for the key
				for (uint16_t i = 0; i < Current_Size; i++) {

					// Check Key
					if (Data_Container[i]._Data_Key == _Key) {
						
						// Update the value
						Data_Container[i]._Data_Value = _Value;
						
						// End Function
						return;

					}

				}

				// Check Capacity
				if (Current_Size == Capacity) Resize();

				// Add new data
				Data_Container[Current_Size++] = Key_Value<DataType>(_Key, _Value);

			}

			// Get Function
			DataType* Get(uint16_t _Key) {

				// Search for Key
				for (uint16_t i = 0; i < Current_Size; i++) {

					// Check Key
					if (Data_Container[i]._Data_Key == _Key) {

						// Return Value
						return &Data_Container[i]._Data_Value;

					}

				}

				// Return Null
				return nullptr;

			}

			// Get Size Function
			uint16_t Size(void) const {
				
				// Return Size
				return Current_Size;

			}

			// Clear Function
			void Clear(void) {
			
				// Delete existing data
				delete[] Data_Container;

				// Reset pointers and counters
				Data_Container = nullptr;
				Capacity = 0;
				Current_Size = 0;

			}
	};

#endif /* defined(__Variable__) */
