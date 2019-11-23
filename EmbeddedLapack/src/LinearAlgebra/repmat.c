/*
 * repmat.c
 *
 *  Created on: 16 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Do repeate matrix.
 * If you have a matrix A with size row x column and you want to repeat matrix A horz=3 times to left and vert=2 times down,
 * Then you need a matrix B with size row*2 x column*3
 */

void repmat(double* A, int row, int column, int horz, int vert, double* B) {

	int jump = 0;

	// Copy whole matrix a to b
	for (int i = 0; i < row*vert; i++) {
		for (int j = 0; j < horz; j++) {
			memcpy(B, A + jump, sizeof(double) * column);
			B += column;
		}
		jump += column; // Jump m columns
		// If we are at the last row of data
		if(jump >= column*row)
			jump = 0; // jump back to first row

	}
}
