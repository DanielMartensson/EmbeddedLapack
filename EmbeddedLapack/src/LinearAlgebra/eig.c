/*
 * eig.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

void loadEigen(integer row, doublereal* wr, doublereal* wi, double* Ereal, double* Eimag);
void loadVector(integer N, doublereal* wi, doublereal* v, double* Vreal, double* Vimag);

/*
 *	Solve the eigenvalue problem
 *	A size row x row
 *	Ereal size row x 1 - Eigenvalues real part
 *	Eimag size row x 1 - Eigenvalues imag part
 *	Vreal_left size row x row - Eigenvectors real left
 *	Vimag_left size row x row - Eigenvectors imag left
 *	Vreal_right size row x row - Eigenvectors real right
 *	Vimag_right size row x row  - Eigenvectors imag right
 */

void eig(double* A, double* Ereal, double* Eimag, double* Vreal_left,
		double* Vimag_left, double* Vreal_right, double* Vimag_right, int row) {
	/* Locals */
	integer N = row;
	integer LDA = row;
	integer LDVL = row;
	integer LDVR = row;
	integer INFO;
	integer LWORK;
	doublereal wkopt;
	doublereal WORK[row * row];
	doublereal WR[row];
	doublereal WI[row];
	doublereal VL[row * row];
	doublereal VR[row * row];

	// Load the A_ matrix
	doublereal A_[row * row];
	memcpy(A_, A, row * row * sizeof(double));
	tran(A_, row, row);

	LWORK = -1; // This will load values
	dgeev_("V", "V", &N, A_, &LDA, WR, WI, VL, &LDVL, VR, &LDVR, &wkopt, &LWORK,
			&INFO);
	LWORK = (int) wkopt;

	/* Solve eigenproblem */
	dgeev_("V", "V", &N, A_, &LDA, WR, WI, VL, &LDVL, VR, &LDVR, WORK, &LWORK,
			&INFO);

	tran(VL, N, N);
	tran(VR, N, N);

	/*
	 * Load the values into the mats
	 */
	loadEigen(N, WR, WI, Ereal, Eimag);
	loadVector(N, WI, VL, Vreal_left, Vimag_left);
	loadVector(N, WI, VR, Vreal_right, Vimag_right);


}

void loadEigen(integer N, doublereal* WR, doublereal* WI, double* Ereal, double* Eimag) {

	for (int j = 0; j < N; j++) {
		if (WI[j] == (double) 0.0) {
			//printf(" %6.2f", WR[j]);
			*(Ereal++) = WR[j];
			*(Eimag++) = 0;
		} else {
			//printf(" (%6.2f,%6.2f)", WR[j], WI[j]);
			*(Ereal++) = WR[j];
			*(Eimag++) = WI[j];
		}
	}
}

void loadVector(integer N, doublereal* WI, doublereal* V, double* Vreal, double* Vimag) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(WI[j] == (double) 0.0){
				*(Vreal + i*N + j) = *(V + i*N + j);
				*(Vimag + i*N + j) = 0.0;
			}else{
				*(Vreal + i*N + j) = *(V + i*N + j);
				*(Vreal + i*N + j+1) = -*(V + i*N + j);
				*(Vimag + i*N + j) = *(V + i*N + j+1);
				*(Vimag + i*N + j+1) = -*(V + i*N + j+1);
				j++;
			}
		}
	}

}

