#include <stdio.h>

int factorial_iter(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int main()
{
	printf("°á°ú : %d \n",factorial_iter(5));
}