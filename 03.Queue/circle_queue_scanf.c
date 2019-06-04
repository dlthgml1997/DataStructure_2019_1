
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}


// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front,q->rear);
	int i = q->front;
	while (!is_empty(q)) {
		i = (i + 1) % MAX_QUEUE_SIZE;
		printf("%d |", q->data[i]);
		if (i == q->rear)
			break;
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front) % MAX_QUEUE_SIZE];
}

int main(void)
{
	QueueType queue;
	element a;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue))
	{
		printf("������ �Է��ϼ���: ");
		scanf("%d", &a);
		enqueue(&queue, a);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n");
	printf("--������ ���� �ܰ�--\n");
		/*
		while (!is_empty(&queue))
		{
			a = dequeue(&queue);
			printf("������ ����: %d \n", element);
		}
		*/

		a = dequeue(&queue);
	printf("������ ����: %d \n", a);
	queue_print(&queue);
	a = dequeue(&queue);
	printf("������ ����: %d \n", a);
	queue_print(&queue);
	printf("������ �Է�\n");
	enqueue(&queue, 100);
	queue_print(&queue);

	printf("������ �Է�\n");
	enqueue(&queue, 200);
	queue_print(&queue);
}

