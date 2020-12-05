/*
 * mul.c
 *
 *  Created on: 10 feb. 2019
 *      Author: Daniel Mårtensson
 */
#include "declareFunctions.h"

/*
 * Multiply A with size row_a x column_a with matrix B with size column_a x column_b and get matrix C with row_a x column_b
 */

void mul(double* A, double* B, bool elementWise, double* C, int row_a, int column_a, int column_b) {

	/*
	 * C = A*B if elementWise = false
	 * C = A.*B if elementWise = true
	 */

	// Data matrix
	double* data_a = A;
	double* data_b = B;
	//double* C = C; // No need

	if (elementWise == true) {

		// Dot multiply all values
		if (column_b > 1) { // If matrix b is a matrix
			for (int i = 0; i < row_a; i++) {
				for (int j = 0; j < column_a; j++) {
					// Do element wise mutiplication. In MATLAB it is A.*A
					*(C++) = *(data_a++) * *(data_b++);
				}
			}
		} else {
			// If matrix b is a vector
			for (int i = 0; i < row_a; i++) {
				for (int j = 0; j < column_a; j++) {
					// Do element wise mutiplication. In MATLAB it is A.*b
					*(C++) = *(data_a++) * *(data_b + i);
				}
			}
		}

	} else {
		// Do regular mutiplication. In MATLAB it is A*A
		// Let's take our a matrix
		for (int i = 0; i < row_a; i++) {

			// Then we go through every column of b
			for (int j = 0; j < column_b; j++) {
				data_a = &A[i * column_a];
				data_b = &B[j];

				*C = 0; // Reset
				// And we multiply rows from a with columns of b
				for (int k = 0; k < column_a; k++) {
					*C += *data_a * *data_b;
					data_a++;
					data_b += column_b;
				}
				C++;
			}
		}
	}
}
