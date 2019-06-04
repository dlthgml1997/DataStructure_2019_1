#include <stdio.h>
#include <stdlib.h>

/* 동적 stack */
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element *data; // 데이터는 포인터로 정의된다.
	int capacity; // 현재 크기
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

void push(StackType *s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		// data를 현재크기*element의 크기만큼 재할당
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러 \n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	StackType *s;
	s = (StackType *)malloc(sizeof(StackType));

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s)); //3
	printf("%d\n", pop(&s)); //2
	printf("%d\n", pop(&s)); //1
	free(s);
	return 0;
}