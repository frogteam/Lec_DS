#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OrdList.h"
#pragma warning(disable:4996)


// ����Ʈ �ʱ�ȭ  
void list_init(List *pList)
{
	// head�� dummy node ���
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));   // ��� �ʱ�ȭ
	
	pList->numData = 0;

	printf("����Ʈ �ʱ�ȭ\n");
}

// ������ �߰� : 
int list_add(List *pList, Data *pData)
{
	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->pData = (Data*)malloc(sizeof(Data));
	memset(pNewNode->pData, 0, sizeof(Data));

	// ������ ����
	pNewNode->pData->age = pData->age;
	pNewNode->pData->grade = pData->grade;
	strcpy(pNewNode->pData->szName, pData->szName);  // ���ڿ� ����

	
	// ���ĵǾ� ������ �߰�
	// �տ������� 
	int i = 0;
	Node *pPrev = pList->pHead;

	while (pPrev->pNext != NULL &&
		pList->fnComp(pData, pPrev->pNext->pData) != 0)
	{
		pPrev = pPrev->pNext;
		i++;
	}

	pNewNode->pNext = pPrev->pNext;
	pPrev->pNext = pNewNode;

	printf("[%d] ��° ������ %s �߰�\n", pList->numData, pData->szName);
	(pList->numData)++;
	return TRUE;
}


// ������ ��ȸ, ù��°��
void list_first(List *pList)
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
Data *list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // �켱 current �̵�
	return pList->pCurrent->pData;
}

// ������ ����
// 
int list_set(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) 
		return FALSE;

	list_first(pList);  // iteration ����
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) 
			break;
		i++;
	}

	// ������ ����
	pList->pCurrent->pData->age = pData->age;
	pList->pCurrent->pData->grade = pData->grade;
	strcpy(pList->pCurrent->pData->szName, pData->szName);  // ���ڿ� ����



	printf("%d ��° ������ ����\n", n);
	return TRUE;
}

// ������ ����
int list_size(List *pList)
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
	list_first(pList);  // iteration ����
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

	// Node ���� �Ҵ� ��.��.�� ����
	free(tmp->pData);   // �� ������ �� ����!
	free(tmp);

	pList->numData--;  // ����Ʈ size ����
	printf("%d ��° ������ ����\n", n);
	return TRUE;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
		return FALSE;

	list_first(pList);  // iteration ����
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n)
			break;
		i++;
	}

	// �Ű������� �� �����
	pData->age = pList->pCurrent->pData->age;
	pData->grade = pList->pCurrent->pData->grade;
	strcpy(pData->szName, pList->pCurrent->pData->szName);

	printf("get %d ��° ������ %s\n", n, pData->szName);

	return TRUE;
}

// ����Ʈ �Ҹ�
// head���� ���� �Ҹ��̴�.
void list_destroy(List *pList)
{
	list_first(pList);  // iteration ����
	int i = 0;
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);
		free(pPrev->pData);   // �� �����Ҵ�� ������ �� ���� 
		free(pPrev);
	}
	pList->pHead = NULL;
	pList->numData = 0;
	printf("����Ʈ �Ҹ�\n");
}