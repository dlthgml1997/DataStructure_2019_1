#include <stdio.h>

//x��n���� ���� ���ϴ� ����
double slow_power(double x,int n) //�ݺ�
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= x;
	}
	return result;
}

double power(double x, int n) //��ȯ
{
	if (n == 0) return 1;
	else if ((n % 2) == 0) return power(x*x, n / 2);
	else return x*power(x*x, (n - 1) / 2);
}

int main(){

	printf("�ݺ� : %.1f \n", slow_power(2, 3)); // �ð����⵵ : O(n) , ���� ����ӵ�: 7.17��
	printf("��ȯ : %.1f \n", power(4, 3)); // �ð����⵵ : O(log n), ���� ����ӵ� : 0.47��
	return 0;
}