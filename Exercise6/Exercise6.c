
// File. Exercise6.c
// Author(s): Sebastian Sopola
// Description: Use pointers to fill, sort and print arrays. Hardcode and print 2D array. 

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 11
#define ROW 32
#define COLUMN 2

// print elements of array with pointer arithmetic
void printArray( int length, int *array ) {
	
	int counter = 1;
	
	while ( counter < length ) {
		printf("%d th element of array is %d\n",counter, *array);
		array++;
		counter++;
	}
}

// fill array with random numbers smaller than a million
void fillArray( int length, int *array ) {
	
	int random_number = 0;
	int counter = 0;
	srand(time(NULL));
	while ( counter < length ) {
		random_number = rand() % 11 + 1;
		*array = random_number;
		array++;
		counter++;
	}
}

// sort array of random numbers with pointers
void sortArray( int length, int *array ) {
	
	int number = 0;
	for ( int index1 = 0; index1 < length; index1++) {
		for( int index2 = index1+1; index2 < length; index2++) {
			if ( *(array+index1) < *(array+index2) ) {
				number= *(array+index1);
				*(array+index1) = *(array+index2);
				*(array+index2) = number;
			}	
		}
	}
}



// print NTC voltage table
void printTable( int voltage ) {

	int counter = 1;
	float array[ROW][COLUMN] = {{250, 1.4},{275, 4.0},{300, 6.4},{325,8.8},{350, 11.1}, {375, 13.4},{400, 15.6},{425, 17.8},
				    {450, 20.0},{475, 22.2}, {500, 24.4},{525, 26.7},{550, 29.0},{575, 31.3},{600, 33.7}, {625, 36.1},
				    {650, 38.7},{675, 41.3},{700, 44.1},{725, 47.1}, {750, 50.2},{775, 53.7},{784, 55.0},{825, 61.5},
				    {850, 66.2},{875, 71.5},{900, 77.9},{925, 85.7},{937, 90.3},{950, 96.0},{975, 111.2},{1000,139.5}	 
				   };
	
	printf("                         NTC table\n");
	
	// print NTC table
	for ( int index1 = 0; index1 < ROW; index1++) {
		printf("        [%d]th voltage is [%.0f] and temperature [%.1f]\n", counter,array[index1][0], array[index1][1]);
		counter++;
	}
	
	int num = 0;
	num = voltage;
	
	if ( num < 250 || num > 1000 ) {
		printf("\n              Voltage doesn't appear in the table\n");
	
	// check number and round it to closest possible 	
	} else if ( num >= 250 && num <= 262 ) {
		num = 250;
	} else if ( num >= 263 && num <= 286 ) {
		num = 275;
	} else if ( num >= 287 && num <= 311 ) {
		num = 300;
	} else if ( num >= 312 && num <= 336 ) {
		num = 325; 
	} else if ( num >= 337 && num <= 361 ) {
		num = 350;
	} else if ( num >= 362 && num <= 386 ) {
		num = 375;
	} else if ( num >= 387 && num <= 411 ) {
		num = 400;
	} else if ( num >= 412 && num <= 436 ) {
		num = 425;
	} else if ( num >= 437 && num <= 461 ) {
		num = 450;
	} else if ( num >= 462 && num <= 486 ) {
		num = 475;
	} else if ( num >= 487 && num <= 511 ) {
		num = 500;
	} else if ( num >= 512 && num <= 536 ) {
		num = 525;
	} else if ( num >= 537 && num <= 561) {
		num = 550;
	} else if ( num >= 562 && num <= 586 ) {
		num = 575;
	} else if ( num >= 587 && num <= 611 ) {
		num = 600;
	} else if ( num >= 612 && num <= 636 ) {
		num = 625;
	} else if ( num >= 637 && num <= 661 ) {
		num = 650;
	} else if ( num >= 662 && num <= 686 ) {
		num = 675;
	} else if ( num >= 687 && num <= 711 ) {
		num = 700;
	} else if ( num >= 712 && num <= 736 ) {
		num = 725;
	} else if ( num >= 737 && num <= 761) {
		num = 750;
	} else if ( num >= 762 && num <= 786 ) {
		num = 775;
	} else if ( num >= 787 && num <= 811 ) {
		num = 800;
	} else if ( num >= 812 && num <= 836 ) {
		num = 825;
	} else if ( num >= 837 && num <= 861) {
		num = 850;
	} else if ( num >= 862 && num <= 886 ) {
		num = 875;
	} else if ( num >= 887 && num <= 911 ) {
		num = 900;
	} else if ( num >= 912 && num <= 936 ) {
		num = 925;
	} else if ( num >= 937 && num <= 961) {
		num = 950;
	} else if ( num >= 962 && num <= 986 ) {
		num = 975;
	} else if ( num >= 987 && num < 1001 ) {
		num = 1000;
	} 
	
	// search for temperature value of given voltage
	int index = 0;
	while ( index < ROW ) {
		if ( array[index][0] == num ) {
			printf("\n            Temperature at voltage [%d] is %.1f Celsius\n", voltage, array[index][1]);
			break;
		}
		index++;
	}
}


int main () {
	
	// Check if user input appears in array
	int number = 0;
	printf("Give number:\n");
	scanf("%d", &number);
	if ( number < 1 || number > 999999 ) {
		printf("Number must be between 1 and 999 999. Otherwise I can not check if it is in the array or not\n\n\n");
	} else {
		int length = 0;
		length = SIZE;
		
		int array[SIZE] = {};
		int *arrayPointer = NULL;
		arrayPointer = &array[0];
		
		// call function to fill array with pointer
		fillArray(length, arrayPointer);
		
		// call function to sort filled array with pointer
		sortArray(length, arrayPointer);
		
		// call function to print array with pointer + clear space for another program output
		printArray(length, arrayPointer);
		printf("\n");
		
		// Check if user input appears in array
		int index = 0;
		for ( ; index < length; index++) {
			if ( *(arrayPointer + index ) == number ) {
				printf("Number [%d] appears first at '%p' in the array above\n\n",number, arrayPointer);
				break;
			}
		}
		
		// check if user input doesn't appear in array
		if ( index == length ) {
			int *arrayPointer = NULL;
			printf("Number doesn't appear in the array above therefore array pointer is %p\n\n", arrayPointer);
			}	
	}
	
	// print NTC temperature table
	printTable(number);
	
	
	return 0;
}








