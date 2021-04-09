#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


// ����Ʈ �ʱ�ȭ  
void list_init(List *pList)
{
	// head�� dummy node ���
	pList->pHead = (Node*)malloc(sizeof(Node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead;  // ���ʿ��� tail �� head ����
	
	//pList->pHead = NULL;
	//pList->pTail = NULL;
	pList->numData = 0;

	//printf("����Ʈ �ʱ�ȭ\n");
}

// ������ �߰� : 
int list_add(List *pList, Data data)
{
	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	// tail �� ����Ű�� next �� ���ο� node �� ����
	pList->pTail->pNext = pNewNode;

	//if (pList->pHead == NULL)
	//{
	//	// ù node ���?
	//	pList->pHead = pNewNode;
	//}
	//else 
	//{
	//	// tail �� ���ο� node (�� node) ����Ű�� ��
	//	pList->pTail->pNext = pNewNode;
	//}
	
	pList->pTail = pNewNode;    // tail �̵�

	//printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;     // ���� ����
	return TRUE;
}


// ������ ��ȸ, ù��°��
void list_init_iter(List *pList)
{
	pList->pCurrent = pList->pHead;
}

// ������ ��ȸ : ������ �ֳ�?
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)   // '������' ���θ� üũ�Ѵ�.
		return FALSE;

	return TRUE;
}

// ������ ��ȸ, ������
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // �켱 current �̵�
	Data result = pList->pCurrent->data;
	return result;
}

// ������ ����
// 
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) 
		return FALSE;

	list_init_iter(pList);  // iteration ����
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) 
			break;
		i++;
	}

	pList->pCurrent->data = data;  // ������ ����

	//printf("%d ��° ������ ����\n", n);
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

	// n��°  ��ġ�� ã�ƾ� �ϴµ�
	// ���� ��ġ�� �˾ƾ� �Ѵ�.
	list_init_iter(pList);  // iteration ����
	int i = 0;
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		// 
		pPrev = pList->pCurrent;
		list_next(pList);
		if (i >= n)
			break;
		i++;
	}

	// �̹� ������ pCurrent �� �̵��ߴ�.
	// ���� �� �����ؾ� �Ѵ�.  ���� �ٲ�� �����ȴ�.

	Node *tmp = pPrev->pNext;  // ���� Ŀ��Ʈ

	// ������ �ſ� �ܼ� (�迭�� ����)
	pPrev->pNext = pList->pCurrent->pNext;

	// ���� tail �� ���� �����Ϳ��ٸ� tail���� �����ؾ� �Ѵ�
	if (tmp == pList->pTail)
		pList->pTail = pPrev;

	// Node ���� �Ҵ� ��.��.�� ����
	free(tmp);

	pList->numData--;  // ����Ʈ size ����
	//printf("%d ��° ������ ����\n", n);
	return TRUE;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
		return FALSE;

	list_init_iter(pList);  // iteration ����
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n)
			break;
		i++;
	}

	// �Ű������� �� �����
	*pData = pList->pCurrent->data;

	//printf("get %d ��° ������ %d\n", n, *pData);

	return TRUE;
}

// ����Ʈ �Ҹ�
// head���� ���� �Ҹ��̴�.
void list_destroy(List *pList)
{
	list_init_iter(pList);  // iteration ����
	int i = 0;
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);
		free(pPrev);
	}
	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	//printf("����Ʈ �Ҹ�\n");
}

// Ž��-------------------------------------
Node* list_search(List *pList, int data)
{
	//int d;
	//list_init_iter(pList);
	//while (list_hasNext(pList))
	//{
	//	d = list_next(pList);
	//	if (d == data)
	//		return pList->pCurrent;  // ã���� �ش� ��� ����
	//}

	pList->pCurrent = pList->pHead;
	while (pList->pCurrent->pNext != NULL)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		if (pList->pCurrent->data == data)
			return pList->pCurrent;   // ã���� �ش� ��� ����
	}

	return NULL;   // ������ NULL ����
}

