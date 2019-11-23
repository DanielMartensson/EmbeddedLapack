/*
 * sqrte.c
 *
 *  Created on: 12 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Take power p, on all element on the diagonal of matrix A, who has the size row x column
 */

void diagpower(double* A, double p, int row, int column){

	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			if(j == i){
				*(A) = powf(*(A), p);
				A += column + 1;
			}
		}
	}
}

