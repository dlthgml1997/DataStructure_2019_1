#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
/* 다항식의 계수가 0인 차수를 제외하고 더하는 프로그램*/
typedef struct {
	float coef; //계수
	int expon; //차수
}polynomial;

/*전역변수로 선언*/
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int avail = 6; //나중에 새로운 항을 다항식에 추가할 때 필요

//두개의 정수를 비교 // 차수 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

//새로운 항을 다항식에 추가
void attach(float coef, int expon) //(계수,차수) // 계수가 큰 순서부터 저장됨 
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음 \n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

// As = 현재 인덱스 , Ae = 최대 인덱스
// C만 포인터인 이유: 새로 생성되기 때문에 이곳저곳에서 주소를 이용해 생성할 수 있도록..?
void poly_add(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail; //C배열 시작 인덱스
	while (As <= Ae && Bs <= Be) // As,Bs 만 변하는 값
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>': // A차수> B차수
			attach(terms[As].coef, terms[As].expon);
			As++; break;
		case '=': //A차수 ==B차수
			tempcoef = terms[As].coef + terms[Bs].coef; //A와 B의 계수를 더해서
			attach(tempcoef, terms[As].expon); //더한값을 A(또는 B)의 차수에 붙여라
			As++; Bs++; break;
		case '<': //A차수 < B차수
			attach(terms[Bs].coef, terms[Bs].expon); //B의 계수를 B의 차수에 붙여라
			Bs++;  break;
		}
		//A의 나머지 항들을 이동
		for (; As <= Ae; As++)
			attach(terms[As].coef, terms[As].expon);
		//B의 나머지 항들을 이동
		for (; Bs <= Be; Bs++)
			attach(terms[Bs].coef, terms[Bs].expon);
		*Ce = avail - 1; //왜??
		printf("*Ce = %d \n", *Ce);
	
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d+", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d \n", terms[e].coef, terms[e].expon);
}

int main() {
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("--------------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}