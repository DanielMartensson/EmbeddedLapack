/*
 * main.c
 *
 *  Created on: Aug 29, 2019
 *      Author: Daniel Mårtensson
 */
#include <stdio.h>
#include "Blas/f2c.h"
#include <time.h>
int main(){
	// Transpose matrix A'
	real A[4*3]={-0.0941,  0.5298, 0.1350,
		      0.4098, -0.1581, -0.2768,
		      0.1868, -0.0455, -0.4475,
		      0.6364, -0.0308, 0.0176};
	
	// Transpose vector b'
	real b[1*3]={ 50, 20, 10};
	
	// Transpose vector x'
	real x[1*4] ={4, 6, 53, -4};

	integer m = 3; // Real row dimension of non-transpose A
	integer n = 4; // Read column dimension of non-transpose A
	real alpha = 1; 
	real beta = 1;
	integer incx = 1; // Always 1
	integer incy = 1; // Always 1
	char trans = 'N'; // We have transpose matrix A'
	clock_t start, end;
	float cpu_time_used;
	start = clock();
	sgemv_(&trans, &m, &n,   &alpha, A, &m, x, &incx, &beta, b, &incy); // b = alpha*A*x + beta*b
	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);

	printf("b[%i] = %f\n", 0, b[0]);
	printf("b[%i] = %f\n", 1, b[1]);
	printf("b[%i] = %f\n", 2, b[2]);
}
