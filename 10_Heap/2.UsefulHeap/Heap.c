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
	return idx * 2 + 1;
}

// idx �� �ڽĵ� �� �켱 ������ ���� �ڽ��� index �� ���� --> delete �� ���
int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0 ����
	if (getLeftIdx(idx) > ph->numData) return 0;

	// ���� �ڽ� ��尡 ������(������) �ڽ� �����
	if (getLeftIdx(idx) == ph->numData) return getLeftIdx(idx);

		//	if(ph->heapArr[GetLChildIDX(idx)].pr 
		//				> ph->heapArr[GetRChildIDX(idx)].pr)

	// �ڽ��� �� �ִ� ��� �켱���� ���Լ� ���!
	if (ph->comp(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0)
		return getRightIdx(idx);   // Right�� �켱���� ����
	else
		return getLeftIdx(idx);  // Left�� �켱������ ���ų� ����
}

//------------------------

// �� �ʱ�ȭ
void heap_init(Heap * ph, fnPriorityComp pc)
{
	ph->numData = 0;  // ������(���) ����
	ph->comp = pc;  // �� �Լ�
}

// ���� ����ֳ�?
int heap_is_empty(Heap * ph)
{
	if (ph->numData == 0) return SUCCESS;

	return FAIL;
}

// ���� ������ �߰�
void heap_insert(Heap * ph, HData data)
{
	// ���� INSERT �Ǵ� �����ʹ� �� ������ ����
	int idx = ph->numData + 1;  // �迭 �ε����� '1' ���� �����Ѵ�

	// �Ʒ� while �� �����ϸ鼭 ���� insert �� data �� ��ġ�� idx �� ����
	while(idx != 1) // root (�ֻ���) �� �����Ҷ�����.
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0)  // �θ𺸴� �켱������ ���ٸ�
		{
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];   // �θ� ���� ������ -> idx
			idx = getParentIdx(idx);   // idx -> �θ� index �� �̵�
		}
		else
		{
			// �θ𺸴� �켱������ ���ų� �۴ٸ�,.. ���⼭ ����
			break;
		}
	}
	
	ph->heapArr[idx] = data;   // idx�� ���� �װ��� ���� insert ��  data ���� (����)
	ph->numData++;   // ������ ���� +1 ����
}

// ������ ���� (root ����) �Ͽ� ����
HData heap_delete(Heap * ph)
{
	HData rootData = ph->heapArr[1];  // �ε��� 1���� ��Ʈ ���� . �̸� �����ϰ� �����Ѵ�.

	// ������ ��尡 �ڸ����� ��ġ idx �� �����ؾ� �Ѵ�. 
	// idx�� �����ɶ����� ������ ����� data�� �����س��´�
	HData lastElem = ph->heapArr[ph->numData];  // numData ��°�� ������ ����.

	int idx = 1;  // ������ ��尡 �ϴ� root �� �ڸ��� ������
	int childIdx;

	// �ϴ�, �ڽĳ���� �켱���� ������ ����
	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� while �� ����
	// �Ʒ� while ���� �ᱹ idx ���� �����ϱ� ����.
	while(childIdx = getHighPriority(ph, idx))   
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)

		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��.
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// �ڽ��� �켱������ �� ũ�ٸ�,  �� �ڽ��� �θ��� �ڸ��� ��ü
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// ���� �񱳸� ���� ������ ��� idx�� ������ �ڽ���ġ�� ������
		idx = childIdx;  
	}

	// while �� �� ���� �� �ڸ�(idx)��, ������ ���(lastElem)�� ��ġ�� ���̴�
	ph->heapArr[idx] = lastElem;
	ph->numData--;   // ������ ���� -1 ����
	return rootData;   // ���ʿ� ������ ���Ҵ� root data ����
}