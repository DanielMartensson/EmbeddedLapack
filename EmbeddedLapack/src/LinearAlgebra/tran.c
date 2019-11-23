/*
 * tran.c
 *
 *  Created on: 8 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Take the transpose of a matrix A, with the dimension row x column. The result will be A' with the dimension column x row
 */
void tran(double* A, int row, int column) {

	double B[row*column];
	double* transpose;
	double* ptr_A = A;

	for (int i = 0; i < row; i++) {
		transpose = &B[i];
		for (int j = 0; j < column; j++) {
			*transpose = *ptr_A;
			ptr_A++;
			transpose += row;
		}
	}

	// Copy!
	memcpy(A, B, row*column*sizeof(double));

}
