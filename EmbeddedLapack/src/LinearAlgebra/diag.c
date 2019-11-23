/*
 * diag.c
 *
 *  Created on: 9 feb. 2019
 *      Author: Daniel Mårtensson
 */
#include "declareFunctions.h"

/*
 * Create a diagonal matrix B with the size row x column, of a vector A.
 * Notice that the row of vector A need to be the same length as the column of matrix B.
 */
void diag(double* A, double* B, int row_b, int column_b) {

	// Reset B
	memset(B, 0, row_b * column_b * sizeof(double));

	for (int i = 0; i < row_b; i++) {
		for (int j = 0; j < column_b; j++) {
			if (j == i) {
				*B = A[i];
				B += column_b + 1;
			}
		}
	}
}
