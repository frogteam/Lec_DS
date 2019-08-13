#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListStruct.h"
#pragma warning(disable:4996)


// ����Ʈ �ʱ�ȭ  
void list_init(List *pList)
{
	// head�� dummy node ���
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));   // ��� �ʱ�ȭ, �翬�� pHead�� pNext �� NULLL �� �ȴ�.

	pList->pTail = pList->pHead;  // ���ʿ��� tail �� head ����
	
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
	memcpy(pNewNode->pData, pData, sizeof(Data)); // �����ͺ���

	// tail �� ����Ű�� next �� ���ο� node �� ����
	pList->pTail->pNext = pNewNode;
	pList->pTail = pNewNode;

	printf("[%d] ��° ������ %s �߰�\n", pList->numData, pData->szName);
	(pList->numData)++;
	return SUCCESS;
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
		return FAIL;

	return SUCCESS;
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
	{
		printf("��������: %d ��° �����Ͱ� �����ϴ�\n", n);
		return FAIL;
	}

	// �ϴ� ��������� �ּ��� �����Ͱ� 1�� �̻��� �ִٴ� �Ŵ�.

	pList->pCurrent = pList->pHead->pNext;

	int i;
	for (i = 0; i < n; i++)
		pList->pCurrent = pList->pCurrent->pNext;

	// ������ ����
	pList->pCurrent->pData->age = pData->age;
	pList->pCurrent->pData->grade = pData->grade;
	strcpy(pList->pCurrent->pData->szName, pData->szName);  // ���ڿ� ����

	printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}

// ������ ����
int list_length(List *pList)
{
	return pList->numData;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("%d ��° �����Ͱ� �����ϴ�\n", n);
		return FAIL;
	}

	// �ϴ� ������� �����Ͱ� 1�� �̻� �ִٴ� ���

	pList->pCurrent = pList->pHead->pNext;

	int i;
	for (i = 0; i < n; i++)
		pList->pCurrent = pList->pCurrent->pNext;

	// �Ű������� �� �����
	pData->age = pList->pCurrent->pData->age;
	pData->grade = pList->pCurrent->pData->grade;
	strcpy(pData->szName, pList->pCurrent->pData->szName);

	return SUCCESS;
}

// ������ ����
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
	{
		printf("��������: %d ��° �����ʹ� �����ϴ�\n", n);
		return FAIL;
	}

	// �ϴ� ��������� �ּ��� �����Ͱ� 1�� �̻��� �ִٴ� �Ŵ�.

	// n��°  ��ġ�� ã�ƾ� �ϴµ�
	// ���� ��ġ�� �˾ƾ� �Ѵ�.
	int i = 0;
	Node *pPrev = pList->pHead;
	pList->pCurrent = pList->pHead->pNext;   // <-- �ּ��� 1���� �����ϱ�!   <-- �ϴ� #0��° �����ʹ�
	
	for (i = 0; i < n; i++)  // <-- #1��° ���� ~ n��°���� ã�ư���
	{
		pPrev = pList->pCurrent;					 // prev �� current �� ���� �����δ�.
		pList->pCurrent = pList->pCurrent->pNext;
	}

	// ������ �ſ� �ܼ� (�迭�� ����)
	pPrev->pNext = pList->pCurrent->pNext;

	// ���� tail �� ���� �����Ϳ��ٸ� tail���� �����ؾ� �Ѵ�
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;

	// Node ���� �Ҵ� ��.��.�� ����
	free(pList->pCurrent->pData);   // �� ������ �� ����!
	free(pList->pCurrent);     // Node ����

	pList->numData--;  // ����Ʈ size ����
	printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}



// ����Ʈ �Ҹ�
// head���� ���� �Ҹ��̴�.
void list_destroy(List *pList)
{
	int cnt = 0;  // ������ node ����

	//pList->pCurrent = pList->pHead->pNext;
	//
	//while(pList->pCurrent != NULL)
	//{
	//	Node *pTmp = pList->pCurrent;  // ������ ���
	//	pList->pCurrent = pList->pCurrent->pNext;  // ����� ���� current �̵�

	//	free(pTmp->pData);   // ������ ����
	//	free(pTmp);          // ��� ����
	//	cnt++;
	//}

	int i;
	int num = pList->numData;
	for (i = 0; i < num; i++)
	{
		list_remove(pList, 0);
		cnt++;
	}

	// dummy node ����
	free(pList->pHead);   // dummy ���� ������ ������ �����ʹ� �Ű澲�� �ʾƵ� �ȴ�.

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("����Ʈ ���� %d ���� node ����\n", cnt);
}

