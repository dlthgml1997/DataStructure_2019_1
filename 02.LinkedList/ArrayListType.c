#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size; //현재 리스트에 저장된 항목들의 갯수
} ArrayListType;

//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
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

// pos번째 요소 반환
element get_entry(ArrayListType *L, int pos)
{
	if (pos < 0 || pos >= L->size)
	{
		error("위치 오류");
	}
	return L->array[pos];

}

//리스트 출력
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
		error("리스트 오버플로우");
		}
	L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item)
{
	//포화상태가 아니고 0이상의 포지션, 사이즈보다 이하의 포지션
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i]; //pos를 만날 때까지 이전 array값을 다음 array값으로 옮김
		L->array[pos] = item;
		L->size++; // 하나 추가됐으니까 사이즈 하나 늘림
	}
}

element delete(ArrayListType *L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size) //get_entry함수에도 쓰임
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i <= (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item; //반환하면서 삭제
}

int main() {
	//ArrayListType을 정적으로 생성하고 AllayListType을
	//가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;

	init(&list);
	insert(&list, 0, 10); print_list(&list); // 10
	insert(&list, 0, 20); print_list(&list); // 20 10
	insert(&list, 0, 30); print_list(&list); // 30 20 10
	insert_last(&list, 40); print_list(&list); // 30 20 10 40
	delete(&list, 0); print_list(&list); // 20 10 40
	return 0;
}