/*
 * lu.c
 *
 *  Created on: 11 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Do LU-factorization of a matrix A, size row x column, and get the L matrix, size row x column, and U matrix, size column x column.
 * Don't forget that the P matrix is the pivot matrix and have the size row x row
 */
void lu(double* A, double* L, double* U, double* P, int row, int column) {

	/*
	 * Solve PA = LU - Same as MATLAB/Octave
	 * Normally, this subroutine compute A = PLU, but it's much better to follow the "MATLAB/Octave"-standard.
	 */

	integer M = row;
	integer N = column;
	doublereal A_[row * column];
	memcpy(A_, A, row * column * sizeof(double));
	tran(A_, row, column); // Important!
	integer LDA = row;
	integer IPIV[max(row, column)];
	double IPIV_d[max(row, column)];
	integer INFO;

	// Solve!
	dgetrf_(&M, &N, A_, &LDA, IPIV, &INFO, IPIV_d); // I've change the dgetrf so it will return a IPIV vector of doubles, due to memory loss.

	// Important
	tran(A_, column, row);

	if (column > row) {

		// Create U matrix
		memset(U, 0, row * column * sizeof(double));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				// This will create a upper triangular matrix.
				if (j >= i) {
					*((U + i * (row - (row - column))) + j) = *((A_
							+ i * (row - (row - column))) + j); // Lower traingular of A_
				}
			}
		}

		// Create the L matrix
		memset(L, 0, row * min(row, column) * sizeof(double));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				// This will create a lower triangular matrix.
				if (j < i) {
					*((L + i * (row)) + j) = *((A_ + i * (row - (row - column)))
							+ j); // Lower traingular of A_
				} else if (j == i)
					*((L + i * (row)) + j) = 1; // Only on diagonal
			}
		}

	} else {

		// Create U matrix
		triu(A_, U, 0, column, column);

		// Create the L matrix
		memset(L, 0, row * column * sizeof(double));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				// This will create a lower triangular matrix.
				if (j < i) {
					*((L + i * (row - (row - column))) + j) = *((A_
							+ i * (row - (row - column))) + j); // Lower traingular of A_
				} else if (j == i)
					*((L + i * (row - (row - column))) + j) = 1; // Only on diagonal
			}
		}

	}

	/*
	 * Insert all values 1 to row to our IPIV integer vector
	 */
	for (int i = 0; i < row; i++)
		IPIV[i] = i + 1;

	/*
	 * Change the IPIV - Swap the values
	 */

	for (int i = 1; i <= min(row, column); i++) {
		int temp = IPIV[(int) IPIV_d[i] - 1]; // the IPIV_d have values from index 1 to index column, that's why - 1
		//printf("IPIV %d\n", IPIV[i-1]); // test it!
		IPIV[(int) IPIV_d[i] - 1] = IPIV[i - 1];
		IPIV[i - 1] = temp;
	}

	// Find the permutation matrix P
	eye(P, row, row); // Turn P into a diagonal matrix
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			double swap1 = *(P + i * row + j);
			double swap2 = *(P + i * row + ((int) IPIV[i]) - 1);

			// Swap it!
			*(P + i * row + j) = swap2;
			*(P + i * row + ((int) IPIV[i]) - 1) = swap1;
			i++;
		}
	}

}

