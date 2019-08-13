#include "SimpleHeap.h"

//------------------------------------------------------------
// 부모노드 인덱스
int getParentIdx(int idx)
{
	return idx / 2;
}

// left 자식노드 인덱스
int getLeftIdx(int idx)
{
	return idx * 2;
}

// right 자식 노드 인덱스
int getRightIdx(int idx)
{
	return getLeftIdx(idx) + 1;
}

// 우선순위가 높은 자식의 인덱스 값 반환
int getHighPriority(Heap * ph, int idx)
{
	if (getLeftIdx(idx) > ph->numData)    // 자식 노드가 없다면
		return 0;

	else if (getLeftIdx(idx) == ph->numData)    // 왼쪽 자식 노드가 마지막(유일한) 자식 노드라면
		return getLeftIdx(idx);

	else   // 왼쪽 자식 노드와 오른쪽 자식 노드의 우선순위를 비교
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
	HData retData = (ph->heapArr[1]).data;    // 삭제할 데이터 임시 저장
	HeapElem lastElem = ph->heapArr[ph->numData];

	int parentIdx = 1;    // 루트 노드의 Index
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