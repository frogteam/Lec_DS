#include <stdio.h>
#include <string.h>   // memset()
#include <stdlib.h>    // realloc
#include "ArrayListEx.h"

/* �Ű����� ��ȿ�� ������ ���� */

// ����Ʈ �ʱ�ȭ
void list_init(List* pList)
{
	// �ʱ� �迭 ũ�� ����
	pList->arr = (Data*)malloc(sizeof(Data) * LIST_INC_LEN);
	pList->maxLen = LIST_INC_LEN;  // ���� �迭 ũ�� (��������)

	pList->numData = 0;        
	pList->curPosition = -1;   // iterating �� ����
	memset(pList->arr, 0, sizeof(pList->arr));
	printf("����Ʈ �ʱ�ȭ\n");
}

// ����Ʈ �Ҹ�
void list_destroy(List* pList)
{
	free(pList->arr);
	printf("����Ʈ �Ҹ�\n");
}


int list_add(List* pList, Data data)
{
	if(pList->numData >= pList->maxLen)
	{
		int newSize = sizeof(Data) * (pList->maxLen + LIST_INC_LEN);
		// �����迭���� '������'��ŭ ������Ų ���迭 �Ҵ�
		Data* pNerArr = (Data*)malloc(newSize);
		// �����迭�� ���迭�� '����'
		memcpy(pNerArr, pList->arr, sizeof(Data) * (pList->maxLen));

		//pList->arr = realloc(pList->arr, newSize);

		free(pList->arr);  // �����Ҵ�� �迭�� �ݵ�� ����
		pList->arr = pNerArr;
		pList->maxLen += LIST_INC_LEN;  // ���� ������ �迭 
	}

	pList->arr[pList->numData] = data;

	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;
	return TRUE;
}

// ������ ��ȸ, ù��°��
void list_first(List *pList)
{
	pList->curPosition = -1;
}

// ������ ��ȸ, ������
Data list_next(List *pList)
{
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];
	
	return result ;
}

// ������ ��ȸ : ������ �ֳ�?
int list_hasNext(List *pList)
{
	if (pList->curPosition + 1 < pList->numData) 
		return TRUE;

	return FALSE;
}

// ������ ����
// 
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FALSE;
	
	pList->arr[n] = data;
	printf("%d ��° ������ ����\n", n);
	return TRUE;
}

// ������ ����
int list_size(List *pList)
{
	return pList->numData;  // ������ �迭�̴ϱ� numData ������
}

// ������ ����
int list_remove(List *pList, int n)
{
	// �迭�̴ϱ� �߰� �����ϸ� ���� �͵� ��ܾ� �Ѵ�.
	if (n >= pList->numData) return FALSE;

	int i;
	for (i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numData--;  // ����Ʈ size ����

	// �迭 ��ü ũ�� resizing
	if (pList->numData > 0 && pList->maxLen - pList->numData >= LIST_INC_LEN)
	{
		int newSize = sizeof(Data) * (pList->maxLen - LIST_INC_LEN);
		//Data *pNewArr = (Data*)malloc(newSize);
		pList->arr = (Data*)realloc(pList->arr, newSize);
		pList->maxLen -= LIST_INC_LEN;
	}

	printf("%d ��° ������ ����\n", n);
	return TRUE;
}
//
//int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�
