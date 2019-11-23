/*
 * sumrows.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Sum all rows from A size row x column, into a flat matrix B size 1 x column
 */

void sumrows(double* A, double* B, int row, int column) {

	for(int j = 0; j < column; j++){
		for(int i = 0; i < row; i++){
			*(B + j) += *((A + i*column) + j);
		}
	}

}
