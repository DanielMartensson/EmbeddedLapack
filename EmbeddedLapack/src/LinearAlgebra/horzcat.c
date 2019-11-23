/*
 * horzcat.c
 *
 *  Created on: 15 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Concate A with B into C.
 * A size row_a x column_a
 * B size row_a x column_b
 * C size row_a x (column_a + column_b)
 */

void horzcat(double* A, double* B, double* C, int row_a, int column_a, int column_b) {

	/*
	 * C = [A B]
	 */

	for (int i = 0; i < row_a; i++) {

		// We are at row i and we add the cells after the columns j
		for (int j = 0; j < column_a; j++) {
			*(C++) = *((A + i * column_a) + j);
		}

		// We change the matrix now - We use b matrix now
		for (int j = 0; j < column_b; j++) {
			*(C++) = *((B + i * column_b) + j);
		}
	}

}
