# EmbeddedLapack 

![](https://raw.githubusercontent.com/DanielMartensson/EmbeddedAlgebra/master/C-symbol.png)  ![](https://raw.githubusercontent.com/DanielMartensson/EmbeddedAlgebra/master/CPU-symbol.png) 
![](https://raw.githubusercontent.com/DanielMartensson/EmbeddedAlgebra/master/Matrix-symbol.png)

## Introduction
This is a C-library for linear algebra which are ment to be used for embedded systems such as AVR, PIC, ARM etc. The library is
easy built and follows as much as it can the MATLAB/Octave "standard", how to compute and solve matrices.
This C-library using Lapack subroutines from Lapack version 3.2.1 and I have change this Lapack library so it don't require a specific CPU/computer or asking for a operative system. I want this library to have 100% portability.  

* Easy to use in the editor
* Basic easy code to read if needed
* Follows MATLAB commands as much as it can
* Can be used with a compiler as low as C99 standard, default is C11
* Simple use for most common matrix algebra
* Using minimal but necessary Lapack subroutines as possible due to the small amout of flash memory it will be loaded into.

## Tested on without any compile errors
* Windows 7 MinGW 64 bit
* Ubuntu Linux GCC 64 bit
* Raspberry Pi B+ GCC-ARM 32 bit
* STM32 GCC-ARM-Atollic 32 bit

## Installation for testing and buildning your matrix algebra

Step 1: Download EmbeddedLapack folder

Step 2: Open EmbeddedLapack and go to Debug folder

Step 3:
Write this to compile
```
make clean
make
```

## Installation to an embedded target
Step 1: Download EmbeddedLapack folder

Step 2: Move the folders "Lapack" and "LinearAlgebra" from the folder EmbeddedLapack -> src, to the same folder as your main.c file is located.

Step 3: Link "-lm" like this.

![](https://raw.githubusercontent.com/DanielMartensson/EmbeddedLapack/master/Markering_006.png)

Step 4: Paste in "#include "LinearAlgebra/declareFunctions.h"" in top of your main.c file

![](https://raw.githubusercontent.com/DanielMartensson/EmbeddedLapack/master/Markering_008.png)

Done! Now you can compile.

## Functions

```
void tran(double* A, int row, int column);
void print(double* A, int row, int column);
void linsolve(double* A, double* X, double* B, int row, int column_b);
void svd(double* A, double* U, double* S, double* V, int row, int column);
void diag(double* A, double* B, int row_b, int column_b);
void qr(double* A, double* Q, double* R, int row, int column);
void triu(double* A, double* B, int shift, int row, int column);
void eye(double* A, int row, int column);
void mul(double* A, double* B, bool elementWise, double* C, int row_a, int column_a, int column_b);
void scale(double* A, double scalar, int row, int column);
void sub(double* A, double* B, double* C, int row_a, int column_a, int column_b);
void lu(double* A, double* L, double* U, double* P, int row, int column);
void tril(double* A, double* B, int shift, int row, int column);
void inv(double* A, int row);
void chol(double* A, double* L, int row);
double det(double *A, int row);
void toeplitz(double* A, double* B, int length);
void hankel(double* A, double* H, int length, int step);
void cut(double* A, int row, int column, double* B, int start_row, int stop_row, int start_column, int stop_column);
void diagpower(double* A, double p, int row, int column);
void eabs(double* A, int row, int column);
void add(double* A, double* B, double* C, int row_a, int column_a, int column_b);
void copy(double* A, double* B, int row, int column);
void cofact(double* A, double* CO, int row, int column);
void mdiag(double* A, double* B, int row, int column);
double dot(double* A, double* B, int row);
void horzcat(double* A, double* B, double* C, int row_a, int column_a, int column_b);
void maxvector(double* A, int row, double* val, int* index);
void minvector(double* A, int row, double* val, int* index);
double norm(double* A, int row, char* P);
void ones(double* A, int row, int column);
void pinv(double* A, int row, int column);
void power(double* A, int row, int column, double value);
void repmat(double* A, int row, int column, int horz, int vert, double* B);
void sqrte(double* A, int row, int column);
void sumrows(double* A, double* B, int row, int column);
void vec(double* A, double* B, int row, int column);
void vertcat(double* A, double* B, double* C, int row_a, int column_a, int row_b);
void zeros(double* A, int row, int column);
int rank(double* A, int row);
void eig(double* A, double* Ereal, double* Eimag, double* Vreal_left, double* Vimag_left, double* Vreal_right, double* Vimag_right, int row);
void mpower(double* A, int row, int n);
void insert(double* A, double* B, int row_a, int column_a, int column_b, int startRow_b, int startColumn_b);
void move(double* A, int row, int column, int down, int right);
```
## Compiler and microprocessor
When you compile this, you need to take respect on this.
```
#include <math.h>  // Need be linked with "-lm" when compiling this code
```
Also you need to link the folder "Include" located inside EmbeddedLapack -> src -> Lapack. 

## Troubleshooting
If you declare a matrix or a vector and you use that with this library, but you getting garbage values back. Try to sett all values of the matrix or vector to zeros by using:
```
zeros(A, row, column);
```
Most of my functions have this algorithm included in the beginning of the functions. 

## Examples and how to use
Here is some examples how to use

## QR-factorization
```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main() {

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	 // A matrix with size 6 x 4
	double A[6*4] = {0.674878,   0.151285,   0.875139,   0.150518,
			0.828102,   0.150747,   0.934674,   0.474325,
			0.476510,   0.914686,   0.740681,   0.060455,
			0.792594,   0.471488,   0.529343,   0.743405,
			0.084739,   0.475160,   0.419307,   0.628999,
			0.674878,   0.151285,   0.875139,   0.150518};

	double Q[6*6];
	double R[6*4];

	// Solve
	qr(A, Q, R, 6, 4);

	// Print
	print(A, 6,4);
	print(Q, 6,6);
	print(R, 6,4);

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}
```
## Singular Value Decomposition
```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"


#define row 17
#define column 15

int main( )
{

   clock_t start, end;
   float cpu_time_used;
   start = clock();

   double A[row*column] = {
0.84245,     0.23405   ,  0.69751 ,    0.27905   ,  0.18851  ,   0.61018    , 0.62182  ,   0.71839   ,  0.79161     ,0.56156   ,  0.83395   , 0.092388     , 0.8511    , 0.44826    , 0.82158,
0.84614  ,   0.15947  ,  0.096336  ,   0.80793  ,   0.35114 ,    0.42583 ,     0.2134 ,    0.75324   ,  0.31391 ,    0.22892  ,   0.94773 ,    0.81204   ,  0.62554 ,    0.28367   ,  0.26637,
0.26509  ,   0.91429  ,   0.14222  ,   0.28321   ,  0.11607 ,    0.41188 ,    0.10071 ,    0.18224   ,  0.75723 ,    0.89125  ,   0.62494 ,    0.83016   ,  0.46448  ,   0.73119  ,   0.10982,
0.45197  ,   0.44562  ,   0.27909  ,   0.76019   , 0.014571 ,    0.42705 ,    0.70214 ,    0.64936   ,  0.98451 ,    0.59632  ,   0.07654 ,    0.95633   ,  0.18574   ,  0.92716  ,   0.65401,
0.48034  ,   0.38327  ,   0.32906  ,   0.34794   ,  0.68673 ,    0.54113 ,    0.34142 ,    0.48561  ,   0.37221 ,    0.16097  ,   0.15569 ,    0.63287  ,   0.17518  ,  0.055447  ,   0.44536,
0.54119  ,   0.34478   ,  0.53297  ,    0.2796   ,  0.95212 ,     0.5353 ,     0.8202 ,    0.32707  , 0.0062771 ,    0.64993  ,  0.057361 ,    0.59959  ,   0.16867  ,   0.67892  ,   0.52882,
0.082573  ,   0.96676  ,  0.080315  ,   0.48813   ,  0.33496 ,     0.4436 ,    0.01436 ,    0.89664   ,  0.49167 ,    0.37092  ,   0.31586 ,    0.54683  ,   0.65159  ,   0.38531  ,   0.20697,
0.35775  ,   0.42437  ,   0.79392  ,   0.49724    , 0.01319 ,  0.0074932 ,    0.66462 ,     0.6506   ,   0.9889 ,    0.27213  ,   0.99607 ,    0.68418  ,   0.70238  ,   0.81493  ,   0.46062,
0.22609  ,   0.59924  ,   0.74631  ,   0.81566   ,  0.92784 ,    0.47376 ,    0.83531 ,    0.47031   ,  0.97093 ,    0.44778  ,   0.42997 ,    0.71882  ,   0.36504  ,   0.34216  ,   0.95187,
0.87475  ,   0.22003  ,   0.71901  ,   0.90968   ,  0.27265 ,    0.16106 ,    0.21283 ,    0.14918   ,  0.16776 ,    0.83038  ,   0.43605 ,    0.85075  ,   0.54771  ,   0.77479  ,   0.24739,
0.21203  ,   0.65616  ,   0.63534  ,   0.57569   ,  0.22113 ,    0.48063 ,    0.24207 ,    0.54873   ,  0.25042 ,    0.82671  ,   0.88986 ,    0.41674  ,   0.95235  ,   0.89875  ,   0.15004,
0.86164  ,   0.89058  ,   0.66423  ,   0.60958   ,  0.47708 ,    0.18674 ,    0.66359 ,    0.92383  ,   0.48073 ,    0.79466  ,   0.64519 ,    0.69876  , 0.0066587  ,   0.55114  ,   0.10979,
0.35586  ,   0.94772  ,   0.28888  ,   0.63119   ,  0.42774 ,    0.82597 ,    0.90274 ,    0.40152  ,   0.96414 ,    0.84376  ,  0.028355 ,   0.040771   ,  0.85359  ,   0.92875  ,   0.32352,
0.39274  ,   0.27788  ,   0.41549  ,   0.90884  ,  0.042767 ,    0.64168 ,   0.086933 ,    0.47941  ,   0.91491 ,    0.26425  ,   0.11667 ,    0.49996   ,  0.12644  ,   0.87136  ,   0.30768,
0.86527 ,    0.92393  ,   0.47957  ,   0.32175  ,   0.87965 ,    0.13719 ,     0.4014 ,    0.25277  ,   0.83936 ,    0.73476  ,   0.97174 ,    0.65243   ,  0.85813  ,   0.62705  , 0.0013063,
0.34355 ,    0.43424  ,   0.34352  ,   0.34341  ,   0.94343 ,    0.45452  ,     0.343  ,    0.1243   ,   0.12522 ,    0.214343 ,   0.12432 ,    0.54534   ,  0.12442  ,   0.12467  , 0.9988,
0.84245,     0.23405   ,  0.69751 ,    0.27905   ,  0.18851  ,   0.61018    , 0.62182  ,   0.71839   ,  0.79161     ,0.56156   ,  0.83395   , 0.092388     , 0.8511    , 0.44826    , 0.82158};


   double U[row*row];
   double S[row*column];
   double V[column*column];

   // Solve
   svd(A, U, S, V, row, column);

   // print
   print(U, row, row);
   print(S, row, column);
   print(V, column, column);

   end = clock();
   cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
   printf("\nTotal speed  was %f,", cpu_time_used);
   return 0;
}

```

## Solve AX=B
```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main( )
{
    clock_t start, end;
	float cpu_time_used;
	start = clock();
	

	/*
	 * A matrix 3x3 - Need to be square
	 */
	double A[3*3] = {3, 4, 1,
			6, 10, 2,
			5, 3, 2
	};


	/*
	 * Solution 3x4
	 */
	double X[3*4];

	/*
	 * B matrix 3x4
	 */
	double B[3*4] = {4, 3, 22, 5,
			5, 3, 2, 5,
			3, 4, 5, 3};

	/*
	 * Solve
	 */
	linsolve(A, X, B, 3, 4); // 3 = A row, 4 = B column

	/*
	 * Print solution
	 */
	print(X, 3, 4);
	
	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
    return 0;
}
```
## Find eigenvalues and eigenvectors
```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main( ) {

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	// Need to be square
	double A[6*6] = {4,3,1,4,2,23,
			 6,3,-2,3,5,8,
			 1,3,6,2,3,2,
			 2,5,6,7,4,4,
			 4,6,-88,6,4,6,
			 2,1,44,54,3,2
	};


	double Ereal[6]; // Eigenvalues real
	double Eimag[6]; // Eigenvalues imag part
	double Vreal_left[6*6]; // Eigenvectors real left
	double Vimag_left[6*6]; // Eigenvectors imag left
	double Vreal_right[6*6]; // Eigenvectors real right
	double Vimag_right[6*6]; // Eigenvectors imag right

	// Solve
	eig(A,Ereal,Eimag,Vreal_left,Vimag_left,Vreal_right,Vimag_right,6);

	// Print
	print(A, 6, 6);
	print(Ereal, 6, 1);
	print(Eimag, 6, 1);
	print(Vreal_left, 6,6);
	print(Vimag_left, 6,6);
	print(Vreal_right, 6,6);
	print(Vimag_right, 6,6);

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}
```

## LU-factorization
```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main( ) {

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	double A[5*4] = {2, 7, 6, 2,
			 9, 5, 1, 3,
			 4, 3, 8, 4,
			 5, 6, 7, 8,
			 2, 2, -3,-1
	};

	double U[4*4];
	double L[5*4];
	double P[5*5];

	// Solve
	lu(A, L, U, P, 5, 4);

	// Print
	print(A, 5,4);
	print(U, 4,4);
	print(L, 5,4);
	print(P, 5,5);


	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}

```

## Observer Kalman IDentification(OKID) and Eigensystem Realization Theory(ERA)
This will estimate a 2x2 state space model from measurement data
```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"


int main() {

	/*
	 * G(s) = 1/(s^2 + 1s + 3)  - Model
	 * y = measured output values
	 * u = measured input values
	 */

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	double y[144] = { 0.00000, 0.49525, 1.43863, 2.13779, 2.30516, 2.05713,
			1.69220, 1.45608, 1.42777, 1.54146, 1.67927, 1.75624, 1.75400,
			1.70478, 1.65394, 1.62996, 1.63549, 1.65594, 1.67426, 1.68125,
			1.67752, 1.66930, 1.66285, 1.66102, 1.66300, 1.66621, 1.66842,
			1.66880, 1.66786, 1.66664, 1.66591, 1.66588, 1.66629, 1.66675,
			1.66698, 1.66695, 1.66678, 1.66661, 1.66654, 1.66657, 1.66664,
			1.66670, 1.66672, 1.66670, 1.66667, 1.66665, 1.66665, 1.66666,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66666, 1.66666,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667, 1.66667,
			1.66667, 1.66667, 1.66667, 1.66667, 1.66667 };

	double u[144] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
			5, 5, 5, 5, 5, 5, 5, 5, 5 };

	// Toeplitz matrix
	double toe[144 * 144];
	toeplitz(u, toe, 144);

	// Upper triangular
	double tru[144 * 144];
	triu(toe, tru, 0, 144, 144);

	// inverse
	inv(tru, 144);

	// Multiplication
	double g[144];
	mul(y, tru, false, g, 1, 144, 144);

	// Create hankel
	double H0[144 * 144];
	hankel(g, H0, 144, 1);
	double H1[144 * 144];
	hankel(g, H1, 144, 2);

	// Cut hankel into half
	double H0_half[72 * 72];
	double H1_half[72 * 72];
	cut(H0, 144, 144, H0_half, 0, 71, 0, 71);
	cut(H1, 144, 144, H1_half, 0, 71, 0, 71);

	// Do SVD
	double U[72 * 72];
	double S[72 * 72];
	double V[72 * 72];
	svd(H0_half, U, S, V, 72, 72);

	// Model reduction to second order model
	double Un[72 * 2];
	double Sn[2 * 2];
	double Vn[72 * 2];
	cut(U, 72, 72, Un, 0, 71, 0, 1);
	cut(S, 72, 72, Sn, 0, 1, 0, 1);
	cut(V, 72, 72, Vn, 0, 71, 0, 1);

	// Create A, B, C
	double Sn_sqrt_negative[2 * 2];
	double Sn_sqrt_positive[2 * 2];
	copy(Sn, Sn_sqrt_negative, 2,2);
	copy(Sn, Sn_sqrt_positive, 2,2);
	diagpower(Sn_sqrt_negative, -0.5, 2, 2);
	diagpower(Sn_sqrt_positive, 0.5, 2, 2);

	/*
	 * C = Un*Sn^(1/2);
	 * Cd = C(1, 1:2)
	 */
	double C[72 * 2];
	double Cd[1 * 2];
	mul(Un, Sn_sqrt_positive, false, C, 72, 2, 2);
	cut(C, 72, 2, Cd, 0, 0, 0, 1);

	/*
	 * Ad = Sn^(-1/2)*Un'*H1*Vn*Sn^(-1/2);
	 */
	double A[72 * 2];
	double A1[72 * 2];
	double Ad[2 * 2];
	double Ad1[2 * 2];
	mul(Vn, Sn_sqrt_negative, false, A, 72, 2, 2);
	mul(H1_half, A, false, A1, 72, 72, 2);
	tran(Un, 72, 2);
	mul(Un, A1, false, Ad1, 2, 72, 2);
	mul(Sn_sqrt_negative, Ad1, false, Ad, 2, 2, 2);

	/*
	 * B = Sn^(1/2)*Vn'
	 * Bd = B(:, 1);
	 */
	double B[2 * 72];
	double Bd[2 * 1];
	tran(Vn, 72, 2);
	mul(Sn_sqrt_positive, Vn, false, B, 2, 2, 72);
	cut(B, 2, 72, Bd, 0, 1, 0, 0);

	/*
	 * Print A, B, C
	 */
	printf("A Matrix: \n");
	print(Ad, 2, 2);

	printf("B Matrix: \n");
	print(Bd, 2, 1);

	printf("C Matrix: \n");
	print(Cd, 1, 2);

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}
```

## Basic Model Predictive Control example
Given a state space model and a reference point, this example can compute your best input signals U depending on how you set your control- and predictive horizons column_o and column_h

```
#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

/*
 * Here you can set the sizes for the matrices
 */

#define row_a 2 // A row
#define column_a 2 // A column

#define row_b 2 // B row, the same row as A.
#define column_b 1 // B column, the same column as D

#define row_c 1 // C row, the same row as D
#define column_c 2 // C column, the same column as A

/*
 * Create a state space model - discrete
 */
double A[row_a * column_a] = { -0.099272, 0.029481,
		               -0.088444, -0.158234};

double B[row_b * column_b] = { 0.366424,
			       0.029481
};

double C[row_c * column_c] = {1, 0};

double D[row_c * column_b] = {0};

double X[row_a] = {0, 0};

double R =  6;

// Create the length of the observability matrix, notice it will have the dimension (row_o * row_c + row_c) x column_b
#define row_o 20

// Create the widt of the lower triangular toeplitz H matrix, notice that it will have the dimension (row_o * row_c + row_c) x (column_h * column_b)
#define column_h 19 // column_h < row_o - always!

// Define the column of the reference vector - Standard is 1
#define column_ry 1

int main() {

	/*
	 * Model predictive control
	 */

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	/*
	 * Create the Observabillity matrix and the
	 */

	double O[(row_o * row_c) * row_a];
	double O_[(row_o * row_c) * row_a]; // This is for the lower triangular toeplitz matrix
	double A_[row_a * column_a];
	double C_[row_c * column_c];

	for (int i = 1; i <= row_o; i++) {
		copy(A, A_, row_a, column_a); // Copy A -> A_
		mpower(A_, row_a, i); // Power A_^i
		mul(C, A_, false, C_, row_c, column_c, column_a); // C_ = C*A_
		insert(C_, O, row_c, column_c, row_a, (i-1)*row_c, 0); // Insert O = [CA^1; CA^2; CA^3; ... ; CA^row_o];

		copy(A, A_, row_a, column_a); // Copy A -> A_
		mpower(A_, row_a, i - 1); // Power A_^(i-1)
		mul(C, A_, false, C_, row_c, column_c, column_a); // C_ = C*A_
		insert(C_, O_, row_c, column_c, row_a, (i-1)*row_c, 0); // Insert O_ = [CA^0; CA^1; CA^2; ... ; CA^(row_o-1)];
	}

	//print(O, row_o * row_c, row_a);

	/*
	 * Create the lower triangular toeplitz matrix
	 */
	double H[(row_o * row_c) * (column_h * column_b)];
    zeros(H, row_o * row_c, column_h * column_b);

	// T = O_*B - Observabillity matrix times B
    double T[(row_o * row_c) * column_b];
	mul(O_, B, false, T, row_o * row_c, row_a, column_b);


	// Lower triangular toeplitz matrix of T = [C*A^0*B; C*A^1*B; C*A^2*B; C*A^3*B; ...; C*A^(row_o-1)*B]
	for (int j = 0; j < column_h; j++){
		insert(T, H, row_o * row_c, column_b, column_h * column_b, 0, j*column_b);
		move(T, row_o * row_c, column_b, row_c , 0);
	}

	//print(H, row_o * row_c, column_h * column_b); // H matrix


	/*
	 * Compute U = pinv(H)*(Ry*R - O*X), where R is our reference vector, X is our initial state vector
	 */

	pinv(H, row_o * row_c, column_h * column_b); // Pseudo inverse of H. Using the SVD method

	double Ry[(row_o * row_c)*column_ry];
	ones(Ry, row_o * row_c, column_ry);
	scale(Ry, R, row_o * row_c, column_ry); // Ry*R = Ry

	double OX[(row_o * row_c)*column_ry];
	mul(O, X, false, OX, row_o * row_c, row_a, column_ry); // O*X

	double Ry_OX[(row_o * row_c)*column_ry];
	sub(Ry, OX, Ry_OX, row_o * row_c, column_ry, column_ry); // Ry-O*X

	double U[(column_h * column_b)*column_ry];
	mul(H, Ry_OX, false, U, column_h * column_b, row_o * row_c, column_ry); // U = pinv(H)*(Ry-O*X);

	/*
	 * Our best input values
	 */
	print(U, column_h * column_b, column_ry);



	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}
```

## Read the .c files
If you don't know how to use the function, you can read the .c file of that function that you want to use. It will always be a comment above the function name that describe what you should have as argument, what size and what data type and what it will return. Here is an example.
```
#include "declareFunctions.h"

/*
 * Cut a matrix A with size row x columns into a matrix B with size (stop_row - start_row + 1) x (stop_column - start_column + 1).
 * Remember! Indexing start and stop are from zero!
 *
 * Example:
 * If you have a matrix A 5 x 6 and you want to cut the values from A to matrix B with size 3 x 3 and you want to start at 0,0 and end at 3,3
 * Code: cut(A, 5, 6, B, 0, 2, 0, 2); // Because indexing from zero
 */

void cut(double* A, int row, int column, double* B, int start_row, int stop_row, int start_column, int stop_column) {

	int in_columns = column;
	double* data = A + start_row * in_columns + start_column;

	// Create the output
	//double* ptr = B;
	int out_columns = stop_column - start_column + 1;

	// Instead of having two for loops, we just copy the whole row at once.
	for (int i = start_row; i < stop_row + 1; i++) {
		memcpy(B, data, sizeof(double) * out_columns);
		B += out_columns;
		data += in_columns;
	}

}

```


## How can you help and build on this library?
Download the clapack.tgz file above, or from here http://www.netlib.org/clapack/. Extract it. Then you can copy and paste the files into the subfolders of folder "Lapack" from the EmbeddedLapack -> src folder, so you can have your desire Lapack subroutine to work. You can see how I have done. Just do the same. I just include the Lapack routine I want to use, and then I got lots of errors in the compiling and those errors asking for functions from other .c files located from clapack.tgz file. I copy and paste functions until all errors where gone. 


