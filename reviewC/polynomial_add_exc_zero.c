#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
/* ���׽��� ����� 0�� ������ �����ϰ� ���ϴ� ���α׷�*/
typedef struct {
	float coef; //���
	int expon; //����
}polynomial;

/*���������� ����*/
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int avail = 6; //���߿� ���ο� ���� ���׽Ŀ� �߰��� �� �ʿ�

//�ΰ��� ������ �� // ���� ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

//���ο� ���� ���׽Ŀ� �߰�
void attach(float coef, int expon) //(���,����) // ����� ū �������� ����� 
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ���� \n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

// As = ���� �ε��� , Ae = �ִ� �ε���
// C�� �������� ����: ���� �����Ǳ� ������ �̰��������� �ּҸ� �̿��� ������ �� �ֵ���..?
void poly_add(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail; //C�迭 ���� �ε���
	while (As <= Ae && Bs <= Be) // As,Bs �� ���ϴ� ��
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>': // A����> B����
			attach(terms[As].coef, terms[As].expon);
			As++; break;
		case '=': //A���� ==B����
			tempcoef = terms[As].coef + terms[Bs].coef; //A�� B�� ����� ���ؼ�
			attach(tempcoef, terms[As].expon); //���Ѱ��� A(�Ǵ� B)�� ������ �ٿ���
			As++; Bs++; break;
		case '<': //A���� < B����
			attach(terms[Bs].coef, terms[Bs].expon); //B�� ����� B�� ������ �ٿ���
			Bs++;  break;
		}
		//A�� ������ �׵��� �̵�
		for (; As <= Ae; As++)
			attach(terms[As].coef, terms[As].expon);
		//B�� ������ �׵��� �̵�
		for (; Bs <= Be; Bs++)
			attach(terms[Bs].coef, terms[Bs].expon);
		*Ce = avail - 1; //��??
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