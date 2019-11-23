/*
 * linsolve.c
 *
 *  Created on: 8 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Solve a Ax=B system by setting A, X, B as double matrix and also row for A, X and B and column_b for X and B.
 * Notice that A need to be a square matrix, so row x row as dimension, but the B matrix can have more columns than rows, so row x column_b.
 */
void linsolve(double* A, double* X, double* B, int row, int column_b) {

	integer N = row;
	integer NRHS = column_b;
	integer LDA = row;
	doublereal A_[row*row];
	memcpy(A_, A, row*row*sizeof(double));
	tran(A_, row, row); // Important to take the transpose because it's FORTRAN we calling via C
	integer IPIV[row];
	integer LDB = row;
	doublereal B_[row*column_b];
	memcpy(B_, B, row*column_b*sizeof(double));
	tran(B_, row, column_b); // Important to take the transpose because it's FORTRAN we calling via C
	integer INFO;

	// Call dgesv from FORTRAN
	dgesv_(&N, &NRHS, A_, &LDA, IPIV, B_, &LDB, &INFO);

	// Copy the solution
	memcpy(X, B_, row*column_b*sizeof(double));
	tran(X, column_b, row);

}
