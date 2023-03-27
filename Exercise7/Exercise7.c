// File:	Exercise7.c
// Author(s): Sebastian Sopola		
// Description: Run Sieve algoritm from another file amd use memory allocation 

// header files of source codes
#include "Sieve.h"
#include "Matrix.h"



int main() {

	// memory allocation for array
	int *memoryPointer = NULL;
	memoryPointer = (int*) malloc(ARRAYSIZE * sizeof(int));
	
	// check that memory allocation was successfull
	if ( memoryPointer == NULL ) {
		printf("\n\nTraceback ( most recent call last):\n");
		printf("File: 'Exercise7.c', line 17, in <module>\n");
		printf("   raise: Memory allocation was unsuccessfull due to unkown error\n");
	}
	
	
	int integer = 0;
	integer = askNumber();
	
	// check can we run Primecheck
	if ( fillArray(integer, memoryPointer) == true ) {
		checkPrime(integer, memoryPointer );
	}
	
	
	// free memory after use
	free(memoryPointer);
	
	// --------------------------------------------------------------------------------------------------------------
	const int array[SIZE][SIZE] = {
	{ 3,  2, 21, 29, 43, 15, 00, 40, 00, 18,  4,  5,  9, 93, 51, 22, 50, 98, 82,  3},
	{46, 46, 88, 40, 29, 32,  1, 59, 50, 39, 28, 40, 83, 74, 58, 43,  4, 55, 52, 00},
	{32, 36, 31, 83, 55, 88, 14, 29, 94, 91, 30, 59, 54, 33, 30,  4, 39, 23, 13, 55},
	{51, 90, 18, 14,  4, 50, 11, 41, 59, 13, 62, 55,  2, 32, 55, 92, 32,  1, 14, 81},
	{12, 32, 25, 82, 52, 58, 54, 38, 32, 82, 14, 54, 11, 40, 40,  1, 55, 74, 14, 30},
	{14, 48, 41, 50, 88,  4, 14,  1, 74, 18, 74, 54, 93, 14, 34, 10, 14, 19, 11, 50},
	{41, 93, 31,  1, 54, 14, 59, 10, 25, 43, 40, 59, 59, 54, 90, 55,  1, 43, 54, 88},
	{59, 25, 20, 61,  1, 52, 22, 20, 18, 54, 94, 42, 54,  3, 40, 92, 55, 49, 94, 22},
	{24, 55, 62,  5, 55, 94, 99, 25, 99, 29, 93, 93, 18, 34, 14, 33, 74, 89, 54, 91},
	{11, 14, 14,  9, 18, 00, 18, 74, 10, 14, 14, 14, 00, 52, 74, 99, 94, 42, 74, 18},
	{93, 29, 54,  1, 22, 18, 42, 59, 25, 93,  3, 30,  3, 52, 25, 93,  9, 53, 55, 92},
	{25, 42,  5, 42, 18, 14, 42, 49, 55, 62, 33, 24, 00, 29, 53, 24, 13, 29, 35, 59},
	{35, 55, 00, 43, 14, 92, 39,  9,  5, 73, 73, 39, 74, 50, 22, 62, 52, 54, 29, 62},
	{29, 30, 32, 62,  5, 94, 46, 59,  1, 93, 92, 23, 35, 52, 29, 99,  3, 39, 55, 30},
	{ 4, 52,  3, 34, 99, 14, 99, 25,  9, 99, 59, 42, 25, 25, 25, 99, 74, 29, 93, 55},
	{33, 14, 62, 39, 59, 52, 20, 92,  3, 13, 73, 59, 13, 55, 22, 32, 54, 94, 54, 59},
	{ 4, 42, 25, 94, 43, 25, 46, 22, 24, 94, 92,  1,  3, 14, 29, 42, 40, 52, 18, 13},
	{20, 58, 14, 42, 82, 40, 24, 33, 73, 52, 99, 59, 32, 58, 58, 35, 93,  4, 14, 25},
	{20, 94, 14, 29, 93, 42, 90,  2, 84, 42, 46, 82, 43, 35, 32, 25, 24, 58,  5, 54},
	{ 2, 80, 54, 82, 34, 52, 54, 59, 25, 92, 74, 43, 52, 74, 52,  2, 39, 29, 59, 43}
	};
	
	testMatrix();
	/*
	horizontalSum(array); // 379
	
	verticalSum(array);  // 374 
	
	diagonalSum(array); // 458
	*/
	
	result(diagonalSum(array), verticalSum(array), horizontalSum(array));
 	
 		
 
    return 0;
}





