/*
 * add.c
 *
 *  Created on: 15 feb. 2019
 *      Author: Daniel Mårtensson
 */

/*
 * Add C = A+B with A size row_a x column_a and B have the size row_a x column_b and C have the size row_a x column_a
 */

void add(double* A, double* B, double* C, int row_a, int column_a, int column_b) {

	/*
	 * This uses the formula C=A+B
	 */

	// Check which one should be the column counter
	int columnMatrix = column_a; // Initial select
	if(column_b > column_a) // But if....
		columnMatrix = column_b;

	// Add all values
	for (int i = 0; i < row_a; i++) {
		for (int j = 0; j < columnMatrix; j++) {

			if (column_b == 1 && column_a > 1)
				*(C++) = *(A++) + *(B + i); // Matrix + Vector
			else if (column_b > 1 && column_a == 1)
				*(C++) = *(A + i) + *(B++); // Vector + Matrix
			else
				*(C++) = *(A++) + *(B++); // Matrix + Matrix or Vector + Vector

		}
	}
}
