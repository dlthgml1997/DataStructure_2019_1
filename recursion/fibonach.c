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
	for (int i = 2; i <= n; i++) // 0,1�� �� ����
	{
		result = pp + p;
		pp = p;
		p = result;
	}
	return result;
}
int main()
{

	printf("��ȯ : %d \n", fib(4)); //��ȯ //���� �Լ��� �ߺ��Ǿ ����
	printf("�ݺ� : %d \n", fib_iter(4)); //�ݺ� : �� ȿ����
	return 0;
}