#include <stdio.h>

int factorial(int n)
{
	printf("factorial(%d)\n", n);
	if (n <= 1) return 1;
	else return(n*factorial(n - 1));
}

int main()
{
	int result;
	result = factorial(5);
	printf("°á°ú : %d", result);
}