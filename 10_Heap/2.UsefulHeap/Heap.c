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
	return getLeftIdx(idx) + 1;
}

// 우선순위가 높은 자식의 인덱스 값 반환
int getHighPriority(Heap *ph, int idx)
{
	if (getLeftIdx(idx) > ph->numData)  // 자식 노드가 없다면 0 리턴
		return 0;

	else if (getLeftIdx(idx) == ph->numData)  // 왼쪽 자식 노드가 마지막(유일한) 자식 노드라면
		return getLeftIdx(idx);

	else
	{
		//	if(ph->heapArr[GetLChildIDX(idx)].pr 
		//				> ph->heapArr[GetRChildIDX(idx)].pr)

		// 우선순위 비교 함수 사용!
		if (ph->comp(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0)
			return getRightIdx(idx);   // 오른쪽이 우선순위 높다
		else
			return getLeftIdx(idx);    // 왼쪽이 우선순위 높다.
	}
}

//------------------------

// 힙 초기화
void heap_init(Heap * ph, fnPriorityComp pc)
{
	ph->numData = 0;  // 노드 개수
	ph->comp = pc;  // 비교 함수
}

// 힙이 비어있나?
int heap_is_empty(Heap * ph)
{
	if(ph->numData == 0)
		return SUCCESS;
	else
		return FAIL;
}

// 힙에 데이터 추가
void heap_insert(Heap * ph, HData data)
{
	int idx = ph->numData + 1;  // 배열 인덱스는 '1' 부터 시작한다

	while(idx != 1)
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0)  // 부모보다 우선순위가 높다면
		{
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];   // 부모를 끌어 내리고
			idx = getParentIdx(idx);   // 부모 index 로 idx 값 이동
		}
		else
		{
			// 부모보다 우선순위가 같거나 작다면,.. 여기서 멈춤
			break;
		}
	}
	
	ph->heapArr[idx] = data;   // 멈춘 그곳에 새로 들어온 데이터 쓰기 (정착)
	ph->numData += 1;  // 데이터 개수 추가
}

// 힙에서 root 삭제 (리턴)
HData heap_delete(Heap * ph)
{
	HData retData = ph->heapArr[1];  // 인덱스 1번이 루트 노드다 . 이를 리턴하고 제거한다.
	HData lastElem = ph->heapArr[ph->numData];  // numData 번째가 마지막 노드다.

	int parentIdx = 1;
	int childIdx;

	// 일단, 자식노드중 우선순위 높은거 선택
	// 만약 자식이 하나도 없다면 0이 리턴되어 while 문 종료
	while(childIdx = getHighPriority(ph, parentIdx))   
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)

		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교.
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// 자식의 우선순위가 더 크다면,  그 자식이 부모의 자리로 교체
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;  // 다음 비교를 위헤 index를 좀전의 자식위치로 내리기
	}

	// while이 다 끝난 그 자리가, 마지막 노드가 위치할 곳이다.
	ph->heapArr[parentIdx] = lastElem;
	ph->numData -= 1;
	return retData;  // 최초에 저장해놓은 root 리턴
}