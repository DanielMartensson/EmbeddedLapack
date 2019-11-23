/*
 * diagm.c
 *
 *  Created on: 15 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"
/*
 * Take the diagonal of matrix A and insert it into into vector B.
 * A size row x column and B size column x 1
 */

void mdiag(double* A, double* B, int row, int column){

	// This will take the diagonal of matrix a and turn it to a vector matrix
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			if(i == j){
				*B = *A;
				B++;
				A++;
			}else{
				A++;
			}

		}
	}
}
