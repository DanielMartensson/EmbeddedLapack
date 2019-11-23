/*
 * tril.c
 *
 *  Created on: 11 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Turn a matrix A, with size row x column, into a lower triangular matrix B, with size row x column
 */
void tril(double* A, double* B, int shift, int row, int column){


	// Reset our output
	memset(B, 0, row*column*sizeof(double));

	// Compensator - Else, we cannot use non-square matrix
	int t = row - column;

	// Create a triangular matrix
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){

			// This will create a lower triangular matrix. Shift make sure that we can step shift steps to the right
			if(j <= i + shift){
				*((B + i*(row-t)) + j) = *((A + i*(row-t)) + j);
			}
		}
	}

}
