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

	printf("����Ʈ �ʱ�ȭ\n");
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

	(pList->numData)++;     // ������ ���� ����
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
	if (pList->pCurrent->pNext == NULL)  // '�������' ���� ���θ� üũ�Ѵ�
		return FALSE;

	return TRUE;
}

// ������ ��ȸ, ������
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // �켱 current �ѹ� ������ �̵�
	Data result = pList->pCurrent->data;  // ������ ����
	return result;
}

// n��° ������ ����
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FALSE;

	// head���ͽ����ؼ� n��° ��� ã��,  iteration ���
	list_init_iter(pList);  // iteration ����
	int i = 0;  // ���� ���° ���?
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) break;  // n��° ��� ã��! 
		i++;
	}
	// �� while ���� ������ pCurrent �� n��° ��带 ����Ű�� �ֽ�

	printf("%d ��° ������ ���� %d  --> %d\n", n, pList->pCurrent->data, data);

	pList->pCurrent->data = data;  // ������ ����

	return TRUE;
}

// ������ ����
int list_length(List *pList)
{
	return pList->numData;
}

// n��° ������ ����
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
		return FALSE;

	// n��° ��� �����Ϸ���
	// n��° �� �ƴ϶� n-1 ��° ��� ������ �˾ƾ� �Ѵ�
	// ��. ���� ���(previous node) ���� �˾ƾ� �Ѵ�.
	list_init_iter(pList);  // iteration ����
	int i = 0;
	Node *pPrev = NULL;  // ���� ��带 ����ų ������
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent; // pCurrent �� �̵��ϱ� ���� pCurrent ���� ������� �� ����ؾ� �Ѵ�
		list_next(pList);    // pCurrent �̵�
		if (i >= n)	break;
		i++;
	}

	// �� while ���� ������ 
	// pCurrent (n��° ���), pPrev(n-1��° ���) �� ������.

	// ���� �� �����ؾ� �Ѵ�.  ���� �ٲ�� �����ȴ�.

	// ��������: �ſ� �ܼ� (�迭�� ����)
	pPrev->pNext = pList->pCurrent->pNext;

	// ���� tail �� ������ ��忴�ٸ� tail���� �����ؾ� �Ѵ�
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;  // tail �� ���� ���� �̵�

	// n��° ������ ���� �޸� �Ҵ� ����! ��!
	free(pList->pCurrent);

	pList->numData--;  // ����Ʈ ������ ���� -1 ����
	
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
		if (i >= n) break; // n ��° �߰�!
		i++;
	}
	// �� while���� ������ pCurrent ���� n��° node�� ����Ű�� �ִ�.

	// �Ű������� n��° ��� ������ �����
	*pData = pList->pCurrent->data;

	//printf("get %d ��° ������ %d\n", n, *pData);

	return TRUE;
}

// ����Ʈ �Ҹ�
// head���� ���� �Ҹ��̴�.
void list_destroy(List *pList)
{
	list_init_iter(pList);  // iteration ����
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);  // �ϴ� pCurrent ������� �̵�
		free(pPrev);  // ��� ����
	}
	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("����Ʈ �Ҹ�\n");
}

// ������ ����: n��° ��ġ�� ������ ����
// �ǵڿ� ����(�߰�) �ϴ� �͵� ���
int list_insert(List* pList, int n, Data data)
{
	if (n > pList->numData) return FALSE;  // >= �� �ƴ϶� > �̴�!


	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	
	if (pList->numData == 0)  // 1.ù��° �������� ���
	{
		pList->pHead->pNext = pNewNode;
		pList->pTail = pNewNode;
	} 
	else if (n == pList->numData)  // 2.�� ���� �߰���
	{
		pList->pTail->pNext = pNewNode; // add() �� ����
		pList->pTail = pNewNode;
	}
	else
	{
		// 3. n��° ��忡 �����Ϸ���
		// n-1��° ���, �������(previoud node) ���� �˾ƾ� �Ѵ�.
		list_init_iter(pList);  // iteration ����
		int i = 0;
		Node *pPrev = NULL;  // ���� ��带 ����ų ������
		while (list_hasNext(pList))
		{
			pPrev = pList->pCurrent; // pCurrent �� �̵��ϱ� ���� pCurrent ���� ������� �� ����ؾ� �Ѵ�
			list_next(pList);    // pCurrent �̵�
			if (i >= n)	break;
			i++;
		}

		// �� while ���� ������ 
		// pCurrent (n��° ���), pPrev(n-1��° ���) �� ������.

		// ���Ե��� ����
		pPrev->pNext = pNewNode;  // ���� ���� ���ο� ��带 ����Ű��
		pNewNode->pNext = pList->pCurrent;   // ���ο� ���� ������ n��° ��带 ����Ű�� �ȴ�
	}

	//printf("[%d] ��° ������ %d ����\n", n, data);
	
	(pList->numData)++;     // ������ ���� ����
	return TRUE;
}