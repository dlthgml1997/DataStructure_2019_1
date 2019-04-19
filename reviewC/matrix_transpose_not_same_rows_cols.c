#include <stdio.h>
#define ROWS 3
#define COLS 4
//행렬 전치 함수, 행의 갯수와 열의 갯수가 다를 때

void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS]) // B의 cols rows는 A의 rows cols
{
	for (int r = 0; r < ROWS; r++) //열
		for (int c = 0; c < COLS; c++) //행
			B[c][r] = A[r][c];
}

void matrix_print1(int A[][COLS]) //전치 전 행렬 출력
{
	printf("=======================\n");
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
			printf("%d ", A[r][c]);
		printf("\n");
	}
	printf("=======================\n");

}

void matrix_print2(int A[][ROWS]) //전치 된 행렬 출력
{
	printf("====================\n");
	for (int r = 0; r < COLS; r++) {
		for (int c = 0; c < ROWS; c++)
			printf("%d ", A[r][c]);
		printf("\n");
	}
	printf("====================\n");
}

int main(void)
{
	int array1[ROWS][COLS] = { { 2,3,0,1 },
	{ 8,9,1,2 },
	{ 7,0,5,3 } };
	int array2[COLS][ROWS];

	matrix_transpose(array1, array2);
	matrix_print1(array1);
	matrix_print2(array2); 
	return 0;
}
