/*
 * rank.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Find the rank of matrix A, size row x column, where row == column
 */
int rank(double* A, int row){
	double determinant = det(A, row);

	/*
	 * If the terminant is not equal to zero, then we have full rank = row, else we have not full rank
	 */
	if(determinant != 0){
		return row;
	}else
		return -1; // Not full rank

}
