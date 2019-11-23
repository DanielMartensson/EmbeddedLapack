/*
 * powe.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Take the power values of every element of matrix A, size row x column
 * MATLAB code A.^n, where n is the double value
 */

void power(double* A, int row, int column, double value){
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++){
			*A = powf(*(A), value);
			A++;
		}
}
