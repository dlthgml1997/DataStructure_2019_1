#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;

} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType * s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType * s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int prec(char op) // 연산자 우선순위 반환
{
	switch (op)
	{
	case ')': case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2; 
	}
	return -1; // 오류
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
		if (ch>='0'&&ch<='9') { //숫자일 때
			value = ch - '0'; 
			push(&num, value);
		}
		else //숫자가 아닐때
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
	printf("중위표시수식 %s \n", s);
	printf("답: %f \n",infix(s));
	return 0;
}