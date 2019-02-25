#include <time.h>
#include "LinearAlgebra/declareFunctions.h"


int main() {

	/*
	 * Standard template
	 */

	clock_t start, end;
	float cpu_time_used;
	start = clock();

	/*
         * Enter your code here
         */

	end = clock();
	cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f,", cpu_time_used);
	return 0;
}
