#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100

typedef struct {
	short r;
	short c;
}element; //추가

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;

} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

element here = { 1,0 }, entry = { 1,0 }; // 현재위치와 입구

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

// 주변 위치 (아래,위,왼쪽,오른쪽 순서대로) stack에 저장
void push_loc(StackType *s,int r,int c) { //*s 로 받아와
	if (r < 0 || c < 0) return; // 좌표가 0보다 작을 때
	if (maze[r][c] != '.' && maze[r][c] != '1')
	{
		element temp;
		temp.r = r;
		temp.c = c;
		push(s, temp); //&s 아님에 주의
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++){
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
	}
		printf("\n");
	}
}

int main() {
	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공 \n");

	return 0;

}

