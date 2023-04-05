
// File: demoFile.c
// Author(s): Sebastian Sopola
// Description: Demo file how to use pointers

#include <stdio.h>

int main () {
	
	
	int number = 0;
	char elem = 0;
	float num = 0.0;
	
	printf("int number %d\nchar elem %d\nfloat num %.1f\n", number, elem, num);
	
	int *pointer1 = NULL;
	char *pointer2 = NULL;
	float *pointer3 = NULL;
	
	
	pointer1 = &number;
	pointer2 = &elem;
	pointer3 = &num;
	
	printf("pointer1 memory address is %p and value there is %d\n", pointer1, *pointer1);
	printf("pointer2 memory address is %p and value there is %d\n", pointer2, *pointer2);
	printf("pointer3 memory address is %p and value there is %.1f\n", pointer3, *pointer3);



	return 0;
}


