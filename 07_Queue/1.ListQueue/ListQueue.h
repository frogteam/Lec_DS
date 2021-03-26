#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define SUCCESS	1
#define FAIL	0

/* 큐의 ADT */

/* 큐 의 데이터 */
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * pNext;
} Node;

typedef struct _lQueue
{
	Node * pFront;
	Node * pRear;
} LQueue;
typedef LQueue Queue;

/* 큐 의 동작 */
void queue_init(Queue *pq);   // 큐 초기화
void queue_destroy(Queue *pq);   //큐 제거

int queue_is_empty(Queue *pq);    // 큐 비어있는지?

int queue_enq(Queue *pq, Data data);    // enqueue 데이터 추가
int queue_deq(Queue *pq, Data *pData);  // dequeue 데이터 꺼내기
int queue_peek(Queue *pq, Data *pData); // peek  데이터 들여다 보기

#endif