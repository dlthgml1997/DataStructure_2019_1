#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

// ���� ó�� �Լ�
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
//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; //���ο� ����� ��
	p->link = pre->link; // ���ο� ����� ���� ���� ���� ����� ���� �������
	// pre -> p -> �������
	pre->link = p; //���� ����� �������� p
	return head;
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;// ���� �ƴϿ����� 
	removed = head;  //���°� �����Ǿ����
	head = removed->link; // head�� removed�� ���� ���
	free(removed); // removed�� ���ش�
	return head; // removed�� ���� ��带 ��ȯ
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
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