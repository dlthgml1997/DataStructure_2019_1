#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

ListNode *insert_first(ListNode *head, element value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//�ܼ� ���� ���� ����Ʈ���� ������������ ���ĵ�
// �� ���Ḯ��Ʈ�� �ϳ��� ���Ḯ��Ʈ�� ���� ��
ListNode* merge(ListNode *head1, ListNode *head2) {
	ListNode *head = NULL, *tail = NULL;
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	while (head1 != NULL && head2 != NULL) { //�� �� �ϳ��� ���̸� ��
		if (head1->data <= head2->data) {
			if (tail == NULL) {
				head = tail = head1;
			}
			else {
				tail->link = head1;
				tail = tail->link;
			}
			head1 = head1->link; 
		}
		else { // head1�� �����Ͱ� head2�� �����ͺ��� Ŭ ��
			if (tail == NULL) {
				head = tail = head2;
			}
			else {
				tail->link = head2;
				tail = tail->link;
			}
			head2 = head2->link;
		}
	}
	//�ϳ��� head�� NULL�� ���� ��, �ٸ� head�� ���� ������ tail�� ��.
	if (head1 != NULL) tail->link = head1; 
	if (head2 != NULL) tail->link = head2;

	return head;
}

int main() {
	ListNode *head1=NULL, *head2=NULL;

	head1 = insert_first(head1, 40);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 10); //��������
	print_list(head1);

	head2 = insert_first(head2, 50);
	head2 = insert_first(head2, 30); //��������
	print_list(head2);

	ListNode *total;
	total = merge(head1, head2);
	print_list(total);
}