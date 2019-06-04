#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size; //���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(ArrayListType *L)
{
	L->size = 0;
}

int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE;
}

// pos��° ��� ��ȯ
element get_entry(ArrayListType *L, int pos)
{
	if (pos < 0 || pos >= L->size)
	{
		error("��ġ ����");
	}
	return L->array[pos];

}

//����Ʈ ���
void print_list(ArrayListType *L)
{
	int i;
	for (int i = 0; i < L->size; i++)
		printf("%d ->", L -> array[i]);
	printf("\n");
}

void insert_last(ArrayListType *L, element item)
{
	if (L->size >= MAX_LIST_SIZE){
		error("����Ʈ �����÷ο�");
		}
	L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item)
{
	//��ȭ���°� �ƴϰ� 0�̻��� ������, ������� ������ ������
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i]; //pos�� ���� ������ ���� array���� ���� array������ �ű�
		L->array[pos] = item;
		L->size++; // �ϳ� �߰������ϱ� ������ �ϳ� �ø�
	}
}

element delete(ArrayListType *L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size) //get_entry�Լ����� ����
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i <= (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item; //��ȯ�ϸ鼭 ����
}

int main() {
	//ArrayListType�� �������� �����ϰ� AllayListType��
	//����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10); print_list(&list); // 10
	insert(&list, 0, 20); print_list(&list); // 20 10
	insert(&list, 0, 30); print_list(&list); // 30 20 10
	insert_last(&list, 40); print_list(&list); // 30 20 10 40
	delete(&list, 0); print_list(&list); // 20 10 40
	return 0;
}