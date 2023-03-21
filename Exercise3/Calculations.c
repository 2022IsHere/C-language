
// File: Calculations.c
// Author(s): Sebastian
// Discription: Fibonacci sequence, Collatz sequence, multiplications, sumEvenNumbers, sum between a and b

// Load necessary libaries
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>


// Calculate Fibonacci sequence for random number between 0 and 99 999
// Rule: X[n] = X[n-1 + X[n-2]
void fibonacci() {

	int random_number = 0;
	int arr[30] = {0,1,1};
	int result = 0;
	int index = 3;


	// Generate random number
	// srand(time(NULL));
	// random_number = rand() % 10 + 0;
	random_number = 6;

	// Make sure random number is positive
	if ( random_number < 0 ) {
		random_number = random_number*(-1);
	}


	// Calculate base cases for fibonacci sequence
	if ( random_number == 0 ) {
		printf("Fibonacci sequence: %d\n", arr[0]);


	} else if ( random_number == 1 ) {
		printf("Fibonacci sequence: %d - ", arr[0]);
		printf("%d\n", arr[1]);


	} else if ( random_number == 2 ) {
		printf("Fibonacci sequence: %d - ", arr[0]);
		printf("%d - ", arr[1]);
		printf("%d\n", arr[2]);


	// Calculate fibonacci sequence if none of the base cases aren't TRUE
	} else if ( random_number == index ) {
		printf("Fibonacci sequence: %d - ", arr[0]);
		printf("%d - ", arr[1]);
		printf("%d - ", arr[2]);

		result = arr[index-1] + arr[index-2];
		arr[index] = result;
		printf("%d\n", result);


	// Calculate fibonacci sequence if none of the base cases aren't TRUE
	} else {
		printf("Fibonacci sequence: %d - ", arr[0]);
		printf("%d - ", arr[1]);
		printf("%d", arr[2]);

		// Use for loop to calculate each item of sequence to random number
		for ( int index = 3; index < random_number+1; index++) {
			result = arr[index-1] + arr[index-2];
			arr[index] = result;
			printf(" - %d", result);


		}

	}



}

// Calculate collatz sequence with random number
void collatzSequence() {

	int random_number = 0;
	int counter = 0;

	// Generate random number
	// srand(time(NULL));
	// random_number = rand() % 10 + 0;
	random_number = 13;


	// Check whether number is 0, 1 or higher
	if ( random_number == 0 ) {
		printf("No Collatz sequence with number 0.\n");
	} else if ( random_number == 1 ) {
		counter += 1;
		printf("Collatz sequence: %d\n", random_number);
	} else {
		counter += 1;
		printf("Collatz sequence: %d - ", random_number);


	while ( random_number > 1 ) {


		// onko parillinen, onko pariton, onko 1
		if ( random_number % 2 == 0 ) {
			if ( random_number == 2 ) {
				counter += 1;
				random_number = random_number/2;
				printf("%d\n", random_number);
			} else {
				counter += 1;
				random_number = random_number/2;
				printf("%d - ", random_number);
			}
		} else if ( random_number % 2 != 0 ) {
			counter += 1;
			random_number = random_number*3+1;
			printf("%d - ", random_number);

		} else {
			printf("%d", random_number);
		}
	}

	}

	printf("The length of the sequence: %d\n\n", counter);




}

// Calculate multiplications with random number
void multiply() {

	int random_number = 0;
	int result = 0;

	// Generate random number
	srand(time(NULL));
	random_number = rand() % 20 + 2;


	// Check whether random number is zero or 1
	if ( random_number == 0 ) {
		printf("Random number: %d\n", random_number);
		printf("No multiplication made with zero");
	} else if ( random_number == 1) {
		printf("Random number: %d\n", random_number);
		printf("No multiplication with 1");
	} else {

		result = random_number*random_number;

		// If random number over 0, It is multiplied by itself until result reaches
		// Max value for integer type
		printf("Random number: %d\n", random_number);
		printf("Result of multiplication: %d\n", result);
		while ( result < 46345 || result < -46345 ) {
			result = result*result;
			printf("Result of multiplication: %d\n", result);
		}

		printf("Result has to be under 46 345 or it exceeds integer type limit, (INT_MAX %d)\n\n\n", INT_MAX);


	}


}


// Calculate sum of even numbers between a and b
void sumEvenNumbers() {

	int sum = 0;

	// Calculate sum of even numbers between 1 to 1 000
	for ( int i = 0; i < 1000+1; i++ ) {
		if ( i % 2 == 0 ) {
			sum += i;
		} else {
			continue;
		}


	}
	printf("Sum of even numbers between 1 to 1 000: %d\n\n", sum);



}


// Calculate sum of numbers between a b b
int main () {

	int sum = 0;

	// Calculate sum of numbers 1 to 100
	for ( int i = 0; i < 100+1; i++ ) {
		sum += i;

	}
	printf("\n\nSum of numbers from 1 to 100: %d\n\n", sum);



	sumEvenNumbers();
	multiply();
	collatzSequence();
	fibonacci();





	return 0;
}



