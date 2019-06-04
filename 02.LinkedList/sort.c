#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100

typedef struct {
	int id;
	int eng;
	int math;
}student;
typedef student element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("�й�: %d, ����: %d, ����: %d \n", p->data.id,p->data.eng,p->data.math);
	printf("\n");
}

//��� pre �ڿ� ���ο� ��� ����
ListNode * insert(ListNode * head, ListNode * pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; //���ο� ����� ��
	p->link = pre->link; // ���ο� ����� ���� ���� ���� ����� ���� �������
	// pre -> p -> �������
	pre->link = p; //���� ����� �������� p
	return head;
}

ListNode* sort(ListNode * head, element class)
{
	ListNode* p =NULL, *pre =NULL;
	p = head;
	if (head == NULL || head->data.id > class.id)
		head = insert_first(head, class);
	else if (head->data.id< class.id)
	{
		while (p != NULL)
		{
			if (p->data.id > class.id)
				break;
			pre = p;
			p = p->link;
		}
		head = insert(head, pre, class);
	}
	return head;
}

ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode* head = NULL, * tail = NULL;
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	while (head1 != NULL && head2 != NULL) { //�� �� �ϳ��� ���̸� ��
		if (head1->data.id <= head2->data.id) {
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
	int len,i=0;
	ListNode* head1= NULL, *head2 =NULL, *total=NULL;

	element class1[5] = { {134,88,65},{125,95,90},{145,70,55},{128,75,50},{129,60,60} };
	element class2[5] = { {124,78,55},{135,65,70},{147,80,85},{115,95,90},{144,90,80} };

	len= sizeof(class1) / sizeof(element);
	for (i=0; i < len; i++)
	{
		head1 = sort(head1, class1[i]);
		head2 = sort(head2, class2[i]);
	}
	printf("1�� \n");
	print_list(head1);

	printf("2�� \n");
	print_list(head2);

	printf("1��+2�� \n");
	total= merge(head1, head2);
	print_list(total);
	return 0;
}