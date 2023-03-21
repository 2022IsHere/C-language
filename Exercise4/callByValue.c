
// File: callByValue.c
// Author(s): Sebastian Sopola
// Description: call by value example in code

// import necessary libaries
#include <stdio.h>


// function call is defined with parameters variable1 and variable2
int call( int *variable1, int *variable2 ) {

	// Take * pointer tag off and you get call by value = local variable
	// Pointer * tag changes original value also
	int temp = 0;
	temp = *variable1;
	*variable1 = *variable2;
	*variable2 = temp;

	return 0;
}

int main () {

	int variable3 = 100;
	int variable4 = 200;
	printf("Before call, value of variable3 is: %d\n", variable3);
	printf("Before call, value of variable4 is: %d\n", variable4);


	// Calling call function
	// variable3 and variable 4 are within function when called
	// variable3 & 4 == arguments
	call(&variable3, &variable4);
	printf("After call, value of variable3 is: %d\n", variable3);
	printf("After call, value of variable4 is: %d\n", variable4);

	return 0;

}
