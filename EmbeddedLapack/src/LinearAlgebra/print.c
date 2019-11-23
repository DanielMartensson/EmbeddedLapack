/*
 * print.c
 *
 *  Created on: 8 feb. 2019
 *      Author: Daniel Mårtensson
 */
#include "declareFunctions.h"

/*
 * Print a matrix A, with the dimension row x column
 */
void print(double* A, int row, int column) {
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			printf("%0.18f ", *(A++));
		}
		printf("\n");
	}
	printf("\n");

}
