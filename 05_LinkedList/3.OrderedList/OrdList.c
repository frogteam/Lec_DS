#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OrdList.h"
#pragma warning(disable:4996)


// 리스트 초기화  
void list_init(List *pList)
{
	// head용 dummy node 방식
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));   // 노드 초기화
	
	pList->numData = 0;

	printf("리스트 초기화\n");
}

// 데이터 추가 : 
int list_add(List *pList, Data *pData)
{
	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->pData = (Data*)malloc(sizeof(Data));
	memset(pNewNode->pData, 0, sizeof(Data));

	// 데이터 복사
	pNewNode->pData->age = pData->age;
	pNewNode->pData->grade = pData->grade;
	strcpy(pNewNode->pData->szName, pData->szName);  // 문자열 복사

	
	// 정렬되어 데이터 추가
	// 앞에서부터 
	int i = 0;
	Node *pPrev = pList->pHead;

	while (pPrev->pNext != NULL &&
		pList->fnComp(pData, pPrev->pNext->pData) != 0)
	{
		pPrev = pPrev->pNext;
		i++;
	}

	pNewNode->pNext = pPrev->pNext;
	pPrev->pNext = pNewNode;

	printf("[%d] 번째 데이터 %s 추가\n", pList->numData, pData->szName);
	(pList->numData)++;
	return TRUE;
}


// 데이터 조회, 첫번째로
void list_first(List *pList)
{
	pList->pCurrent = pList->pHead;
}

// 데이터 조회 : 다음번 있나?
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)   // '다음것' 여부를 체크한다.
		return FALSE;

	return TRUE;
}

// 데이터 조회, 다음번
Data *list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 우선 current 이동
	return pList->pCurrent->pData;
}

// 데이터 수정
// 
int list_set(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) 
		return FALSE;

	list_first(pList);  // iteration 시작
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) 
			break;
		i++;
	}

	// 데이터 수정
	pList->pCurrent->pData->age = pData->age;
	pList->pCurrent->pData->grade = pData->grade;
	strcpy(pList->pCurrent->pData->szName, pData->szName);  // 문자열 복사



	printf("%d 번째 데이터 수정\n", n);
	return TRUE;
}

// 데이터 개수
int list_size(List *pList)
{
	return pList->numData;
}

// 데이터 삭제
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
		return FALSE;

	// n번째  위치를 찾아야 하는데
	// 직전 위치도 알아야 한다.
	list_first(pList);  // iteration 시작
	int i = 0;
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		// 
		pPrev = pList->pCurrent;
		list_next(pList);
		if (i >= n)
			break;
		i++;
	}

	// 이미 위에서 pCurrent 는 이동했다.
	// 순서 잘 생각해야 한다.  순서 바뀌면 엉망된다.

	Node *tmp = pPrev->pNext;  // 현재 커런트

	// 삭제가 매우 단순 (배열에 비해)
	pPrev->pNext = pList->pCurrent->pNext;

	// Node 동적 할당 반.드.시 해제
	free(tmp->pData);   // ★ 데이터 꼭 삭제!
	free(tmp);

	pList->numData--;  // 리스트 size 감소
	printf("%d 번째 데이터 삭제\n", n);
	return TRUE;
}

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
		return FALSE;

	list_first(pList);  // iteration 시작
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n)
			break;
		i++;
	}

	// 매개변수에 값 담아줌
	pData->age = pList->pCurrent->pData->age;
	pData->grade = pList->pCurrent->pData->grade;
	strcpy(pData->szName, pList->pCurrent->pData->szName);

	printf("get %d 번째 데이터 %s\n", n, pData->szName);

	return TRUE;
}

// 리스트 소멸
// head까지 완전 소멸이다.
void list_destroy(List *pList)
{
	list_first(pList);  // iteration 시작
	int i = 0;
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);
		free(pPrev->pData);   // ★ 동적할당된 데이터 꼭 삭제 
		free(pPrev);
	}
	pList->pHead = NULL;
	pList->numData = 0;
	printf("리스트 소멸\n");
}