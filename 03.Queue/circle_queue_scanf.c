
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}


// 공백 상태 검출 함수
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
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front) % MAX_QUEUE_SIZE];
}

int main(void)
{
	QueueType queue;
	element a;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하세요: ");
		scanf("%d", &a);
		enqueue(&queue, a);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n");
	printf("--데이터 삭제 단계--\n");
		/*
		while (!is_empty(&queue))
		{
			a = dequeue(&queue);
			printf("꺼내진 정수: %d \n", element);
		}
		*/

		a = dequeue(&queue);
	printf("꺼내진 정수: %d \n", a);
	queue_print(&queue);
	a = dequeue(&queue);
	printf("꺼내진 정수: %d \n", a);
	queue_print(&queue);
	printf("데이터 입력\n");
	enqueue(&queue, 100);
	queue_print(&queue);

	printf("데이터 입력\n");
	enqueue(&queue, 200);
	queue_print(&queue);
}

