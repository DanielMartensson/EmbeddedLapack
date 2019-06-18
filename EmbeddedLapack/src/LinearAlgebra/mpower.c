/*
 * mpower.c
 *
 *  Created on: 19 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * This is the almost the same as powe, power on every element, but the difference is that this function
 * does not take power on each element, it does A^n
 * A will be size row x row. It must be square!!!
 * A^n and n will be an integer
 */

void mpower(double* A, int row, int n) {
	double T[row * row];
	double T2[row * row];
	zeros(T, row, row);
	zeros(T2, row, row);

	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			eye(T, row, row); // Identity matrix will return
		} else if (i == 1) {
			copy(A, T, row, row); // A - > T
		} else if (i == 2) {
			mul(A, A, false, T, row, row, row); // T= A*A;
		} else {
			mul(A, T, false, T2, row, row, row); // T2 = A*T
			copy(T2, T, row, row); // T2 -> T
		}
	}
	copy(T, A, row, row); // T -> A and then return

}
