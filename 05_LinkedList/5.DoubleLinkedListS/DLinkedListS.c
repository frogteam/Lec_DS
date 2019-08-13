#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedListS.h"
#pragma warning(disable:4996)

// ����Ʈ �ʱ�ȭ  
void list_init(List *pList)
{
	// head / tail �� dummy node ���
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));
	pList->pTail = (Node*)malloc(sizeof(Node));  // ��
	memset(pList->pTail, 0, sizeof(Node));  // ��

	pList->numData = 0;
	printf("����Ʈ �ʱ�ȭ\n");
}

// ������ �߰� (����)
int list_add(List *pList, Data *pData)
{
	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));   // prev �� next �� null �� ����
	
	pNewNode->pData = (Data*)malloc(sizeof(Data));
	memcpy(pNewNode->pData, pData, sizeof(Data)); // �����ͺ���

	// �� ������ ��尡 ������ �� �Ѱ��� ������ �����ؾ� �Ѵ�.
	if (pList->numData == 0)   // ������ ��尡 �ϳ��� ������
	{
		pList->pHead->pNext = pNewNode;  // ��
		pList->pTail->pPrev = pNewNode;  // ��
	}
	else  // ������ ��尡 �Ѱ��̻� ������
	{
		// tail �� ����Ű�� next �� ���ο� node �� ����
		pList->pTail->pPrev->pNext = pNewNode;    // �� ��   ������ ��� pTail->pPrev   �� pHead �� ����.
		pNewNode->pPrev = pList->pTail->pPrev;  // �� ��
		pList->pTail->pPrev = pNewNode;  // �� ��
	}

	printf("[%d] ��° ������ %s �߰�\n", pList->numData, pData->szName);
	(pList->numData)++;
	return SUCCESS;
}

// forward �������� �ʱ�ȭ
void list_init_forward(List *pList)  // ��
{
	pList->pCurrent = pList->pHead;
}

// ������ ��ȸ : ������ �ֳ�?
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)   // '���� ���' ���θ� üũ�Ѵ�.
		return FAIL;

	return SUCCESS;
}

// ������ ��ȸ, ������
Data *list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // �켱 current �̵�
	return pList->pCurrent->pData;
}

// �� backward iteration �ʱ�ȭ 
void list_init_backward(List *pList)
{
	pList->pCurrent = pList->pTail;
}
// �ڵ����� ��ȸ : ���� ��� �ֳ�?
int list_hasPrev(List *pList)
{
	if (pList->pCurrent->pPrev == NULL)   // '���� ���' ���θ� üũ�Ѵ�.
		return FAIL;

	return SUCCESS;
}

// �ڵ����� ��ȸ, ���� ��� ������
Data *list_prev(List *pList)
{
	pList->pCurrent = pList->pCurrent->pPrev;  // �켱 current �̵�
	return pList->pCurrent->pData;
}

// �ڡڡ�
// current �̵� :  doubly linked list �� ����
// next �� �ƴ϶� prev �� ���� �ֱ� ������  current �� �˸�
// ����, ���� ���� ���� ����  
// (�ܹ��� linkedlist ���� �ڵ忡�� prev �� ���� ������ ���� ���� �߾�� �߱� ������ current �� �ȴٰ� �ذ� �ȵǾ���)
int list_move_current(List* pList, int n)
{
	// n �� ���� ������ ������ �Ѱ����� ����
	int i;
	if (n <= pList->numData / 2)
	{	// head ���� ����
		pList->pCurrent = pList->pHead->pNext;
		for (i = 0; i < n; i++)
			pList->pCurrent = pList->pCurrent->pNext;
	}
	else
	{	// tail ���� ����
		pList->pCurrent = pList->pTail->pPrev;
		for (i = 0; i < pList->numData - n - 1; i++)    // ��� loop
			pList->pCurrent = pList->pCurrent->pPrev;
	}
	return SUCCESS;
}



// ������ ����
int list_set(List *pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("��������: %d ��° �����Ͱ� �����ϴ�\n", n);
		return FAIL;
	}

	// �ϴ� ��������� �ּ��� �����Ͱ� 1�� �̻��� �ִٴ� �Ŵ�.

	list_move_current(pList, n);  // �� current �̵� --> n��° ���

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

	// �ϴ� ��������� �ּ��� �����Ͱ� 1�� �̻��� �ִٴ� �Ŵ�.

	list_move_current(pList, n);  // �� current �̵� --> n��° ���

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

	list_move_current(pList, n);  // �� current �̵� --> n��° ���

	// �� ���߿��Ḯ��Ʈ �� current �� �˾Ƶ� '����' �� ���ϴ� 
	if(pList->pCurrent->pPrev != NULL)                           // ��ù��° �������� �ƴ� ���   
		pList->pCurrent->pPrev->pNext = pList->pCurrent->pNext;  // �� current �� prev �� next �� current �� next �� ���� 
	else 
		pList->pHead->pNext = pList->pCurrent->pNext;    // ù��° �������� ��� head �� ����

	if(pList->pCurrent->pNext != NULL)                           // �� ������ �������� �ƴ� ��� 
		pList->pCurrent->pNext->pPrev = pList->pCurrent->pPrev;  // �� current �� next �� prev �� current �� prev �� ����
	else
		pList->pTail->pPrev = pList->pCurrent->pPrev;   // ������ ��� ������ ��� tail �� ����


	// Node ���� �Ҵ� ��.��.�� ����
	free(pList->pCurrent->pData);   // ������ ����!
	free(pList->pCurrent);     // Node ����

	pList->numData--;  // ����Ʈ size ����
	printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}

// ����Ʈ �Ҹ�
void list_destroy(List *pList)
{
	pList->pCurrent = pList->pHead->pNext;

	int cnt = 0;  // ������ node ����
	while (pList->pCurrent != NULL)
	{
		Node *pTmp = pList->pCurrent;  // ������ ���
		pList->pCurrent = pList->pCurrent->pNext;  // ����� ���� current �̵�

		free(pTmp->pData);   // ������ ����
		free(pTmp);          // ��� ����
		cnt++;
	}

	// dummy node ����
	free(pList->pHead);   // dummy ���� ������ ������ �����ʹ� �Ű澲�� �ʾƵ� �ȴ�.
	free(pList->pTail);   // �ڡ�

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;

	printf("����Ʈ ���� %d ���� node ����\n", cnt);
}
