/*
 * norm.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Do norm of a vector A with size row x 1. Specify what kind of norm with P
 */

double norm(double* A, int row, char* P) {

	/*
	 *  P = "1" - L1 Norm - Sum
	 *  P = "2" - L2 Norm - Abs
	 */

	double sum = 0; // Initial

	if (P == "1") {
		for (int i = 0; i < row; i++)
			sum += (*(A + i));
		return sum;
	}
	else if (P == "2") {
		for (int i = 0; i < row; i++)
			sum += fabsf((*(A + i)));
		return sum;
	}else
		return 0;

}
