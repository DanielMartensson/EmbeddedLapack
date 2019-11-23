/*
 * move.c
 *
 *  Created on: 21 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Move the rows steps down or move the columns steps to right. The replacement will be zeros
 * Matrix A have the size row x column
 */

void move(double* A, int row, int column, int down, int right) {

	double B[row*column];
	memset(B, 0, row*column*sizeof(double));

	/*
	 * We take -1 due to indexing from zero
	 */

	for (int i = row-1; i >= 0; i--){
		for (int j = column-1; j >= 0; j--){
			if(i -down <= -1)
				*(B + i*column + j) = 0;
			else
				if(j - right >= 0)
					*(B + i*column + j) = *(A + (i-down)*column + j - right);
		}
	}


	memcpy(A, B, row*column*sizeof(double));
}
