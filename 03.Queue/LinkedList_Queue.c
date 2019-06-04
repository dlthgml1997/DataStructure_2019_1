#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct ListNode {
	QueueNode * front, * rear;
	struct ListNode* link;
}ListNode;


typedef struct LinkedListType {		// 큐 ADT 구현
	ListNode* head;
	int length;
} LinkedListType;

void error(const char* message) //에러
{
	printf("%s\n", message);
	exit(1);
}

// 큐 초기화 함수
void init(LinkedListType* q)
{
	q->length = 0;
	q->head = NULL;
}


void init_queue(LinkedListType* list, int line)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	for (int i = 0; i < line; i++)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (i==0) {
			temp->rear = 0;
			temp->front = 0;
			list->head = temp;
			p = temp;
		}
		else {
			if (i == line - 1)
			{
				temp->link = NULL;
			}
			p->link = temp;
			temp->rear = 0;
			temp->front = 0;
			p = temp;
		}
	}
	list->length = line;
}

void add_queue(LinkedListType* list, int queue_num, int data)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
	temp = list->head;
	int i = 0;
	if (list->head == NULL) error("메모리 할당 불가 \n");
	while (temp != NULL)
	{
		if (i == queue_num)
		{
			break;
		}else{
		temp = temp->link;
		}
		i++;
	}

	if (temp->front == NULL) {
		temp->front = q;
		temp->rear = q;
		q->data = data;
		q->link = NULL;
	}
	else {
		//q = q->link;
		q->data = data;
		q->link = NULL;
		temp->rear->link = q;
		temp->rear = q;
	}
}


void display_data(LinkedListType* list) {
	ListNode* temp = list->head;
	QueueNode* q = temp->front;
	while (temp != NULL)
	{
		q = temp->front;
		while (q != NULL)
		{
			printf("%d->", q->data);
			q = q->link;
		}
		printf("\n");
		temp = temp->link;
	}
}

void delete_queue(LinkedListType* list, int num)
{
	ListNode* temp = list->head;
	QueueNode* q = temp->front;
	QueueNode* remove = NULL;
	int i = 0;
	if (list->head == NULL) error("삭제가 불가능 \n");
	else {
		while (temp != NULL)
		{
			if (i == num) {
				remove = q;
				q = q->link;
				if (q == NULL) temp->rear = NULL;
				temp->front = q;
				free(remove);
			}
			temp = temp->link;
			i++;
		}
	}
}


void main()
{
	LinkedListType list1;
	init(&list1); //list1의 head는 NULL, length는 0이 되도록 초기화
	int line;
	printf("how many lines?\n"); //몇 개의 큐가 필요한가?
	scanf_s("%d", &line);
	init_queue(&list1, line); //line이 3이라면 list1의 head가 가리키는 연결리스트에는
	   //노드가 세 개 있으며 각각의 노드는 하나의 큐에 대한 head와 tail을 데이터로 갖          
	   //는다.  각 노드의 head와 tail을 NULL로 초기화 한다.

	   //위와 같이 할 수 없을 때는 처음부터 큐의 개수를 정해 놓고 시작하시오.

	printf("length=%d\n", list1.length); //노드의 개수가 맞는지 찍어 보기
	

   //line이 3이라고 하면 
//queue 0에 입력
	add_queue(&list1, 0, 1); //0번 큐에 1을 입력
	add_queue(&list1, 0, 2);
	add_queue(&list1, 0, 3);
	//queue 1에 입력
	add_queue(&list1, 1, 11); //1번 큐에 11을 입력
	add_queue(&list1, 1, 22);
	add_queue(&list1, 1, 33);
	//queue 2에 입력
	add_queue(&list1, 2, 111); //2번 큐에 111을 입력
	add_queue(&list1, 2, 222);
	add_queue(&list1, 2, 333);
	
	display_data(&list1); // 전체 출력 (1,2,3) (11, 22,33) (111, 222, 333)이 출력된다. 
						   //그림 참조
	
	delete_queue(&list1, 0);//queue 0에서 삭제. queue 0 전체를 삭제하는 것이 아님 
	display_data(&list1);
}
