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
		printf("학번: %d, 영어: %d, 수학: %d \n", p->data.id,p->data.eng,p->data.math);
	printf("\n");
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode * insert(ListNode * head, ListNode * pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; //새로운 노드의 값
	p->link = pre->link; // 새로운 노드의 다음 노드는 이전 노드의 기존 다음노드
	// pre -> p -> 기존노드
	pre->link = p; //이전 노드의 다음노드는 p
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
	while (head1 != NULL && head2 != NULL) { //둘 중 하나가 널이면 끝
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
		else { // head1의 데이터가 head2의 데이터보다 클 때
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
	//하나의 head가 NULL이 됐을 때, 다른 head의 남은 노드들이 tail이 됨.
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
	printf("1반 \n");
	print_list(head1);

	printf("2반 \n");
	print_list(head2);

	printf("1반+2반 \n");
	total= merge(head1, head2);
	print_list(total);
	return 0;
}