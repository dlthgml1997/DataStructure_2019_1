#include <stdio.h>
#include <stdlib.h>

//매개변수 x는 정수에 대한 이중 포인터
void f(int **x)
{
	*x = *x + 1; 
	//이중포인터가 가리키고 있는 포인터가 가리키는 주소를 하나 증가
}

//g는 정수에 대한 포인터 반환 
int *g(int x) 
{
	//정수 x를 가리키는 포인터 반환
	int *px = (int *)malloc(sizeof(int));
	*px = x;
	return px;
}

void main()
{
	int a[3] = { 10,20,30 };
	int *p = &a[0];
	printf("p=%d\n", p); // a[0] 의주소
	f(&p);
	printf("*p=%d, p=%d\n", *p, p); //20 , a[0]의 주소+4
	p = g(40);
	printf("*p=%d, p=%d\n", *p, p); // 40, 40의 주소

}