#include <stdio.h>
#include <string.h>   // memset()
#include "ArrayList.h"

/* �Ű����� ��ȿ�� ������ ���� */

// ����Ʈ �ʱ�ȭ
void list_init(List* pList)
{
	pList->numData = 0;
	pList->curPosition = -1;   // iterating �� ����
	memset(pList->arr, 0, sizeof(pList->arr));
	printf("����Ʈ �ʱ�ȭ\n");
}

// ����Ʈ ����
void list_destroy(List* pList)
{
	pList->numData = 0;
	printf("����Ʈ ����\n");
}

int list_add(List* pList, Data data)
{
	if(pList->numData >= LIST_INC_LEN)
	{
		printf("������ �߰� �Ұ�\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data;

	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;
	return SUCCESS;
}

// ������ ��ȸ, ù��°��
void list_init_iter(List *pList)
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
		return SUCCESS;

	return FAIL;
}

// ������ ����
// 
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FAIL;
	
	printf("%d ��° ������ ���� %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;
	return SUCCESS;
}

// ������ ����
int list_length(List *pList)
{
	return pList->numData;  // ������ �迭�̴ϱ� numData ������
}

// ������ ����
int list_remove(List *pList, int n)
{
	// �迭�̴ϱ� �߰� �����ϸ� ���� �͵� ��ܾ� �Ѵ�.
	if (n >= pList->numData) return FAIL;

	int i;
	for (i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numData--;  // ����Ʈ size ����

	printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	*pData = pList->arr[n];  // ������ ��,  �����ͷ� ����

	return SUCCESS;
}
