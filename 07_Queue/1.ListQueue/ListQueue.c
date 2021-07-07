#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"

void queue_init(Queue * pq)
{
	pq->pFront = NULL;
	pq->pBack = NULL;
}

int queue_is_empty(Queue * pq)
{
	if(pq->pFront == NULL)
		return SUCCESS;

	return FAIL;
}

int queue_enq(Queue * pq, Data data)
{
	// 새로운 노드 생성
	Node * pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = data;

	// 큐가 비어있을때와 그렇지 않을때 구분
	if(queue_is_empty(pq))   
	{
		pq->pFront = pNewNode;
		pq->pBack = pNewNode;
	}
	else
	{
		pq->pBack->pNext = pNewNode;
		pq->pBack = pNewNode;
	}

	return SUCCESS;
	// ※ LinkedList.c 의 list_add() 함수와 비교해보자
	//    dummy node 를 사용한것(LinkedList)와
	//    그렇지 않은것(ListBaseQueue)도 비교
	//   dummy node  를 사용하면 코드가 더욱 간결해진다. (분기가 적어진다)
}

int queue_deq(Queue * pq, Data *pData)
{
	if(queue_is_empty(pq))
	{
		printf("Queue EMPTY!");
		return FAIL;
	}

	 

	if(pData != NULL)
		*pData = pq->pFront->data; // front 데이터 추출

	Node * deleteNode = pq->pFront;  // 삭제할 노드 기억
	pq->pFront = pq->pFront->pNext; // front 는 다음 노드로 이동

	free(deleteNode);

	return SUCCESS;
}

int queue_peek(Queue *pq, Data *pData)
{
	if(queue_is_empty(pq))
	{
		printf("Queue EMPTY!");
		return FAIL;
	}

	if(pData != NULL)
		*pData =  pq->pFront->data;
	return SUCCESS;
}

void queue_destroy(Queue *pq)
{
	// 큐가 다 비어질때까지 dequeue
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}