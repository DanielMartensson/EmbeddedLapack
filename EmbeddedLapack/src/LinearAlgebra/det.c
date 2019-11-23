/*
 * det.c
 *
 *  Created on: 12 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Find the determiant of a square matrix A with size row x row
 */

double det(double *A, int row) {

	if (row == 1) {
		// 1x1 "matrix" - Just return the value
		return *(A);
	} else if (row == 2) {
		// 2x2 matrix - Easy
		return *(A + 0) * *(A + 3) - *(A + 1) * *(A + 2);
	} else if (row == 3) {

		// Don't change this! It works fine for 3x3 - Took me long time to write this
		return (*(A + 0)) * (*(A + 4)) * (*(A + 8))
				+ (*(A + 1)) * (*(A + 5)) * (*(A + 6))
				+ (*(A + 2)) * (*(A + 3)) * (*(A + 7)) -

		(*(A + 6)) * (*(A + 4)) * (*(A + 2))
				- (*(A + 7)) * (*(A + 5)) * (*(A + 0))
				- (*(A + 8)) * (*(A + 3)) * (*(A + 1));

	} else {

		double mat[row][row];
		double ratio;
		double determinant = 1; // Initial det value

		// We need to create the matrix into an array matrix, like a normal matrix again
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++) {
				mat[i][j] = *((A + i * row) + j);
			}
		}

		// Gauss Elimination Easy and fast algorithm to find the determinant of a nxn matrix
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++) {
				if (j > i) {
					// We cannot divide with zero
					if (mat[i][i] == 0){
						mat[i][i] = powf(2.2204, -16); // Same as MATLAB command eps
					}
					ratio = mat[j][i] / mat[i][i];
					for (int k = 0; k < row; k++) {
						mat[j][k] -= ratio * mat[i][k];
					}
				}
			}
		}

		// Find det
		for (int i = 0; i < row; i++) {
			determinant *= mat[i][i];
		}

		return determinant;
	}
}
