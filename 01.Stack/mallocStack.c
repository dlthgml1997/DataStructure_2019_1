#include <stdio.h>
#include <stdlib.h>

/* ���� stack */
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element *data; // �����ʹ� �����ͷ� ���ǵȴ�.
	int capacity; // ���� ũ��
	int top;

} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		// data�� ����ũ��*element�� ũ�⸸ŭ ���Ҵ�
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ���� \n");
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