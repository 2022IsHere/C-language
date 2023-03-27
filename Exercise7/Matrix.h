// File:	Matrix.h
// Author(s): Sebastian Sopola 		
//Description: Header file for Matrix.c and Exercise7.c
 

#ifndef MATRIX_H
#define MATRIX_H

// built-in libraries for specific use
#include <stdio.h>


// size of 2D matrix 20x20
#define SIZE 20

// 5 elements for sum
#define ADJACENCY 5

// 15 times to select 5 consecutives for sum
#define LIMIT 16
#define LO 3


// declare functions we wish to share for other files to use
void result();
int horizontalSum();
int verticalSum();
int diagonalSum();
void testMatrix();

#endif 

