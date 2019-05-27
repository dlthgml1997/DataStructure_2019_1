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


typedef struct LinkedListType {		// ť ADT ����
	ListNode* head;
	int length;
} LinkedListType;

void error(const char* message) //����
{
	printf("%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
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
	if (list->head == NULL) error("�޸� �Ҵ� �Ұ� \n");
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
	if (list->head == NULL) error("������ �Ұ��� \n");
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
	init(&list1); //list1�� head�� NULL, length�� 0�� �ǵ��� �ʱ�ȭ
	int line;
	printf("how many lines?\n"); //�� ���� ť�� �ʿ��Ѱ�?
	scanf_s("%d", &line);
	init_queue(&list1, line); //line�� 3�̶�� list1�� head�� ����Ű�� ���Ḯ��Ʈ����
	   //��尡 �� �� ������ ������ ���� �ϳ��� ť�� ���� head�� tail�� �����ͷ� ��          
	   //�´�.  �� ����� head�� tail�� NULL�� �ʱ�ȭ �Ѵ�.

	   //���� ���� �� �� ���� ���� ó������ ť�� ������ ���� ���� �����Ͻÿ�.

	printf("length=%d\n", list1.length); //����� ������ �´��� ��� ����
	

   //line�� 3�̶�� �ϸ� 
//queue 0�� �Է�
	add_queue(&list1, 0, 1); //0�� ť�� 1�� �Է�
	add_queue(&list1, 0, 2);
	add_queue(&list1, 0, 3);
	//queue 1�� �Է�
	add_queue(&list1, 1, 11); //1�� ť�� 11�� �Է�
	add_queue(&list1, 1, 22);
	add_queue(&list1, 1, 33);
	//queue 2�� �Է�
	add_queue(&list1, 2, 111); //2�� ť�� 111�� �Է�
	add_queue(&list1, 2, 222);
	add_queue(&list1, 2, 333);
	
	display_data(&list1); // ��ü ��� (1,2,3) (11, 22,33) (111, 222, 333)�� ��µȴ�. 
						   //�׸� ����
	
	delete_queue(&list1, 0);//queue 0���� ����. queue 0 ��ü�� �����ϴ� ���� �ƴ� 
	display_data(&list1);
}
