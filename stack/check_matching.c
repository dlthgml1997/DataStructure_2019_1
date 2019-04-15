#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100

typedef int element;

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
// 괄호 검사 함수
int check_matching(const char *in) {

	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n= 들어온 문자배열의 길이
	init_stack(&s); // 스택 초기화

	for (i = 0; i < n; i++)
	{
		ch = in[i]; // ch는 다음 문자
		switch (ch)
		{
		case '(': case '[': case '{': //왼쪽괄호이면
			push(&s, ch); //삽입
			break;
		case')': case'}': case']':
			if (is_empty(&s)) //만약 비어있다면
				return 0; //오류
			else {
				open_ch = pop(&s);// 전에 입력된 ch값 
				// ch 와 open_ch 의 짝이 맞지 않으면
				if (open_ch == '(' && ch != ')' || open_ch == '{' && ch != '}' || open_ch == '[' && ch != ']')
					return 0;
			}
			break;
		default:
			break;
		}
	}
	if (!is_empty(&s)) return 0; //다 돌았는데 비어있지 않으면 오류
	return 1;
}
int main() {
	char *p = "{A[(i+1)]}=0";
	if (check_matching(p) == 1)
		printf("%s 괄호 검사 성공 \n", p);
	else
		printf("%s 괄호 검사 실패 \n", p);
	return 0;
}