#include <stdio.h>

int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}

int fib_iter(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0, p = 1, result = 0;
	for (int i = 2; i <= n; i++) // 0,1일 때 제외
	{
		result = pp + p;
		pp = p;
		p = result;
	}
	return result;
}
int main()
{

	printf("순환 : %d \n", fib(4)); //순환 //같은 함수가 중복되어서 계산됨
	printf("반복 : %d \n", fib_iter(4)); //반복 : 더 효율적
	return 0;
}