#include <stdio.h>
#include <stdlib.h>

//�Ű����� x�� ������ ���� ���� ������
void f(int **x)
{
	*x = *x + 1; 
	//���������Ͱ� ����Ű�� �ִ� �����Ͱ� ����Ű�� �ּҸ� �ϳ� ����
}

//g�� ������ ���� ������ ��ȯ 
int *g(int x) 
{
	//���� x�� ����Ű�� ������ ��ȯ
	int *px = (int *)malloc(sizeof(int));
	*px = x;
	return px;
}

void main()
{
	int a[3] = { 10,20,30 };
	int *p = &a[0];
	printf("p=%d\n", p); // a[0] ���ּ�
	f(&p);
	printf("*p=%d, p=%d\n", *p, p); //20 , a[0]�� �ּ�+4
	p = g(40);
	printf("*p=%d, p=%d\n", *p, p); // 40, 40�� �ּ�

}