#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main() {

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	double A[2*2] ={3,   3,
		           2,   4};

	double b[2] = {120,
				   150};

	double c[2] = {10,
		          12};
	double x[2];
	linprog(c, A, b, x, 2, 2);

	// Solution
	print(x, 2, 1);

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}

