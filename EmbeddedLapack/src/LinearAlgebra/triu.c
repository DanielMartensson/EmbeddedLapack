/*
 * triu.c
 *
 *  Created on: 10 feb. 2019
 *      Author: Daniel Mårtensson
 */


#include "declareFunctions.h"

/*
 * Turn a matrix A, with size row x column, into a upper triangular matrix B, with size row x column
 */
void triu(double* A, double* B, int shift, int row, int column){

	// Reset our outut matrix B
	memset(B, 0, row*column*sizeof(double));

	// Compensator - Else, we cannot use non-square matrix
	int t = row - column;

	// Create a triangular matrix
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			// Do the "jump"
			if(j == 0){
				j = i + shift; // When we are at column 0 again, jump then n rows + shift at the right
			}
			// Write
			if(j != column)
				*((B + i*(row-t)) + j) = *((A + i*(row-t)) + j);
		}
	}
}
