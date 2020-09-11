/*
 * dot.c
 *
 *  Created on: 15 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Find the dot product of two vectors A and B with the same size: row x 1
 * MATLAB code:
 * >> A =    [1,2,3,5,8]
   A =
	   1   2   3   5   8
   >> B =  [-3,4,1,5,10]
   B =
	   -3    4    1    5   10
   >> dot(A, B)
   ans =  113
   >>
 *
 *
 */

double dot(double* A, double* B, int row) {

	// Reset
	double sum = 0;

	// Multiply each row
	for (int i = 0; i < row; ++i) {
		sum += (*(A + i)) * (*(B + i));
	}
	return sum;

}
