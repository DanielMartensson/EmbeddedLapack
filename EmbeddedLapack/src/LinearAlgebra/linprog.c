/*
 * linprog.c
 *
 *  Created on: 26 nov. 2019
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
 * c [n] // Objective function
 * x [n] // Solution
 * row_a = m
 * column_a = n
 */
void linprog(double* c, double* A, double* b, double* x, int row_a, int column_a, int iteration_limit){

	// Clear the solution
	memset(x, 0, column_a*sizeof(double));

	// Create the tableau with space for the slack variables s and p as well
	double tableau[(row_a+1)*(column_a+row_a+2)]; // +1 because the extra row for objective function and +2 for the b vector and slackvariable for objective function
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
	for(int i = 0; i < column_a; i++){
		tableau[(row_a+1-1)*(column_a+row_a+2) + i] = -*(c +i);
	}
	// Slack variable for the objective function
	tableau[(row_a+1-1)*(column_a+row_a+2) + (column_a+row_a+2-2)] = 1;
	// Done!

	// Print tableau
	//print(tableau,(row_a+1),(column_a+row_a+2));

	// Do row operations
	double entry = 0.0;
	int pivotColumIndex = 0;
	int pivotRowIndex = 0;
	double pivot = 0.0;
	double value1 = 0.0;
	double value2 = 0.0;
	double value3 = 0.0;
	double smallest = 0.0;
	int count = 0;
	do{
		// Find our pivot column
		pivotColumIndex = 0;
		entry = 0.0;
		for(int i = 0; i < (column_a+row_a+2) -1; i++){ // -1 because we don't want to count with the last column
			value1 = *(tableau + (row_a+1-1)*(column_a+row_a+2) + i); // Bottom row
			if(value1 < entry){
				entry = value1;
				pivotColumIndex = i;
			}
		}
		//printf("Entry = %f\n", entry);
		// If the smallest entry is equal to 0 or larger than 0, break
		if(entry >= 0.0 || count >= iteration_limit)
			break;

		// Find our pivot row
		pivotRowIndex = 0;
		value1 = *(tableau + 0*(column_a+row_a+2) + pivotColumIndex); // Value in pivot column
		value2 = *(tableau + 0*(column_a+row_a+2) + (column_a+row_a+2-1)); // Value in the b vector
		smallest = value2/value1; // Initial smallest value
		for(int i = 1; i < row_a; i++){
			value1 = *(tableau + i*(column_a+row_a+2) + pivotColumIndex); // Value in pivot column
			value2 = *(tableau + i*(column_a+row_a+2) + (column_a+row_a+2-1)); // Value in the b vector
			value3 = value2/value1;
			if( (value3 > 0  && value3 < smallest ) || smallest < 0 ){
				smallest = value3;
				pivotRowIndex = i;
			}
		}

		// We know where our pivot is. Turn the pivot into 1
		// 1/pivot * PIVOT_ROW -> PIVOT_ROW
		pivot = *(tableau + pivotRowIndex*(column_a+row_a+2) + pivotColumIndex); // Our pivot value
		//printf("pivotRowIndex = %i, pivotColumIndex = %i, pivot = %f\n", pivotRowIndex, pivotColumIndex, pivot);
		for(int i = 0; i < (column_a+row_a+2); i++){
			value1 = *(tableau + pivotRowIndex*(column_a+row_a+2) + i); // Our row value at pivot row
			*(tableau + pivotRowIndex*(column_a+row_a+2) + i) = value1 * 1/pivot; // When value1 = pivot, then pivot will be 1
		}
		//printf("Set to 1\n");
		//print(tableau,(row_a+1),(column_a+row_a+2));

		// Turn all other values in pivot column into 0. Jump over pivot row
		// -value1* PIVOT_ROW + ROW -> ROW
		for(int i = 0; i < row_a + 1; i++){
			if(i != pivotRowIndex){
				value1 = *(tableau + i*(column_a+row_a+2) + pivotColumIndex); // This is at pivot column
				for(int j = 0; j < (column_a+row_a+2); j++){
					value2 = *(tableau + pivotRowIndex*(column_a+row_a+2) + j); // This is at pivot row
					value3 = *(tableau + i*(column_a+row_a+2) + j); // This is at the row we want to be 0 at pivot column
					*(tableau + i*(column_a+row_a+2) + j) = -value1*value2 + value3;
				}
			}
		}
		//printf("Set to 0\n");
		//print(tableau,(row_a+1),(column_a+row_a+2));

		// Count for the iteration
		count++;

	}while(entry < 0); // Continue if we have still negative entries

	// Now when we have shaped our tableau. Let's find the optimal solution. Sum the columns
	for(int i = 0; i < column_a; i++){
		value1 = 0; // Reset
		for(int j = 0; j < row_a + 1; j++){
			value1 += *(tableau + j*(column_a+row_a+2) + i); // Summary
			value2 = *(tableau + j*(column_a+row_a+2) + i); // If this is 1 then we are on the selected

			// Check if we have a value that are very close to 1
			if(value1 < 1.00001 && value1 > 0.99999 && value2 > 0.99999){
				*(x + i) = *(tableau + j*(column_a+row_a+2) + (column_a+row_a+2-1));
			}
		}
	}

	//print(tableau,(row_a+1),(column_a+row_a+2));

}
