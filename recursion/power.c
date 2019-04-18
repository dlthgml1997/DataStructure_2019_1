#include <stdio.h>

//x의n제곱 값을 구하는 문제
double slow_power(double x,int n) //반복
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= x;
	}
	return result;
}

double power(double x, int n) //순환
{
	if (n == 0) return 1;
	else if ((n % 2) == 0) return power(x*x, n / 2);
	else return x*power(x*x, (n - 1) / 2);
}

int main(){

	printf("반복 : %.1f \n", slow_power(2, 3));
	printf("순환 : %.1f \n", power(4, 3));
	return 0;
}