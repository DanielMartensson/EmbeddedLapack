/*
 * lu.c
 *
 *  Created on: 11 feb. 2019
 *      Author: dell
 */

#include "declareFunctions.h"

/*
 * Do LU-factorization of a matrix A, size row x column, and get the L matrix, size row x column, and U matrix, size column x column.
 * Don't forget that the P matrix is the pivot matrix and have the size row x row
 */
void lu(double* A, double* L, double* U, double* P, int row, int column) {

	/*
	 * Solve PA = LU
	 */

	integer M = row;
	integer N = column;
	doublereal A_[row * column];
	memcpy(A_, A, row * column * sizeof(double));
	tran(A_, row, column); // Important!
	integer LDA = row;
	integer IPIV[row];
	integer INFO;

	// Solve!
	dgetrf_(&M, &N, A_, &LDA, IPIV, &INFO); // Added IPIV_d as last argument

	// Important
	tran(A_, column, row);

	// Create the L matrix
	memset(L, 0, row * column * sizeof(float));
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


	// Create U matrix
	triu(A_, U, 0, column, column);

	// Find the Pivot matrix from PA = LU -> P = LU*pinv(A), where A = P_
	double P_[row*column];
	double LU[row*column];
	mul(L, U, false, LU, row, column, column); // LU = L*U
	copy(A, P_, row, column); // A -> P_
	pinv(P_, row, column); // pseudo inverse of P_
	mul(LU, P_, false, P, row, column, row); // P_ have the size column x row after pseudo inverse

	// We need to round P
	for(int i = 0; i < row*row; i++)
		*(P+i) = round(*(P+i));

}

