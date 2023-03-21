

// File: fillArray.c
// Author(s): Sebastian Sopola
// Description: add n number of elements to array of size 100


#include <stdio.h>

#define ARRAY_SIZE 100
#define LOW 0

void createArray() {

	int index = 0;
	int integer = 0;
	int arr[ARRAY_SIZE] = {0,0,0};
	
	printf("Enter total number of elements (1 to 100): ");
	scanf("%d", &integer);
	
	if ( integer < LOW || integer == LOW ) {
		printf("Please give positive integer.\n");
		
	} else {
		for (int index = 0; index < integer; index++) {
		arr[index]  = index;
		}
	
		printf("We have added %d elements to array\n", integer);
		printf("First element of array is %d\n", arr[index]);
	}
}

int main() {

	createArray();
	
	return 0;
}
