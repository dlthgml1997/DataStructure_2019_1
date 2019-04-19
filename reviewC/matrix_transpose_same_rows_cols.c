#include <stdio.h>
#define ROWS 3
#define COLS 3
//��� ��ġ �Լ�
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) //A = ��ġ�� ��� ,B=��ġ�� ���
{
	for (int r = 0; r < ROWS; r++) { //��
		for (int c = 0; c < COLS; c++) //��
			B[r][c] = A[c][r];
	}
}
void matrix_print(int A[ROWS][COLS])
{
	printf("===========\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) 
			printf("%d", A[r][c]);
		printf("\n");
	}
}

int main()
{
	int array[ROWS][COLS]={ {2,3,0},
	{8,9,1},
	{7,0,5} };

	int array2[ROWS][COLS];
	matrix_transpose(array, array2);
	matrix_print(array);
	matrix_print(array2);

	return 0;

}