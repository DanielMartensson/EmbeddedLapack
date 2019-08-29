/*
 * blasFunctions.h
 *
 *  Created on: Aug 29, 2019
 *      Author: Daniel Mårtensson
 */

#ifndef BLAS_BLASFUNCTIONS_H_
#define BLAS_BLASFUNCTIONS_H_

// b' = alpha*A'*x' + beta*b'
int sgemv_(char *trans, integer *m, integer *n, real *alpha,
	real *a, integer *lda, real *x, integer *incx, real *beta, real *y,
	integer *incy);


#endif /* BLAS_BLASFUNCTIONS_H_ */
