/*
#include <stdio.h>
#include <string.h>

//책 1번
int sub(int n)
{
	if (n < 0) return 0;
	return n + sub(n - 3);
}

int sub2(int n)
{
	int result = 0;
	while(n>=0)
	{
		result += n;
		n -= 3;
	}
	return result;
}

//12번(모르겠다)
unknown() 
{
	int ch;
	if ((ch = getchar()) != '\n')
		unknown();
	putchar("");
}

//13번
int add(int n) {
	if (n < 1) return 0;
	else return n + add(n - 1);
}
//14번
double add2(double n) {
	if (n < 1) return 0;
	else return (1 / n) + add2(n - 1);
}
//15번
int fib(int n)
{
	printf("fib(%d) is called \n", n);
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
//16번
int sum1(int n) //반복
{
	int result = 0;
	for (int i = 0; i <= n; i++) {
		result += i;
	}
	return result;
}

int sum2(int n) //순환
{
	if (n == 1) return 1;
	else return (n + sum2(n - 1));
}
//17번
int bino(int n, int k) //순환
{
	if (k == n || k == 0) return 1;
	else if (k > 0 && k < n) 
	{
		return	bino(n - 1, k - 1) + bino(n-1, k);
	}
}

int bino2(int n, int k) //반복
{

}

int main() {
	//1
	printf("순환 : %d, ", sub(10));
	printf("반복 : %d \n", sub2(10));
	//12
	//unknown();
	//13
	printf("[문제13] %d \n", add(5));
	//14
	printf("[문제14] %f \n", add2(5));
	//15
	printf("[문제15] 답: %d \n",fib(6));
	//16
	printf("[문제16] 반복: %d, 순환: %d \n", sum1(5),sum2(5));
	//17
	printf("[문제17] 반복: %d, 순환: %d \n", bino(5, 3),bino2(5,3));
	
	return 0;
}*/