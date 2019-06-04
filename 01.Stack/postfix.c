#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ����ǥ��� ���α׷�
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
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
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 
int eval(const char *exp)
{
	int op1, op2, value, i = 0;
	int len = strlen(exp); //���� ����ǥ����� ����
	char ch;
	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+'&&ch != '/'&&ch != '*'&&ch != '-')
		{// �Է��� �ǿ������̸�
			value = ch - '0';  //�ƽ�Ű�ڵ� -> 10����
			push(&s, value);
		}
		else
		{ //�������̸�  2���� ���ÿ��� ����
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+':push(&s,op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*':push(&s, op1 * op2); break;
			case '/':push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main() {

	int result;
	printf("���� ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� : %d \n", result);
	return 0;
}