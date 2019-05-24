#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;  //행번호
	int col;   //열번호
	int value; //값
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct {
	int rows;//행의 갯수
	int cols;//열의 개수
	ListNode* head;//연결리스트의 시작
	ListNode* tail;//연결리스트의 끝.
}ListHeader;

// 오류 함수
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node_last(ListHeader* plist, element x)
{
	ListNode* temp =
		(ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) perror("메모리 할당 에러");
	temp->data = x;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
}



void init(ListHeader* plist, int r, int c)
{
	plist->rows = r;
	plist->cols = c;
	plist->head = NULL;
	plist->tail = NULL;
}

void print_matrix(ListHeader* plist)
{
	ListNode* p = plist->head;
	while (p != NULL) {
		printf("%d %d %d\n", p->data.row, p->data.col, p->data.value);
		p = p->link;
	}
}

ListHeader* matrix_transpose(ListHeader* list1) {
	ListHeader list2;
	init(&list2, 4, 3);
	ListNode* temp = list1->head;
	ListNode* temp2 = list1->head;

	if (temp != NULL)
	{
		for (int c = 0; c < list1->cols; c++) {
			while (temp!=NULL)
			{
					temp2->data.row = temp->data.col;
					temp2->data.col = temp->data.row;
					temp2->data.value = temp->data.value;
					insert_node_last(&list2, temp2->data);
				temp= temp->link;
			}
		}
	}
	print_matrix(&list2);
}


int main()
{
	ListHeader list1;
//	ListHeader list2;
	init(&list1, 3, 4);
	//init(&list2, 3, 4);

	element x = { 0,0,2 };
	insert_node_last(&list1, x);
	element x2 = { 0,4,1 };
	insert_node_last(&list1, x2);
	element x3 = { 1,1,3 };
	insert_node_last(&list1, x3);
	element x4 = { 2,0,-2 };
	insert_node_last(&list1, x4);

	print_matrix(&list1);

	matrix_transpose(&list1);

	/*
	element y = {0,2,4};
	insert_node_last(&list2, y);
	element y2 = {0,3,-1};
	insert_node_last(&list2, y2);
	element y3 = {2,2,1};
	insert_node_last(&list2, y3);
	element y4 = {2,3,-1};
	insert_node_last(&list2, y4);

	print_matrix(&list2);
	*/

	return 0;
}