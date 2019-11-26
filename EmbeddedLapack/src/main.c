#include <time.h>
#include "LinearAlgebra/declareFunctions.h"

int main() {

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	/**
	 * Your code here
	 */

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}

