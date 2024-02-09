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
	#ifndef __Arduino__
		#include <Arduino.h>
	#endif

	// Include Config
	#include "Config.h"

	// Define Variable Class
	class Variable {

		// Public Context
		public:

			// Define Variable Structure
			struct Struct_Variable_List {

				// Define Variable Count
				uint8_t	Variable_Count = 0;

				// Define Variable Structure
				struct Struct_Variable {
					
					// Define Variable Name
					char * Name;

					// Define Variable Value
					float Value;

				};

				// Define Variable Array
				Struct_Variable Variable[MAX_VARIABLE_COUNT];

			} Data;

			// Constructor
			Variable(void) {

				// Clear Variables
				this->Clear();

			}

			// Set Variables Function
			bool Add(const char* _Name, float _Value) {

				// Control for Existing Variable
				for (uint8_t i = 0; i < this->Data.Variable_Count; i++) {

					// Check for Existing Variable
					if (strcmp(Data.Variable[i].Name, _Name) == 0) {

						// Update Value
						Data.Variable[i].Value = _Value;

						// End Function
						return true;

					}

				}

				// Control for Max Variable Count
				if (this->Data.Variable_Count < MAX_VARIABLE_COUNT) {

					// Set Variable Name
					Data.Variable[this->Data.Variable_Count].Name = strdup(_Name);

					// Control for Memory Allocation
					if (Data.Variable[this->Data.Variable_Count].Name == NULL) return false;

					// Set Variable Value
					Data.Variable[this->Data.Variable_Count].Value = _Value;

					// Increase Variable Count
					this->Data.Variable_Count++;

					// End Function
					return true;

				}

				// Failed to add variable (likely due to reaching max count)
				return false;

			}

			// Clear Variable
			void Clear(void) {

				// Loop through all variables
				for (uint8_t i = 0; i < this->Data.Variable_Count; i++) {

					// Free the memory
					free(Data.Variable[i].Name);

					// Set the pointer to NULL
					Data.Variable[i].Name = NULL;

				}

				// Clear the variable count
				this->Data.Variable_Count = 0;

			}

	};

#endif /* defined(__Variable__) */
