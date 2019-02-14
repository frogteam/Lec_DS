#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"


// 리스트 초기화  
void list_init(List *pList)
{
	// 양방향 연결 리스트 에선
	pList->pHead = NULL;
	pList->pTail = NULL; 
	pList->numData = 0;

	printf("리스트 초기화\n");
}

// 데이터 추가 (끝에)
int list_add(List *pList, Data data)
{
	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));   // prev 도 next 도 null 로 세팅
	pNewNode->data = data;


	// 처음이면 : <0
	if (pList->pHead == NULL)
	{
		pList->pHead = pNewNode;
	}
	else
	{
		// tail 이 가리키던 next 를 새로운 node 에 연결
		pList->pTail->pNext = pNewNode;
		if(pList->numData > 0)					// 첫 node 이면 prev 를 NULL 로 두어야 한다.
			pNewNode->pPrev = pList->pTail;   // ★ 
	}

	pList->pTail = pNewNode;

	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;
	return TRUE;
}


// 첫번째로 데이터 가져오기
int list_init_iter(List *pList, Data *pData)
{
	if (pList->pHead == NULL)
		return FALSE;

	pList->pCurrent = pList->pHead;
	*pData = pList->pCurrent->data;
	return TRUE;
}

// 마지막 데이터 가져오기
int list_last(List *pList, Data *pData)
{
	if (pList->pTail == NULL)
		return FALSE;

	pList->pCurrent = pList->pTail;
	*pData = pList->pCurrent->data;
	return TRUE;
}


// 다음 데이터 가져오기
int list_next(List *pList, Data *pData)
{
	if (pList->pCurrent == NULL || pList->pCurrent->pNext == NULL)   // '다음것' 여부를 체크한다.
		return FALSE;
	pList->pCurrent = pList->pCurrent->pNext;
	*pData = pList->pCurrent->data;
	return TRUE;
}
// 이전 데이터 가져오기
int list_prev(List *pList, Data *pData)
{
	if (pList->pCurrent == NULL || pList->pCurrent->pPrev == NULL)   // '이전것' 여부를 체크한다.
		return FALSE;
	pList->pCurrent = pList->pCurrent->pPrev;
	*pData = pList->pCurrent->data;
	return TRUE;
}


// 데이터 수정
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) 
		return FALSE;

	int i = 0;  // 첫번째 부터
	pList->pCurrent = pList->pHead;
	while (i < n)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		i++;
	}

	pList->pCurrent->data = data;  // 데이터 수정

	printf("%d 번째 데이터 수정\n", n);
	return TRUE;
}


// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;
}


// 데이터 삭제
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
		return FALSE;

	int i = 0;  // 첫번째 부터
	pList->pCurrent = pList->pHead;
	while (i < n)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		i++;
	}

	// 이미 위에서 pCurrent 는 이동했다.
	// 순서 잘 생각해야 한다.  순서 바뀌면 엉망된다.

	// 양방향이니 엮어 주기만 하면 된다.
	if (pList->pCurrent->pPrev != NULL)
	{
		pList->pCurrent->pPrev->pNext = pList->pCurrent->pNext;
	}
	if (pList->pCurrent->pNext != NULL)
	{
		pList->pCurrent->pNext->pPrev = pList->pCurrent->pPrev;
	}

	// head 와 tail 업데이 필요한 경우 (즉, 맨 앞과 맨 뒤의 경우)
	if (pList->pCurrent == pList->pHead)
	{
		pList->pHead = pList->pCurrent->pNext;
	}
	if (pList->pCurrent == pList->pTail)
	{
		pList->pTail = pList->pCurrent->pPrev;
	}


	// Node 동적 할당 반.드.시 해제
	free(pList->pCurrent);

	pList->numData--;  // 리스트 size 감소
	printf("%d 번째 데이터 삭제\n", n);
	return TRUE;
}


// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
		return FALSE;

	int i = 0;  // 첫번째 부터
	pList->pCurrent = pList->pHead;
	while (i < n)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		i++;
	}


	// 매개변수에 값 담아줌
	*pData = pList->pCurrent->data;
	printf("get %d 번째 데이터 %d\n", n, *pData);

	return TRUE;
}



// 리스트 소멸
// head까지 완전 소멸이다.
void list_destroy(List *pList)
{
	pList->pCurrent = pList->pHead;
	while (pList->pCurrent != NULL)
	{
		Node *tmp = pList->pCurrent;
		pList->pCurrent = pList->pCurrent->pNext;
		free(tmp);
	}

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("리스트 소멸\n");
}
