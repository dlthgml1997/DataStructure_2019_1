#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double slow_power(double x, int n)
{

}

void main()
{
	clock_t start, finish;
	double duration;
	int i;
	start = clock();
	for (i = 0 ;i < 1000000; i++
		)
		slow_power(1.125,1000);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf(" duration(수행시간) = %lf \n", duration);


}