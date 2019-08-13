#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"

void queue_init(Queue * pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

int queue_is_empty(Queue * pq)
{
	if(pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

int queue_enq(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->data = data;

	// 다 비어 있을때와 그렇지 않을때 구분 필요
	if(queue_is_empty(pq))   
	{
		pq->pFront = newNode;
		pq->pRear = newNode;
	}
	else
	{
		pq->pRear->pNext = newNode;
		pq->pRear = newNode;
	}

	return SUCCESS;
}

int queue_deq(Queue * pq, Data *pData)
{
	Node * delNode;

	if(queue_is_empty(pq))
	{
		printf("Queue Memory Error!");
		return FAIL;
	}

	if(pData != NULL)
		*pData = pq->pFront->data;
	delNode = pq->pFront;
	pq->pFront = pq->pFront->pNext;

	free(delNode);

	return SUCCESS;
}

int queue_peek(Queue *pq, Data *pData)
{
	if(queue_is_empty(pq))
	{
		printf("Queue Memory Error!");
		return FAIL;
	}

	if(pData != NULL)
		*pData =  pq->pFront->data;
	return SUCCESS;
}

void queue_destroy(Queue *pq)
{
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}