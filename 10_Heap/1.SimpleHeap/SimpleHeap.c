#include "SimpleHeap.h"

//------------------------------------------------------------
// �θ��� �ε���
int getParentIdx(int idx)
{
	return idx / 2;
}

// left �ڽĳ�� �ε���
int getLeftIdx(int idx)
{
	return idx * 2;
}

// right �ڽ� ��� �ε���
int getRightIdx(int idx)
{
	return getLeftIdx(idx) + 1;
}

// �켱������ ���� �ڽ��� �ε��� �� ��ȯ
int getHighPriority(Heap * ph, int idx)
{
	if (getLeftIdx(idx) > ph->numData)    // �ڽ� ��尡 ���ٸ�
		return 0;

	else if (getLeftIdx(idx) == ph->numData)    // ���� �ڽ� ��尡 ������(������) �ڽ� �����
		return getLeftIdx(idx);

	else   // ���� �ڽ� ���� ������ �ڽ� ����� �켱������ ��
	{
		if (ph->heapArr[getLeftIdx(idx)].pr
						> ph->heapArr[getRightIdx(idx)].pr)
			return getRightIdx(idx);
		else
			return getLeftIdx(idx);
	}
}

//---------------------------
void heap_init(Heap * ph)
{
	ph->numData = 0;
}

int heap_is_empty(Heap * ph)
{
	if(ph->numData == 0)
		return SUCCESS;
	else
		return FAIL;
}

void heap_insert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numData+1;
	HeapElem nelem = {pr, data}; 

	while(idx != 1)
	{
		if(pr < (ph->heapArr[getParentIdx(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];
			idx = getParentIdx(idx);
		}
		else
			break;
	}
	
	ph->heapArr[idx] = nelem;
	ph->numData += 1;
}

HData heap_delete(Heap * ph)
{
	HData retData = (ph->heapArr[1]).data;    // ������ ������ �ӽ� ����
	HeapElem lastElem = ph->heapArr[ph->numData];

	int parentIdx = 1;    // ��Ʈ ����� Index
	int childIdx;

	while(childIdx = getHighPriority(ph, parentIdx))
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numData -= 1;
	return retData;
}