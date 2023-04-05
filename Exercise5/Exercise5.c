
// File: Exercise5.c
// Author(s): Sebastian Sopola
// Description: command line input validation, Find armstrong number between 0 and given up limit,


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


#define LOW 0
#define TOP 2
#define INDEX 1
#define ARRAY_SIZE 10



// find all possible armstrong numbers between 0 and given integer
int isArms(int lower, int upper) {

	int index = 0;
	int digits = 0;
	int number = 0;
	int remainder = 0;
	int count = 0;
	float sumPow = 0.0;
	int low = 0;
	int up = 0;
	low = lower;
	up = upper;
	
	
	printf("Armstrong numbers between %d and %d are: \n", low,up);
	
	// Loop through numbers between 0 and up 
	for (index = low ; index < up+1; index++) {
		digits = index;
		number = index;
		
		// calculate how many digits. Example: 371/10 = 37 ( count 1), 37/10 = 3 ( count 2), 3/10 = 0 ( count 3)
		while ( digits != 0 ) {
			digits /= 10;
			count++;
		}
		
		// calculate sum of nth power of every digit
		while ( number != 0 ) {		    	  // number = 371           // number 37
			remainder = number % 10;   	 // 371 % 10 = 1,          // 37 % 10 = 7
			sumPow += pow(remainder, count);// pow(1, 3)              // pow(7,3)
			number /= 10;		       // number / 10 = 37 now   // number / 10 = 3
		}
		
		// check if it is an armstrong number
		if ( (int)sumPow == index ) {
			printf("%d ", index);
		}
		
		// refresh variables count & sumPow
		count = 0;
		sumPow = 0;
	}
	
	


	return 0;
}


// print argument array with it's length
void printArray( int length, int *array ) {
	int len = 0;
	len = length;
	int arr[ARRAY_SIZE] = {};
	
	
	// add all elements from array argument to new array variable
	for (int index = 0; index < len; index++) {
		arr[index] = array[index];
	}
	printf("\n\n\n");
	printf("<- Random numbers in the array between 0 and under a million are listed below -> \n");
	for (int index = 0; index < len; index++) {
		printf("           Random element in the array is %d at position [%d]\n", arr[index], index);
	}
	
	printf("\n\n\n");
}

// generate array of size 10 with integers smaller than a million
int * generateArray(int length, int *array) {
	int leng = length;
	static int arra[ARRAY_SIZE] = {};
	for (int index = 0; index < leng; index++) {
		arra[index] = array[index];
	}
	
	srand(time(NULL));
	for (int index = 0; index < leng; index++) {
		arra[index] = rand() % 999999;
	}
	printf("\n\n");
	
	return arra;
}

int * sortArray(int length, int *array) {
	int num = 0;
	int len = 0;
	len = length;  
	static int arr[ARRAY_SIZE] = {};
	
	// put elements from input array to local array
	for (int index = 0; index < len; index++) {
		arr[index] = array[index];
	}
	
	for (int index1 = 0; index1 < len; index1++) {
		for (int index2 = index1+1; index2 < len; index2++) {
			if (arr[index1] > arr[index2] ) {
				num = arr[index1];
				arr[index1] = arr[index2];
				arr[index2] = num;		
			}
		}
	}
	
	
	return arr;
}




int main (int argc, char *argv[]) {

	// task 3
	bool state = true;
	int integer = 0;
	
	// check that user gave one integer
	if ( argc > TOP ) {
		state = false;
		printf("You are allowed to give only one integer\n");
	
	} else if ( argc < TOP && argc > LOW ) {
		state = false;
		printf("You didn't give integer\n");
	
	// Check user input
	} else {
		int length = 0;
		length = strlen(argv[INDEX]);
		bool status = true;
		
		// Check every charachter from input
		for (int index = 0; index < length; index++) {
			if ( !isdigit(argv[INDEX][index]) ) {
				status = false;
				state = false;
				printf("Not integer\n");
				break;
			} 
		}
		// Give integer if user input is correct
		if ( status != false ) {
			integer = atoi(argv[INDEX]);
		} 
	}
	
	// print integer only and only if any error blocks havent been triggered before
	while ( state != false ) {
		printf("Integer: %d\n", integer);
		break;
	}
	
	// check falidity of integer for calculating armstrong numbers
	if ( state != false ) {
		isArms(0,integer);
	} else {
		printf("Sorry, we can not give armstrong numbers in given range due to unproper integer\n");
	}
	
	// task 4
	
	// generate random array of size then
	int length = ARRAY_SIZE;
	int array[ARRAY_SIZE] = {};
	int *resultArray;
	resultArray = generateArray(length, array);
	
	// print unsorted array 
	printArray(length, resultArray);
	
	// print sorted array
	int *sortedArray;
	sortedArray = sortArray(length, resultArray);
	printArray(length, sortedArray);
	

	return 0;
}
















