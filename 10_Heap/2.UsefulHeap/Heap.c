#include "Heap.h"

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
int getHighPriority(Heap *ph, int idx)
{
	if (getLeftIdx(idx) > ph->numData)  // �ڽ� ��尡 ���ٸ� 0 ����
		return 0;

	else if (getLeftIdx(idx) == ph->numData)  // ���� �ڽ� ��尡 ������(������) �ڽ� �����
		return getLeftIdx(idx);

	else
	{
		//	if(ph->heapArr[GetLChildIDX(idx)].pr 
		//				> ph->heapArr[GetRChildIDX(idx)].pr)

		// �켱���� �� �Լ� ���!
		if (ph->comp(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0)
			return getRightIdx(idx);   // �������� �켱���� ����
		else
			return getLeftIdx(idx);    // ������ �켱���� ����.
	}
}

//------------------------

// �� �ʱ�ȭ
void heap_init(Heap * ph, fnPriorityComp pc)
{
	ph->numData = 0;  // ��� ����
	ph->comp = pc;  // �� �Լ�
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
		if(ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0)  // �θ𺸴� �켱������ ���ٸ�
		{
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];   // �θ� ���� ������
			idx = getParentIdx(idx);   // �θ� index �� idx �� �̵�
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
	HData retData = ph->heapArr[1];  // �ε��� 1���� ��Ʈ ���� . �̸� �����ϰ� �����Ѵ�.
	HData lastElem = ph->heapArr[ph->numData];  // numData ��°�� ������ ����.

	int parentIdx = 1;
	int childIdx;

	// �ϴ�, �ڽĳ���� �켱���� ������ ����
	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� while �� ����
	while(childIdx = getHighPriority(ph, parentIdx))   
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)

		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��.
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// �ڽ��� �켱������ �� ũ�ٸ�,  �� �ڽ��� �θ��� �ڸ��� ��ü
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;  // ���� �񱳸� ���� index�� ������ �ڽ���ġ�� ������
	}

	// while�� �� ���� �� �ڸ���, ������ ��尡 ��ġ�� ���̴�.
	ph->heapArr[parentIdx] = lastElem;
	ph->numData -= 1;
	return retData;  // ���ʿ� �����س��� root ����
}