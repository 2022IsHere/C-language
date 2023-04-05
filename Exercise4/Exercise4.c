

// File: Exercise4.c
// Author(s): Sebastian Sopola
// Description: take user input as integers and make actions based on input


// import necessary libaries
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>




// macroes
#define ARRAY_SIZE  30
#define LOWLOW 60
#define LOW 72
#define OK 84
#define HIGH 96	
#define HIGHHIGH 108

// string size limit
#define BUFFER_SIZE 4096

// Gets integer as string argument
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


// CHeck whether input number is prime number or not
int ifPrime( int value ) {
	
	if ( value < 0 ) {
		value = 0;
		return value;
	} else {
		value = 1;
		return value;
	}	
}



// random number between two input parameters
int randNum(int num1, int num2) {

	int random_number = 0;
	
	// Check which number is greater
	if ( num1 > num2 ) {
		srand(time(NULL));
		random_number = num2 + ( rand() % ( num1-num2+1 ));
		printf("Random_number: %d\n", random_number);
	}
	
	if ( num2 > num1 ) {
		srand(time(NULL));
		random_number = num1 + ( rand() % ( num2-num1+1 ));
		printf("Random_number: %d\n", random_number);
	}	
	return random_number;
}

// Tell user their grade based on random number generated
int tellGrade(int value) {
	
	int points = 0;
	points = value;
	
	// Check if points are negative
	if ( 0 < points && points <= 120 ) {
		
		// calc wich grade you get based on points
		if ( points < 60 ) { 
			return 0; 
		
		} else if ( LOWLOW <= points && points <= LOW ) { 
			return 1; 
		
		} else if ( LOW <= points && points <= OK ) { 
			return 2; 
		
		} else if ( OK <= points && points <= HIGH ) { 
			return 3; 
		
		} else if ( HIGH <= points && points <= HIGHHIGH ) { 
			return 4; 
		
		} else { 
			return 5; 
		}
	}
	return 0;	
} 

// sum divided by 3
void inputSumDevision () {

	int sum = 0;
	int number = 0;
	
	// read input
	for ( int i = 0; i < INT_MAX; i++ ) {
		printf("Please, enter integer: ");
		
		// if number
		if ( scanf("%d", &number) == 1 ) {
		
			// if positive number
			if ( number > 0 && number % 3 == 0 ) {
				sum += number;
			// if 0	
			} else if ( number == 0 )  {
				printf("You entered number 0. Program has shutdown now.\n");
				printf("Here is sum of all numbers you entered: %d\n", sum);
				break;
			}
		// if not number
		} else if ( scanf("%d", &number) != 1 ) {
			printf("Integers omly!\n");		
		}	
	}
}



// count sum of user inputs
void inputSum () {

	int sum = 0;
	int number = 0;
	
	// read input
	for ( int i = 0; i < INT_MAX; i++ ) {
		printf("Please, enter integer: ");
		
		// if number
		if ( scanf("%d", &number) == 1 ) {
		
			// if number 0
			if ( number == 0 ) {
				printf("You entered number 0. Program has shutdown now.\n");
				printf("Here is sum of all numbers you entered: %d\n", sum);
				break;
				
			} else {
				sum += number;
				continue;			
			}
	
		// if not number
		} else if ( scanf("%d", &number) != 1 ) {
			printf("Integers omly!\n");		
		}
	}
}

// read numbers user gives until user gives number 0. print all negatives
void inputNegNums() {

	int arr[ARRAY_SIZE] = {};
	int counter = 1;
	int number = 0;
	
	// Get user input as integers, list negative numbers into an array
	for ( int i = 0; i < INT_MAX; i++ ) {
		printf("Please, enter integer: ");
		 
		// if number
		if ( scanf("%d", &number) == 1 ) {
		
			// if number 0
			if ( number == 0 ) {
				if ( counter < 2 ) {
					printf("You entered number 0. Program has shutdown now\n");
					break;
				
				// print negative numbers only if user gave one
				} else {
					printf("You entered number 0. Program has shutdown now\n");
					printf("Here are negative numbers you gave: \n");
				
					// print negative numbers
					while ( counter > 2 ) {
						printf("%d ", arr[counter-1]);
						counter -= 1;
					
					}
					if ( counter == 2 ) {
						printf("%d\n", arr[1]);
						break;
					}
				}
				
			// if number negative	
			} else if ( number < 0 ) {
				arr[counter] = number;
				counter += 1;	
			}
		
		// if not number
		} else if ( scanf("%d", &number) != 1 ) {
			printf("Integers omly!\n");		
		}
	  
	}
  	
}

int main () {

	//inputNegNums(); 
	//inputSum();
	//inputSumDevision();
	//randNum(-100,100);
	
	// Determine grade saving random number into grade function parameter
	// int rn = 0;
	//int rn = randNum(0, 120);
	//int grade = tellGrade(rn);
	//printf("Here is your grade: %d\n", grade);
	
	
	
	// final integer is stored.
	int integer = 0;
	// keep track is or not parsed correctly
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
			printf("Must be an integer value!\n");
		}
		
	} while ( !parsed_correct );
	
	// print prime or not if input is parsed correctly
	int value = 0;
	value = ifPrime(integer);
	printf("Here below is final result. If it is 1. Input integer is prime number. Otherwise result is 0 which means integer isn't prime number.\n");
	printf("Here is result: %d\n", value);
	
	
	
	return 0;

}
