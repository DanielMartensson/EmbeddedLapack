#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main() {

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	double A[2*3] ={2, 3, 2,
		            1, 1, 2};

	double b[2] = {1000,
				   800};

	double c[3] = {7,
		           8,
	              10};
	double x[3];
	int iteration_limit = 100;
	linprog(c, A, b, x, 2, 3, iteration_limit);

	// Solution
	print(x, 3, 1);

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}

