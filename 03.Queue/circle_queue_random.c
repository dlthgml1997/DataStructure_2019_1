#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* p)
{
	p->rear = p->front = 0;
}

int is_empty(QueueType* q)
{
	return (q->rear == q->front);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
	printf("Queue(front=%d,rear=%d) = ", q->front, q->rear);
	int i = q->front;
	while (!is_empty(q)) {
		i = (i + 1) % (MAX_QUEUE_SIZE);
		printf("%d|", q->data[i]);
		if (i == q->rear)
			break;
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.\n");
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main(void)
{
	QueueType queue;
	element data;

	init_queue(&queue);
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		if (rand() % 5 == 0)
		{
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);
		if (rand() % 10 == 0)
		{
			data = dequeue(&queue);
		}
		queue_print(&queue);
	}
	return 0;
}