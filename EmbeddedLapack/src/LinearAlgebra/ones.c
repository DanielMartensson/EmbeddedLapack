/*
 * ones.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */
#include "declareFunctions.h"

/*
 * Turn every element of matrix A into 1. Size row x column
 */

void ones(double* A, int row, int column){
	for(int i = 0; i < row*column; i++)
		*(A+i) = 1;
}
