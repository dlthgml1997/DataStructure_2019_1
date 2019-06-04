#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
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
// ��ȣ �˻� �Լ�
int check_matching(const char *in) {

	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n= ���� ���ڹ迭�� ����
	init_stack(&s); // ���� �ʱ�ȭ

	for (i = 0; i < n; i++)
	{
		ch = in[i]; // ch�� ���� ����
		switch (ch)
		{
		case '(': case '[': case '{': //���ʰ�ȣ�̸�
			push(&s, ch); //����
			break;
		case')': case'}': case']':
			if (is_empty(&s)) //���� ����ִٸ�
				return 0; //����
			else {
				open_ch = pop(&s);// ���� �Էµ� ch�� 
				// ch �� open_ch �� ¦�� ���� ������
				if (open_ch == '(' && ch != ')' || open_ch == '{' && ch != '}' || open_ch == '[' && ch != ']')
					return 0;
			}
			break;
		default:
			break;
		}
	}
	if (!is_empty(&s)) return 0; //�� ���Ҵµ� ������� ������ ����
	return 1;
}
int main() {
	char *p = "{A[(i+1)]}=0";
	if (check_matching(p) == 1)
		printf("%s ��ȣ �˻� ���� \n", p);
	else
		printf("%s ��ȣ �˻� ���� \n", p);
	return 0;
}