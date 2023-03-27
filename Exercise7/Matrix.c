// File:	Matrix.c
// Author(s):	Sebastian Sopola 		
// Description: Use harcoded 2D array 20x20 to find max sum of 5 adjacent. 
//		Could be left <-> right
//			 top <-> down
//			 diagonal lefthand corner <-> righthand corner

// all necessary libraries are in this header file 
#include "Matrix.h"

// function to return maxSum of matrix with 5 consecutive sequence in any fashion
void result( int diagonal, int vertical, int horizontal ) {

	if ( diagonal > vertical && horizontal ) {
		printf("\n      Greatest number of 5 adjacent numbers in matrix is in diagonal fashion -%d-\n\n", diagonal);
	}
	
	else if ( vertical > diagonal && horizontal ) {
		printf("\n      Greatest number of 5 adjacent numbers in matrix is in vertical fashion -%d-\n\n", vertical);
	}	
	
	else if ( horizontal > diagonal && vertical ) {
		printf("\n      Greatest number of 5 adjacent numbers in matrix is in horizontal fashion -%d-\n\n",horizontal);
	}
	
}


// function find sum of 5 adjency element in diagonal direction
int diagonalSum( int(*array)[SIZE] ) {
	
	int maxSum = 0;
	
	
	// LEFT -> RIGHT 
	// loop through rows
	for ( int row = 0; row < LIMIT; row++) {
		// loop throgh columns on a row
		for ( int column = 0; column < LIMIT; column++) {
			int sum = 0;
			// loop through element in 5 consecutive sequence
			for ( int k = 0; k < 5; k++) {
				sum += array[row+k][column+k];
			}
			
			if ( sum > maxSum ) {
				maxSum = sum;
			}
		}
	}
	
	
	
	// RIGHT -> LEFT
	// loop through rows
	for ( int row1 = 0; row1 < LIMIT; row1++) {
		// loop through columns on a row
		for ( int column1 = 19; column1 > LO; column1--) {
			int sum1 = 0;
			// loop through element in 5 consecutive sequence
			for ( int k1 = 0; k1 < 5; k1++) {
				sum1 += array[row1+k1][column1-k1];
			}	
			if ( sum1 > maxSum ) {
				maxSum = sum1;
			}			
		}
				
	}
	
		
	
	 printf("      * Max sum of diagonal: %d\n",maxSum);
	return maxSum;
}


// function find sum of 5 adjency elements in vertical direction
int verticalSum( int (*array)[SIZE] ) {

	int maxSum = 0;
	// loop through rows
	for ( int row = 0; row < LIMIT; row++) {
		// loop through columns on a row
		for ( int column = 0; column < SIZE; column++) {
			int sum = 0;
			// loop through element in 5 consecutive sequence
			for ( int k = 0; k < 5; k++) {
				sum += array[row+k][column];
			}
			if ( sum > maxSum ) {
				maxSum = sum;
			}	
		}
	}
	printf("      * Max sum of vertical: %d\n",maxSum);
	return maxSum;
}


// function to find sum of 5 adjency elements in horisontal direction
int horizontalSum( int (*array)[SIZE] ) {
	
	
	int maxSum = 0;
	
	// loop through rows
	for ( int row = 0; row < SIZE; row++) {
		// loop through columns on a row
		for ( int column = 0; column < LIMIT; column++) {
			int sum = 0;
			// loop through columns in 5 consecutive sequence
			for ( int k = 0; k < 5; k++) {
				sum += array[row][column+k];
			}
			if ( sum > maxSum ) {
				maxSum = sum;
			}
		}
	}
	printf("      * Max sum of horisontal: %d\n",maxSum);
	return maxSum;
}



void testMatrix() {

	printf("\n                 Hi, I will be calculating 20x20 2D matrix for you\n\n");
	
		


}



