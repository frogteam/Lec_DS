#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

int QIsEmpty(Queue * pq)
{
	if(pq->pFront == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->data = data;

	if(QIsEmpty(pq))
	{
		pq->pFront = newNode;
		pq->pRear = newNode;
	}
	else
	{
		pq->pRear->pNext = newNode;
		pq->pRear = newNode;
	}
}

Data Dequeue(Queue * pq)
{
	Node * delNode;
	Data retData;

	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->pFront;
	retData = delNode->data;
	pq->pFront = pq->pFront->pNext;

	free(delNode);
	return retData;
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->pFront->data;
}