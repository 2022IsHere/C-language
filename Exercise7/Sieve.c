// File:	Sieve.c
// Author(s):	Sebastian Sopola		
// Description:	calculate Sieve of Eratosthenes algoritm to find primes numbers out of a group of numbers

// all necessary libraries are in this header file 
#include "Sieve.h"




// function that gets integer as string argument and checks that string and if it is correctly formated integer, true is returned
bool parse_int(char *string, int *integer) {
	
	// input string index calculator
	int index = 0;
	int integer_chars = 0;
	
	// temporary array to save each digit
	char integer_buffer[BUFFER_SIZE];
	
	// check integer string for white spaces 
	while ( isspace(string[index]) ) {
		 index++; 
	}
	
	// check if whole string is only white spaces
	int length = 0;
	//int length = strlen(string);
	length = strlen(string);
	
	if ( length == index ) {
		return false;
	}
	
	// check if at first index in input string is - tag or not and move index counter to next
	if ( string[index] == '-' ) {
		integer_buffer[integer_chars] = '-'; 
		integer_chars++;
		index++;
		
		// CHeck if at next index is not an integer.
		if ( !isdigit(string[index]) ) {
			return false;
		}
	}
	
	// loop through input string until we hit whitespace or end of the string. position: '-2'
	// if we hit some else charachter. Return false. 
	while( index < length && !isspace(string[index]) ) {
		if ( !isdigit(string[index]) ) {
			return false;
		}
		
		// add each new digit to temporary string
		integer_buffer[integer_chars] = string[index];
		integer_chars++;
		index++;
	}
	
	// Add this to end of the temporary string for further actions
	integer_buffer[integer_chars] = '\0';
	
	
	// check through whitespaces etc after last integer
	while ( isspace(string[index]) ) {
		index++;
	}
	
	// Return false is command line argument string is deformed
	if ( string[index] != '\0' ) {
		return false;
	}
	
	// convert our integer string into actual integer
	*integer = atoi(integer_buffer);
	
	// return true if no error arose in lines above
	return true;	
}

int askNumber() {

	// final integer is stored.
	int integer = 0;


	// keep track is or not parsed correctly, change which value depending on outcome of argument integer's format
	bool parsed_correct = true;
	
	do {
		printf("Enter integer: ");
		
		// here we store input string and we use this to call parse function
		char buffer[BUFFER_SIZE];
		
		// we store charachters entered into buffer charachter array
		// upto BUFFER_SIZE amount of charachters and not more
		fgets(buffer, BUFFER_SIZE, stdin);
		// store true or false into variable
		parsed_correct = parse_int(buffer, &integer);
				
		// if issues in parsing integer
		if ( !parsed_correct ) {
			printf("\n\nTraceback ( most recent call last):\n");
			printf("File: 'Sieve.c', line 29, in <module>\n");
			printf("   raise: Invalid input\n");
		}
		
	} while ( !parsed_correct );
	
	return integer;
	
	
	
	
}


// function fill array up to specific number 
bool fillArray( int upToNumber, int *array) {

	int filler = 2;
	// check can we even fill array if we are given too big number
	if ( upToNumber > ARRAYSIZE || upToNumber < LOW ) {
		printf("Traceback ( most recent call last):\n");
		printf("File: 'Sieve.c', line 29, in <module>\n");
		printf("   raise: Invalid input\n\n");

		return false;
		
	// fill array if everything good so far	
	} else {
		int counter = 0;
		// check base case was number 2 given or larger
		if ( upToNumber == LOW ) {
			printf("                 Numbers listed below are in allocated memory space [%d pcs]\n", 1 );
			printf("      Number at [%d] is %d\n", counter, filler);
			
		// larger than number 2
		} else {
			printf("                 Numbers listed below are in allocated memory space [%d pcs]\n", upToNumber-LOW+1 );
			while ( filler <= upToNumber ) {
				*( array + counter ) = filler;
				printf("      Number at [%d] is %d\n", counter, filler);
				counter++;
				filler++;
			}
		}
		
	}
	return true;
} 

// function to check for primes
void checkPrime( int upToNumber, int *array ) {
	
	printf("\n\n\n");
	printf("                 Prime numbers are listed below [%d - %d]\n",LOW, upToNumber );
	// loop through whole array
	for ( int index = 0; index < upToNumber-1; index++) {
		
		bool prime = true;
		// check for each value separetly is it prime or not
		for ( int index2 = 2; index2 <= ( *(array+index)/2 ); index2++) {
			
			// check is number prime or not
			if ( *(array+index) % index2 == 0 ) {
				prime = false;
			}
		}
		if ( upToNumber == LOW ) {
			printf("      * Prime: %d\n", LOW );
		}
		// print number if it is prime
		else if ( prime == true ) {
			printf("      * Prime: %d\n", *(array+index) );
		}		
	}
}












