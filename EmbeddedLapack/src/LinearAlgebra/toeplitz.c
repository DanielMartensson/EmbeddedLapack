/*
 * toeplitz.c
 *
 *  Created on: 12 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Turn a array A with the size 1 x length, into an matrix B with size length x length
 */
void toeplitz(double* A, double* B, int length) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if(i-j < 0)
				*((B + i * length) + j) = A[j-i];
			else
				*((B + i * length) + j) = A[i-j];
		}
	}
}
