#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

// 오류 처리 함수
void error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* search_list(ListNode *head, element x)
{
	ListNode *p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; //새로운 노드의 값
	p->link = pre->link; // 새로운 노드의 다음 노드는 이전 노드의 기존 다음노드
	// pre -> p -> 기존노드
	pre->link = p; //이전 노드의 다음노드는 p
	return head;
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;// 널이 아니여야함 
	removed = head;  //들어온게 삭제되어야함
	head = removed->link; // head는 removed의 다음 노드
	free(removed); // removed를 없앤다
	return head; // removed의 다음 노드를 반환
}

//pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete_node(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode *head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	} // 4 3 2 1 0 
	ListNode *p = search_list(head, 2);
	if (p) {
		printf("%d \n", p->data); //2
	}
	head = insert(head, p, 100);
	print_list(head); // 4 3 2 100 1 0
	head = delete_node(head, p); 
	print_list(head); // 4 3 2 1 0

	head = insert(head, head, 200);
	print_list(head); // 4 200 3 2 1 0 
	head = delete_node(head, head);
	print_list(head); // 4 3 2 1 0 

	return 0;
}