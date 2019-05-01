#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;

} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType * s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType * s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int prec(char op) // ������ �켱���� ��ȯ
{
	switch (op)
	{
	case ')': case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2; 
	}
	return -1; // ����
}

double calc(double op1, double op2, char ch)
{
	double result = 0;
	switch (ch)
	{
	case '+': result = op1 + op2; break;
	case '-': result = op1 - op2; break;
	case '*': result = op1 * op2; break;
	case '/': result = op1 / op2; break;
	}
	return result;
}

double infix(const char* exp)
{
	double op1,op2,value;
	int i = 0;
	char ch, top_op;
	StackType num;
	StackType oper;
	init_stack(&num);
	init_stack(&oper);

	while (exp[i] != '\0')
	{
		ch = exp[i];
		if (ch>='0'&&ch<='9') { //������ ��
			value = ch - '0'; 
			push(&num, value);
		}
		else //���ڰ� �ƴҶ�
		{
			if (prec(ch) == 0)
			{
				if (ch == ')')
				{
					ch = pop(&oper);
					while (ch != '(')
					{
						op2 = pop(&num);
						op1 = pop(&num);
						push(&num, calc(op1, op2, ch));
						ch = pop(&oper);
					}
				}
				else if (ch == '(')
				{
					push(&oper, ch);
				}
			} else if (is_empty(&oper) || prec(ch) >= prec(peek(&oper)))
			{
				push(&oper, ch);
			}
			else 
			{	
				while (!is_empty(&oper) && prec(ch) < prec(peek(&oper)))
				{
					top_op = pop(&oper);
					op2 = pop(&num);
					op1 = pop(&num);
					push(&num, calc(op1, op2, top_op));
				}
				push(&oper, ch);
			}	
		}
		i++;
	}

	while (!is_empty(&oper))
	{
		ch = pop(&oper);
		op2 = pop(&num);
		op1 = pop(&num);
		push(&num, calc(op1, op2, ch));
	}
	return pop(&num);
}

int main()
{
	char* s = "(2+3)*4+9";
	printf("����ǥ�ü��� %s \n", s);
	printf("��: %f \n",infix(s));
	return 0;
}