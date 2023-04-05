// File:	Sieve.h
// Author(s): Sebastian SOpola 		
// Description: Header file for Sieve.c and Exercise7.c


#ifndef SIEVE_H
#define SIEVE_H

// built-in libraries for specific use
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// integer string checking libs
#include <ctype.h>
#include <string.h>
#include <math.h>

// determine how many digits we need to allocate from memory for array
#define ARRAYSIZE 100

// determine starting point of prime number calculation
#define LOW 2

// string size limit, char limit for input integer string for correct form valuation
#define BUFFER_SIZE 4096

// declare functions we wish to share for other files to use
int askNumber();
bool parse_int();
bool fillArray();
void checkPrime();



#endif 

