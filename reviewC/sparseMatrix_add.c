#include <stdio.h>

#define MAX_TERMS 10
typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	// 행의 개수
	int cols;	// 열의 개수
	int terms; 	// 0이 아닌 항의 개수
} SparseMatrix;

//희소 행렬 덧셈함수
SparseMatrix sparse_matrix_add(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix c;
	int ca = 0, cb = 0, cc = 0;
	//크기가 같은지를 확인
	if (a.rows != b.rows || a.cols != b.cols)
	{
		printf("희소행렬 크기 에러 \n"); // 두 희소행렬의 열과 행의 개수가 같아야한다.
		exit(1);
	}
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	while (ca < a.terms && cb < b.terms) {
		// [0 1 2] 
		// [3 4 5]
		// [6 7 8]
		// a의 인덱스 = a의 ca번째 원소의 행 * a의 열의 개수 + a의 ca번째 원소의 열
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col; 

		if (inda < indb) //b항목이 더 나중에 와야함
			c.data[cc++] = a.data[ca++];
		else if (inda == indb)
		{
			if ((a.data[ca].value + b.data[cb].value) != 0) {//희소 행렬이기 때문에 value가 0이면 인덱스만 증가시킨다.

				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;

			}
			else {
				ca++; cb++;
			}
		}
		else
			c.data[cc++] = b.data[cb++];
	}

	//나머지 항들을 옮긴다.
	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];
	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];
	c.terms = cc;
	return c;

}


void matrix_print(SparseMatrix a)
{
	printf("====================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}


void main()
{
	SparseMatrix m1 = { { { 1,1,5 },{ 2,2,9 } }, 3,3,2 };
	matrix_print(m1);
	SparseMatrix m2 = { { { 0,0,5 },{ 2,2,9 } }, 3,3,2 };
	matrix_print(m2);
	SparseMatrix m3;

	m3 = sparse_matrix_add(m1, m2);
	matrix_print(m3);
}