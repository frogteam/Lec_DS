#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->pNext = plist->tail;

	plist->tail->pNext = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->pNext = newNode;

	newNode->pNext = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head->pNext == plist->tail)
		return FALSE;

	plist->cur = plist->head->pNext;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->pNext == plist->tail)
		return FALSE;

	plist->cur = plist->cur->pNext;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data remv = rpos->data;

	plist->cur->prev->pNext = plist->cur->pNext;
	plist->cur->pNext->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;    // cur의 위치를 재조정

	free(rpos);
	(plist->numOfData)--;
	return remv;
}

int LCount(List * plist)
{
	return plist->numOfData;
}