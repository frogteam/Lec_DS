#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

#include "Heap.h"

//------------------------------------------------------------

// ��� �ε��� ��� ��ũ�� (���� UP ��)
#define GET_PARENT_IDX(idx) ((idx) >> 1)   // idx / 2
#define GET_LEFT_IDX(idx) ((idx) << 1)		// idx * 2
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1)  // idx * 2 + 1   �ڰ�ȣ���ǡ�

// ���Լ� ��� ��ũ�� (���� UP ��)
#define COMP_ASC(d1, d2) ((d2) - (d1))  // ��������
#define COMP_DESC(d1, d2) ((d1) - (d2)) // ��������


// �켱������ ���� �ڽ��� �ε��� �� ��ȯ
int getHighPriority(Heap *ph, int idx)
{
	if (GET_LEFT_IDX(idx) > ph->numData)  // �ڽ� ��尡 ���ٸ� 0 ����
		return 0;

	else if (GET_LEFT_IDX(idx) == ph->numData)  // ���� �ڽ� ��尡 ������(������) �ڽ� �����
		return GET_LEFT_IDX(idx);

	else
	{
		// �켱���� �� �Լ� ���!
		//if (ph->comp(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
		if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
			return (GET_RIGHT_IDX(idx));   // �������� �켱���� ����
		else
			return (GET_LEFT_IDX(idx));    // ������ �켱���� ����.
	}
}

//------------------------

// �� �ʱ�ȭ
//void heap_init(Heap * ph, fnPriorityComp pc)
//{
//	ph->numData = 0;  // ��� ����
//	ph->comp = pc;  // �� �Լ�
//}

// �� �ʱ�ȭ
void heap_init(Heap *ph, int len)
{
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1));   // +1 �� ��ŭ �ʿ�  1-based �迭
	g_hp = ph;    // �� ���Ŀ� �ʿ�
}

void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
	//ph->heapArr = NULL;
	//ph->numData = 0;
	//g_hp = NULL;
}

// ���� ����ֳ�?
int heap_is_empty(Heap * ph)
{
	if(ph->numData == 0)
		return SUCCESS;
	else
		return FAIL;
}

// ���� ������ �߰�
void heap_insert(Heap * ph, HData data)
{
	int idx = ph->numData + 1;  // �迭 �ε����� '1' ���� �����Ѵ�

	while(idx != 1)
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		//if(ph->comp(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)  // �θ𺸴� �켱������ ���ٸ�
		
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)  // �θ𺸴� �켱������ ���ٸ�
		{
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];   // �θ� ���� ������
			idx = GET_PARENT_IDX(idx);   // �θ� index �� idx �� �̵�
		}
		else
		{
			// �θ𺸴� �켱������ ���ų� �۴ٸ�,.. ���⼭ ����
			break;
		}
	}
	
	ph->heapArr[idx] = data;   // ���� �װ��� ���� ���� ������ ���� (����)
	ph->numData += 1;  // ������ ���� �߰�
}

// ������ root ���� (����)
HData heap_delete(Heap * ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numData];

	int parentIdx = 1;
	int childIdx;

	while(childIdx = getHighPriority(ph, parentIdx))   
	{
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numData -= 1;
	return retData;
}


void HeapSort(int arr[], int n)
{
	int i;
	// �� ���� ������ ����.
	for (i = 0; i < n; i++)
		heap_insert(g_hp, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = heap_delete(g_hp);
}