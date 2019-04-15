#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100

typedef char element; // int ->char

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
// ===== 스택 코드의 끝 ===== 
int prec(char op) // 연산자 우선순위 반환
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1; // 오류
}
// 중위 표기수식 -> 후위 표기수식
void infix_to_postfix(const char *exp)
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp); // 들어온 문자열의 길이
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch)
		{
		case '+': case '-': case '/': case '*':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))// 비어있지 않고, 스택에 있는 연산자의 우선순위가 크거나 같으면
			printf("%c", pop(&s));
			push(&s, ch); // 비어있거나, 스택에 있는 연산자의 우선순위가 더 작으면
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s); // ch로 안하는 이유는 )는 출력되면 안되니까! 
			while (top_op != '(')
			{
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:
			printf("%c", ch);
			break;
}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main() {
	char *s = "(2+3)*4+9";
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;

}

