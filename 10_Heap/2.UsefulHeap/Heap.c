#include "Heap.h"

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
	return idx * 2 + 1;
}

// idx 의 자식들 중 우선 순위가 높은 자식의 index 값 리턴 --> delete 에 사용
int getHighPriority(Heap *ph, int idx)
{
	// 자식노드가 없다면 0 리턴
	if (getLeftIdx(idx) > ph->numData) return 0;

	// 왼쪽 자식 노드가 유일한(마지막) 자식 노드라면
	if (getLeftIdx(idx) == ph->numData) return getLeftIdx(idx);

		//	if(ph->heapArr[GetLChildIDX(idx)].pr 
		//				> ph->heapArr[GetRChildIDX(idx)].pr)

	// 자식이 둘 있는 경우 우선순위 비교함수 사용!
	if (ph->comp(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0)
		return getRightIdx(idx);   // Right가 우선순위 높다
	else
		return getLeftIdx(idx);  // Left가 우선순위가 높거나 같다
}

//------------------------

// 힙 초기화
void heap_init(Heap * ph, fnPriorityComp pc)
{
	ph->numData = 0;  // 데이터(노드) 개수
	ph->comp = pc;  // 비교 함수
}

// 힙이 비어있나?
int heap_is_empty(Heap * ph)
{
	if (ph->numData == 0) return SUCCESS;

	return FAIL;
}

// 힙에 데이터 추가
void heap_insert(Heap * ph, HData data)
{
	// 새로 INSERT 되는 데이터는 맨 끝에서 시작
	int idx = ph->numData + 1;  // 배열 인덱스는 '1' 부터 시작한다

	// 아래 while 문 수행하면서 새로 insert 된 data 가 위치할 idx 를 결정
	while(idx != 1) // root (최상위) 에 도달할때까지.
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0)  // 부모보다 우선순위가 높다면
		{
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];   // 부모를 끌어 내리고 -> idx
			idx = getParentIdx(idx);   // idx -> 부모 index 로 이동
		}
		else
		{
			// 부모보다 우선순위가 같거나 작다면,.. 여기서 멈춤
			break;
		}
	}
	
	ph->heapArr[idx] = data;   // idx가 멈춘 그곳에 새로 insert 된  data 쓰기 (정착)
	ph->numData++;   // 데이터 개수 +1 증가
}

// 힙에서 삭제 (root 삭제) 하여 리턴
HData heap_delete(Heap * ph)
{
	HData rootData = ph->heapArr[1];  // 인덱스 1번이 루트 노드다 . 이를 리턴하고 제거한다.

	// 마지막 노드가 자리잡을 위치 idx 를 결정해야 한다. 
	// idx가 결정될때까지 마지막 노드의 data를 보관해놓는다
	HData lastElem = ph->heapArr[ph->numData];  // numData 번째가 마지막 노드다.

	int idx = 1;  // 마지막 노드가 일단 root 의 자리에 오른다
	int childIdx;

	// 일단, 자식노드중 우선순위 높은거 선택
	// 만약 자식이 하나도 없다면 0이 리턴되어 while 문 종료
	// 아래 while 문은 결국 idx 값을 결정하기 위함.
	while(childIdx = getHighPriority(ph, idx))   
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)

		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교.
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// 자식의 우선순위가 더 크다면,  그 자식이 부모의 자리로 교체
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// 다음 비교를 위해 마지막 노드 idx를 좀전의 자식위치로 내리기
		idx = childIdx;  
	}

	// while 이 다 끝난 그 자리(idx)가, 마지막 노드(lastElem)가 위치할 곳이다
	ph->heapArr[idx] = lastElem;
	ph->numData--;   // 데이터 개수 -1 감소
	return rootData;   // 최초에 저장해 놓았던 root data 리턴
}