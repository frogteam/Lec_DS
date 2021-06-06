#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

#include "Heap.h"

//------------------------------------------------------------

// 노드 인덱스 계산 매크로 (성능 UP ★)
#define GET_PARENT_IDX(idx) ((idx) >> 1)   // idx / 2
#define GET_LEFT_IDX(idx) ((idx) << 1)		// idx * 2
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1)  // idx * 2 + 1   ★괄호주의★

// 비교함수 대신 매크로 (성능 UP ★)
#define COMP_ASC(d1, d2) ((d2) - (d1))  // 오름차순
#define COMP_DESC(d1, d2) ((d1) - (d2)) // 내림차순


// 우선순위가 높은 자식의 인덱스 값 반환
int getHighPriority(Heap *ph, int idx)
{
	if (GET_LEFT_IDX(idx) > ph->numData)  // 자식 노드가 없다면 0 리턴
		return 0;

	else if (GET_LEFT_IDX(idx) == ph->numData)  // 왼쪽 자식 노드가 마지막(유일한) 자식 노드라면
		return GET_LEFT_IDX(idx);

	else
	{
		// 우선순위 비교 함수 사용!
		//if (ph->comp(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
		if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
			return (GET_RIGHT_IDX(idx));   // 오른쪽이 우선순위 높다
		else
			return (GET_LEFT_IDX(idx));    // 왼쪽이 우선순위 높다.
	}
}

//------------------------

// 힙 초기화
//void heap_init(Heap * ph, fnPriorityComp pc)
//{
//	ph->numData = 0;  // 노드 개수
//	ph->comp = pc;  // 비교 함수
//}

// 힙 초기화
void heap_init(Heap *ph, int len)
{
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1));   // +1 개 만큼 필요  1-based 배열
	g_hp = ph;    // 힙 정렬에 필요
}

void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
	//ph->heapArr = NULL;
	//ph->numData = 0;
	//g_hp = NULL;
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
		//if(ph->comp(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)  // 부모보다 우선순위가 높다면
		
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)  // 부모보다 우선순위가 높다면
		{
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];   // 부모를 끌어 내리고
			idx = GET_PARENT_IDX(idx);   // 부모 index 로 idx 값 이동
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
	// 힙 정렬 구현은 간단.
	for (i = 0; i < n; i++)
		heap_insert(g_hp, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = heap_delete(g_hp);
}