/*
 * linprog.c
 *
 *  Created on: 23 nov. 2019
 *      Author: Daniel Mårtensson
 */

#include "declareFunctions.h"

/**
 * This is linear programming with simplex method:
 * Max c^Tx
 * S.t Ax <= b
 *      x >= 0
 *
 * Call this function with the sizes
 * A [m*n] // Matrix
 * b [m] // Constraints
 * c [m] // Objective function
 * x [m] // Solution
 * row_a = m
 * column_a = n
 *
 * Notice that you can solve Ax = b with constraints just to set c = A^T*b
 */
void linprog(double* c, double* A, double* b, double* x, int row_a, int column_a){

	// Clear the solution
	memset(x, 0, column_a*sizeof(double));

	// Create the tableau with space for the slack variables s and p as well
	double tableau[(row_a+1)*(column_a+row_a+2)];
	memset(tableau, 0, (row_a+1)*(column_a+row_a+2)*sizeof(double));

	// Load the constraints
	int j = 0;
	for(int i = 0; i < row_a; i++){
		// First row
		memcpy(tableau + i*(column_a+row_a+2), A + i*column_a, column_a*sizeof(double));

		// Slack variable s
		j = column_a + i;
		tableau[i*(column_a+row_a+2) + j] = 1;

		// Add b vector
		tableau[i*(column_a+row_a+2) + (column_a+row_a+2-1)] = *(b+i);

	}
	// Negative objective function
	for(int i = 0; i < row_a; i++){
		tableau[(row_a+1-1)*(column_a+row_a+2) + i] = -*(c +i);
	}
	// Slack variable for the objective function
	tableau[(row_a+1-1)*(column_a+row_a+2) + (column_a+row_a+2-2)] = 1;
	// Done!

	// Check the smallest negative value of objective function - Need to be < 0
	double value = 0.0;
	int indexColumn = 0;
	double div = 0.0;
	int indexRow = 0;
	do{
		// Search in the negative objective function
		value = 0;
		indexColumn = 0;
		for(int i = 0; i < (column_a+row_a+2) - 1; i++){
			if(tableau[(row_a+1-1)*(column_a+row_a+2) + i] < value){
				value = tableau[(row_a+1-1)*(column_a+row_a+2) + i]; // Save
				indexColumn = i; // Remember index
			}
		}
		// Check that index and divide the columns with the right columns
		div = tableau[(column_a+row_a+2-1)]/tableau[indexColumn]; // Use the upper row as first value
		for(int i = 0; i < row_a; i++){
			if(tableau[i*(column_a+row_a+2) + (column_a+row_a+2-1)]/tableau[i*(column_a+row_a+2) + indexColumn] < div){
				div = tableau[i*(column_a+row_a+2) + (column_a+row_a+2-1)]/tableau[i*(column_a+row_a+2) + indexColumn];
				indexRow = i; // save
			}
		}
		// Time to do row operations on the tableau.
		// First change the value at indexRow and indexColumn to 1
		div = tableau[indexRow*(column_a+row_a+2) + indexColumn];
		for(int i = 0; i < (column_a+row_a+2); i++){
			tableau[indexRow*(column_a+row_a+2) + i] = tableau[indexRow*(column_a+row_a+2) + i] * 1/div;
		}
		// Then set the rest of the columns to 0
		for(int i = 0; i < row_a + 1; i++){
			// We only do row operations on rest of the rows
			if(i != indexRow){
				div = tableau[i*(column_a+row_a+2) + indexColumn];
				for(int j = 0; j < (column_a+row_a+2); j++){
					tableau[i*(column_a+row_a+2) + j] = -div * tableau[indexRow*(column_a+row_a+2) + j] + tableau[i*(column_a+row_a+2) + j];
				}
			}
		}
	}while(value < 0);

	// Now when we have shaped our tableau. Let's find the optimal solution
	// Sum the columns
	for(int i = 0; i < column_a-1; i++){
		value = 0; // Reset
		for(int j = 0; j < row_a + 1; j++){
			value += tableau[j*(column_a+row_a+2) + i]; // Summary
			div = tableau[j*(column_a+row_a+2) + i]; // If this is 1 then we are on the selected

			// Check if we have a value that are very close to 1
			if(value < 1.00001 && value > 0.99999 && div > 0.99999){
				*(x + i) = tableau[j*(column_a+row_a+2) + (column_a+row_a+2-1)];
			}
		}
	}

	//print(tableau, row_a+1, column_a+row_a+2);

}
