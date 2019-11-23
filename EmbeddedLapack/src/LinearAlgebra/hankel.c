/*
 * hankel.c
 *
 *  Created on: 12 feb. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/*
 * Turn the array A with the size 1 x length, into a hankel matrix H with the size length x length
 * Argument step is how the shift of hankel matrix should be. Normaly, you want shift = 0.
 */

void hankel(double* A, double* H, int length, int step) {

	memset(H, 0, length*length*sizeof(double));

	for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
			if(j+i+step >= length){
				*((H + i*length) + j) = 0;
			}else{
				*((H + i*length) + j) = A[j+i+step];
			}
		}
	}
}
