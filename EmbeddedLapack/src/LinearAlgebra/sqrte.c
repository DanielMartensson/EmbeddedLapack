/*
 * sqrte.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */


#include "declareFunctions.h"

/*
 * Take the square root of every element of matrix A, size row x column
 */
void sqrte(double* A, int row, int column){
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++){
			*A = sqrt(*(A));
			A++;
		}
}
