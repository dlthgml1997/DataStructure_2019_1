/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//2-1
typedef struct point {
	double x;
	double y;
} point;

typedef struct line {
	point arr[2];
}line;


//수시고사 문제 1-1번
int divisor(int n) {
	printf("[문제1-1] %d의 약수의 개수:", n);
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			//	printf(" %d",i);
			num++;
		}
	}
	return num;
}

//수시고사 문제 1-2번
int max_num(int *p, int n) {
	printf("[문제1-2] ");
	int max_num = 0;
	int index = 0;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		if (max_num < p[i]) {
			max_num = p[i];
			index = i;
		}
	}
	temp = p[n - 1];
	p[n - 1] = max_num;
	p[index] = temp;

	return p;

}

//수시고사 문제 1-3번
int find_ch(char *p, char a) {
	printf("[문제1-3] ");
	int num = 0;
	for (int i = 0; i < sizeof(p); i++) {
		if (p[i] == a) {
			num++;
		}
	}
	return num;
}

//수시고사 2-1번
void f(point a, point b, double *dist) {
	printf("[문제2-1] ");
	*dist = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

//수시고사 2-2번
double slope(line t) {
	printf("[문제2-2],");
	return (t.arr[1].y - t.arr[0].y) / (t.arr[1].x - t.arr[0].y);
}

//수시고사 4-1번 (1)
int sum1(int a[], int n) //반복
{
	printf("[문제4-1] 반복: ");
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			result += a[i];
	}
	return result;
}

//수시고사 4-1번 (2)
int sum2(int a[], int n) //순환
{
	if (n == 0) return 0;
	else if (a[n - 1] % 2 == 0) return a[n - 1] + sum2(a, n - 1);
	else return sum2(a, n - 1);

}

//수시고사 문제 4-2번
void A(int n)
{
	if (n > 1) {
		A(n - 2);
		A(n - 3);

		printf("%d ", n);
	}
}

int main() {
	//1-1
	printf("%d \n", divisor(18));
	//1-2
	int p[6] = { 4,6,2,7,21,8 };
	max_num(&p, 6);
	for (int i = 0; i < 6; i++)
		printf("%d ", p[i]);
	printf("\n");
	//1-3
	char ch[] = "hello";
	char *po;
	po = ch;
	printf("%d개 \n", find_ch(po, 'l'));
	//2
	struct point a = { 1,2 };
	struct point b = { 3,4 };
	//2-1
	double dist = 0;
	f(a, b, &dist);
	printf("%f \n", dist);
	//2-2,2-3
	line c = { a, b };
	printf("[문제2-3] %.2f \n", slope(c));
	//2-4
	point *space;
	space = (point *)malloc(3 * sizeof(point));
	printf("[문제2-4]");
	if (space == NULL) {
		printf("동적메모리 할당 실패");
		exit(1);
	}
	space->x = 1;
	space->y = 2;
	(space + 1)->x = 3;
	(space + 1)->y = 2;
	(space + 2)->x = 4;
	(space + 2)->y = 2;
	for (int k = 0; k < 3; k++) {
		printf("{%.0f,%.0f} ", (double)space[k].x, (double)(space+k)->y);
	}
	printf("\n");
	free(space);
	//4-1
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sizeOfArr = sizeof(arr) / sizeof(int);
	printf("%d ", sum1(arr, sizeOfArr));
	printf(", 순환: %d \n", sum2(arr, sizeOfArr));
	//4-2
	printf("[문제4-2] ");
	A(6);
	printf("\n");


	return 0;
}

*/