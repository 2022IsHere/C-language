
// File: sum.c
// Author(s): Sebastian Sopola
// Description: count sum 



#include <stdio.h>

#define LOW 0


int main () {
	int num = 0;
	int num2 = 0;
	int num3 = 1;
	int num4 = 2;
	int sum = 0;
	int count = 0;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	// Check if num < or > 0
	if ( num == LOW || num < LOW ) {
		printf("Please give positive integer.\n");
	} else {
		while ( count < num ) {
	
		num2 = 	num3;
		num3 = num4;
		num4 = sum;
		sum = num2 + num3 + num4;
		count = count + 1;
	
		}
	printf("Here is your sum: %d\n", sum);
	
	}
	
	
	return 0;
}
