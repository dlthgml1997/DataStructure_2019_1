#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
	int length;
}LinkedListType;

void error(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

void init(LinkedListType* list)
{

	list->length = 0;
	list->head = NULL;
}

ListNode* get_node_at(LinkedListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0 || pos >= list->length) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;

}
ListNode * insert_first(ListNode * head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode * head, ListNode * pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode * head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete_node(ListNode * head, ListNode * pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void add(LinkedListType * list, int position, element data)
{
	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) error("memory allocation error");
		node->data = data;
		p = get_node_at(list, position - 1);
		//insert_node(&(list->head), p, node);
		if (position == 0) list->head = insert_first(list->head, data);
		else if (p)
			list->head = insert(list->head, p, data);
		else error("위치에러");
		list->length++;
	}
}

int get_length(LinkedListType * list)
{
	return list->length;
}
void add_last(LinkedListType * list, element data)
{
	add(list, get_length(list), data);
}
void add_first(LinkedListType * list, element data)
{
	add(list, 0, data);
}

int is_empty(LinkedListType * list)
{
	if (list->head == NULL) return 1;
	else return 0;
}
void delete_item(LinkedListType * list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode* p = get_node_at(list, pos - 1);
		//다음 줄 책에 있는 소스 틀림. 다음과 같이 수정
		//remove_node(&(list->head), p, (p != NULL) ? p->link : list->head);
		if (p) list->head = delete_node(list->head, p);
		else list->head = delete_first(list->head);
		list->length--;
	}
}
element get_entry(LinkedListType * list, int pos)
{
	ListNode* p;
	if (pos >= list->length) error("position error");
	p = get_node_at(list, pos);
	return p->data;
}
//책에 나와 있는 clear함수 틀림 (2)와 같이 고쳐야 함
/*(1)
void clear(LinkedListType *list)
{
int i;
for(i=0;i<list->length;i++)
delete_element(list,i);
}
*/
//(2)
void clear(LinkedListType * list)
{
	int i;
	int k = list->length;
	for (i = 0; i < k; i++)
		delete_item(list, 0);
}
void display(LinkedListType * list)
{
	int i;
	ListNode* node = list->head;

	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);

		node = node->link;
	}
	printf("\n");
}

int is_in_list(LinkedListType * list, element data)
{

	ListNode* p = list->head;
	while (p) {
		if (p->data == data)
			break;
		p = p->link;
	}
	if (p = NULL) return FALSE;
	else return TRUE;
}

int get_position(LinkedListType * list, element data)
{
	ListNode* p = list->head;
	int pos = 0;
	while (p) {
		if (p->data == data)
			return pos;
		pos++;
		p = p->link;
	}
	return -1;
}


void main()
{

	LinkedListType list1;

	init(&list1);
	add(&list1, 0, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 3, 100);
	// list1 = (10, 20, 30, 40)
	display(&list1);

	// list1 = (10, 20, 30)
	delete_item(&list1, 3);
	display(&list1);

	// list1 = (20, 30)
	delete_item(&list1, 0);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "성공" : "실패");
	printf("%d\n", get_entry(&list1, 0));


}

