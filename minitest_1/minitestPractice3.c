
#include <stdio.h>
// c-test 

typedef enum _boolean {
	FALSE,
	TRUE
} boolean;

typedef struct tri {
	int a;
	int b; 
	int c;
}tri;

#define FALSE 0
#define TRUE 1

//2-4번
boolean triangle(int a, int b, int c) {
	if (a >= b && a >= c) {
		if (c + b > a) return TRUE;
		else return FALSE;
	}
	else if (b >= a && b >= c) {
		if (a + c > b) return TRUE;
		else return FALSE;
	}
	else {
		if (a + b > c) return TRUE;
		else return FALSE;
	}

}

//2-6번
int sum(int a[], int n) {
	if (n-1 < 0) return 0;
	else return a[n - 1] + sum(a, n - 1);
}

int main() {
	//2-4번
	printf("%d \n", triangle(4, 2, 1));
	//2-6번
	int a[] = {1,2,3,4,5};
	printf("%d \n", sum(a, 5));
	//3번
	int *p, q;
	q = 99;
	p = &q;
	printf("%d,%d\n", *p, p);
	q++;
	printf("%d,%d\n", q, p);
	(*p)++;
	printf("%d,%d\n", q, *p);
	q++;
	p++;
	printf("%d,%d\n", q, p);
	//4번
	int arr[5] = { 2,4,6,8,10 };
	int *po;
	po = arr;
	printf("%d,%d\n", *po, *(po + 3));
	//6번
	tri tri = {1,1,3};
	if (tri.a > tri.b&&tri.a > tri.c) {
		if (tri.a*tri.a == tri.b*tri.b + tri.c*tri.c)
			printf("true\n");
		else printf("false\n");
	}else if (tri.b > tri.a&&tri.b > tri.c) {
		if (tri.b*tri.b == tri.a*tri.a + tri.c*tri.c)
			printf("true\n");
		else printf("false\n");
	}else{
		if (tri.c*tri.c == tri.b*tri.b + tri.a*tri.a)
			printf("true\n");
		else printf("false\n");
	}
	//7번
	int max = 0;
	int index = 0;
	int arr2[7] = { 1,2,3,2,1,8,6 };
	for (int i = 0; i < 6; i++)
	{
		if (arr2[i] > arr2[i + 1]) {
			max = arr2[i];
			index = i;
		}
		else
		{
			max = arr2[i + 1];
			index = i + 1;
		}

	}
	printf("max: %d, index: %d \n", max,index);
	//8-4,5

	char str1[] = "data";
	char str2[10];
	char *p0,*q0;
	p0 = str1;
	int i = 0;
	while (*p0) {
		p0++;
		i++;
	}
	printf("i=%d\n", i);
	p0--;
	q0 = str2;
	while (i>0) {
		*q0= *p0;
		q0++;
		p0--;
		i--;
	}
	*q0 = '\0';
	printf("%s", str2);
	
	

	return 0;
}