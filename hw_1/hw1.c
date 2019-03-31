#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 101
#define MAX_TERMS 10 

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	// ���� ����
	int cols;	// ���� ����
	int terms; 	// 0�� �ƴ� ���� ����
} SparseMatrix;

void matrix_print(SparseMatrix a);
typedef struct student {
	int id;
	double eng;
	double math;
}student;

typedef struct polynomial {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

double math_avg(student *student, double length) {
	double total = 0;
	for (int i = 0; i < length; i++) {
		total += student[i].math;
	}
	return total / length;
}

double eng_avg(student *student, double length) {
	double total = 0;
	for (int i = 0; i < length; i++) {
		total += student[i].eng;
	}
	return total / length;
}

double math_standard_deviation(student *student, double length,double avg) {
	double total = 0;
	for (int i = 0; i < length; i++)
	{
		total += (student[i].math - avg)*(student[i].math - avg);
	}
	return sqrt(total / (length - 1));
}

double eng_standard_deviation(student *student, double length, double avg) {
	double total = 0;
	for (int i = 0; i < length; i++)
	{
		total += (student[i].eng - avg)*(student[i].eng - avg);
	}
	return sqrt(total / (length - 1));
}

double* math_high(student *student, double length)
{
	double score = student[0].math;
	double id = student[0].id;
	for (int i = 0; i < length; i++)
	{
		if (student[i].math > score)
		{
			score = student[i].math;
			id = student[i].id;
		}
	}
	double max[] = { id,score };
	return &max;
}

double* eng_high(student *student, double length)
{
	double score = student[0].eng;
	double id = student[0].id;
	for (int i = 0; i < length; i++)
	{
		if (student[i].eng > score)
		{
			score = student[i].eng;
			id = student[i].id;
		}
	}
	double max[] = { id,score };
	return &max;
}

double* total_high(student *student, double length)
{
	if (eng_high(student, length)[1] > math_high(student, length)[1])
		return eng_high(student, length);
	else
		return math_high(student, length);
}

void print_student(student *student,int id,int length) {
	int eng_rank = 1;
	int math_rank = 1;
	int total_rank = 1;
	int student_index = 0;
	for (int j = 0; j < length; j++) {
		if (student[j].id == id)
			student_index = j;
	}
	for (int i = 0; i < length; i++) {
		if (student[student_index].eng < student[i].eng) eng_rank++;
	}
	for (int k = 0; k < length; k++) {
		if (student[student_index].math < student[k].math) math_rank++;
	}
	for (int k = 0; k < length; k++) {
		if (student[student_index].math+ student[student_index].eng < student[k].math+ student[k].eng)
			total_rank++;
	}
	printf("���� ����: %d��, ���� ���� : %d��, �� ����: %d�� \n", eng_rank, math_rank, total_rank);
}
//2-1
int eval(polynomial p,int a){
	int result = 0;
	int k = p.degree;
	for (int i = 0; i <= p.degree; i++) {
		result += p.coef[i]*pow((double)a,(double) k);
		k--;
	}
	return result;
}

polynomial remove1(polynomial a)
{
	float n[MAX_DEGREE];
	int k = a.degree;
	int bd = 0; //0�̾ƴ� �ְ������� ����
	int num = 0;

	for (int i = 0; i < a.degree; i++) {
		n[i] = a.coef[i + 1];
		k--;
		if (a.coef[i + 1] != 0) {
			num++;
			if (num == 1) bd = k;
		}
		i++;
	}
	polynomial b;
	b.degree = bd;
	int se = 0;
	int temp[MAX_DEGREE];
	int jj = a.degree-1 ;
	for (int ii = 0; ii < a.degree; ii++) { //�迭 ������
		temp[ii] = n[jj];
		jj--;
	}
	for (int g = 0; g <= a.degree; g++)
	{
		if (g <= bd)
		{
			b.coef[se] = temp[g]; se++;
		}

	}
	return b;
}
///3
SparseMatrix change(SparseMatrix m, int i, int j)
{
	SparseMatrix ch_m = m;
	int num;
	//row ����(��) , col ����(��)

	for (num = 0; num < m.terms ; num++) { //��ٲٱ�
			if (ch_m.data[num].row == i) {
				ch_m.data[num].row = j;
			}
			else if(ch_m.data[num].row == j)
			{
				ch_m.data[num].row = i;
			}
	}
	printf("�� �ٲٱ�: \n");
	matrix_print(ch_m);
	SparseMatrix temp_m = ch_m;

	for (int num2 = 0; num2 < m.terms*m.terms ; num2++)
	{
		for (num = 0; num < m.terms-1 ; num++)
		{
			int p = num + 1;

			if (ch_m.data[num].row > ch_m.data[p].row)
			{
				temp_m.data[num] = ch_m.data[num];
				ch_m.data[num] = ch_m.data[p];
				ch_m.data[p] = temp_m.data[num];

			}
			else if (ch_m.data[num].row == ch_m.data[p].row)
			{
				if (ch_m.data[num].col > ch_m.data[p].col)
				{
					temp_m.data[num] = ch_m.data[num];
					ch_m.data[num] = ch_m.data[p];
					ch_m.data[p] = temp_m.data[num];
				}
			}

		}
	}
	return ch_m;
}

void matrix_print(SparseMatrix a)
{
	for (int i = 0; i < a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}

int main() {
	student students[10] = { {1234,78,87},{1235,65,55},{1365,88,95},{2546,45,56}
		,{3124,58,88},{1976,71,54},{1657,32,55},{2547,90,43},{2456,66,78},{1765,54,99} };
	//1-(1)
	printf("[���� ���] %.2f \n", math_avg(&students, 10));
	printf("[���� ���] %.2f \n", eng_avg(&students, 10));
	printf("[���� ǥ������] %.2f \n", math_standard_deviation(&students, 10, math_avg(&students, 10)));
	printf("[���� ǥ������] %.2f \n", eng_standard_deviation(&students, 10, eng_avg(&students, 10)));
	printf("[���� �ְ�����] �л�: %.0f, ����: %.2f \n", math_high(&students, 10)[0], math_high(&students, 10)[1]);
	printf("[���� �ְ�����] �л�: %.0f, ����: %.2f \n", eng_high(&students, 10)[0], eng_high(&students, 10)[1]);
	printf("[���� �ְ�����] �л�: %.0f, ����: %.2f \n", total_high(&students, 10)[0], total_high(&students, 10)[1]);
	//1-(2)
	printf("�й��� �Է��ϼ���.\n");
	int id = 0;
	scanf("%d", &id);
	print_student(&students, id, 10);
	//2-(1)
	polynomial p = { 5,{10,0,0,0,6,1} };
	printf("[2-1] p(2) = %d \n", eval(p, 2));
	//2-(2)
	polynomial n[MAX_DEGREE];
	printf("[2-2] ���� ū ������ ���׽��� ������ ���: ");
	n->degree = remove1(p).degree; //3
	int hee = n->degree +1; //4
	int degree = n->degree; //3
	for (int g = 0; g <hee ; g++)
		n->coef[g] = remove1(p).coef[g];

	printf("%.0fx^%d",n->coef[degree],degree);
	
	for (int i = degree-1; i >=0 ; i--) {
		if (i<degree) {
			if (n->coef[i] != 0) {
				printf("+ %.0fx^%d", n->coef[i], degree-1);
				//if (i != 0) { printf("+ "); }
			}
			degree--;	
		}
	}
	printf("\n");
	//3-1
	SparseMatrix m = { { { 0,0,2 },{0,2,-3},{1,2,4},{2,0,4},{2,1,-2},{2,2,1},{3,3,3} }
	, 4,4,7 };
	printf("�� �ٲٱ� ��: \n");
	matrix_print(m);
	SparseMatrix ch_m = change(m, 0, 2);
	printf("���� ������ ������ ����: \n");
	matrix_print(ch_m);
	return 0;
}