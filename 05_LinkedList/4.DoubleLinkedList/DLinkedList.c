#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"


// ����Ʈ �ʱ�ȭ  
void list_init(List *pList)
{
	// ����� ���� ����Ʈ ����
	pList->pHead = NULL;
	pList->pTail = NULL; 
	pList->numData = 0;

	printf("����Ʈ �ʱ�ȭ\n");
}

// ������ �߰� (����)
int list_add(List *pList, Data data)
{
	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));   // prev �� next �� null �� ����
	pNewNode->data = data;


	// ó���̸� : <0
	if (pList->pHead == NULL)
	{
		pList->pHead = pNewNode;
	}
	else
	{
		// tail �� ����Ű�� next �� ���ο� node �� ����
		pList->pTail->pNext = pNewNode;
		if(pList->numData > 0)					// ù node �̸� prev �� NULL �� �ξ�� �Ѵ�.
			pNewNode->pPrev = pList->pTail;   // �� 
	}

	pList->pTail = pNewNode;

	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;
	return TRUE;
}


// ù��°�� ������ ��������
int list_init_iter(List *pList, Data *pData)
{
	if (pList->pHead == NULL)
		return FALSE;

	pList->pCurrent = pList->pHead;
	*pData = pList->pCurrent->data;
	return TRUE;
}

// ������ ������ ��������
int list_last(List *pList, Data *pData)
{
	if (pList->pTail == NULL)
		return FALSE;

	pList->pCurrent = pList->pTail;
	*pData = pList->pCurrent->data;
	return TRUE;
}


// ���� ������ ��������
int list_next(List *pList, Data *pData)
{
	if (pList->pCurrent == NULL || pList->pCurrent->pNext == NULL)   // '������' ���θ� üũ�Ѵ�.
		return FALSE;
	pList->pCurrent = pList->pCurrent->pNext;
	*pData = pList->pCurrent->data;
	return TRUE;
}
// ���� ������ ��������
int list_prev(List *pList, Data *pData)
{
	if (pList->pCurrent == NULL || pList->pCurrent->pPrev == NULL)   // '������' ���θ� üũ�Ѵ�.
		return FALSE;
	pList->pCurrent = pList->pCurrent->pPrev;
	*pData = pList->pCurrent->data;
	return TRUE;
}


// ������ ����
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) 
		return FALSE;

	int i = 0;  // ù��° ����
	pList->pCurrent = pList->pHead;
	while (i < n)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		i++;
	}

	pList->pCurrent->data = data;  // ������ ����

	printf("%d ��° ������ ����\n", n);
	return TRUE;
}


// ������ ����
int list_length(List *pList)
{
	return pList->numData;
}


// ������ ����
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
		return FALSE;

	int i = 0;  // ù��° ����
	pList->pCurrent = pList->pHead;
	while (i < n)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		i++;
	}

	// �̹� ������ pCurrent �� �̵��ߴ�.
	// ���� �� �����ؾ� �Ѵ�.  ���� �ٲ�� �����ȴ�.

	// ������̴� ���� �ֱ⸸ �ϸ� �ȴ�.
	if (pList->pCurrent->pPrev != NULL)
	{
		pList->pCurrent->pPrev->pNext = pList->pCurrent->pNext;
	}
	if (pList->pCurrent->pNext != NULL)
	{
		pList->pCurrent->pNext->pPrev = pList->pCurrent->pPrev;
	}

	// head �� tail ������ �ʿ��� ��� (��, �� �հ� �� ���� ���)
	if (pList->pCurrent == pList->pHead)
	{
		pList->pHead = pList->pCurrent->pNext;
	}
	if (pList->pCurrent == pList->pTail)
	{
		pList->pTail = pList->pCurrent->pPrev;
	}


	// Node ���� �Ҵ� ��.��.�� ����
	free(pList->pCurrent);

	pList->numData--;  // ����Ʈ size ����
	printf("%d ��° ������ ����\n", n);
	return TRUE;
}


// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
		return FALSE;

	int i = 0;  // ù��° ����
	pList->pCurrent = pList->pHead;
	while (i < n)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		i++;
	}


	// �Ű������� �� �����
	*pData = pList->pCurrent->data;
	printf("get %d ��° ������ %d\n", n, *pData);

	return TRUE;
}



// ����Ʈ �Ҹ�
// head���� ���� �Ҹ��̴�.
void list_destroy(List *pList)
{
	pList->pCurrent = pList->pHead;
	while (pList->pCurrent != NULL)
	{
		Node *tmp = pList->pCurrent;
		pList->pCurrent = pList->pCurrent->pNext;
		free(tmp);
	}

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("����Ʈ �Ҹ�\n");
}
