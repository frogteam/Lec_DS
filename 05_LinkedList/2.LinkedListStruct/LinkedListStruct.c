#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListStruct.h"
#pragma warning(disable:4996)


// 리스트 초기화  
void list_init(List *pList)
{
	// head용 dummy node 방식
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));   // 노드 초기화, 당연히 pHead의 pNext 도 NULLL 이 된다.

	pList->pTail = pList->pHead;  // 최초에는 tail 과 head 동일
	
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
	memcpy(pNewNode->pData, pData, sizeof(Data)); // 데이터복사

	// tail 이 가리키던 next 를 새로운 node 에 연결
	pList->pTail->pNext = pNewNode;
	pList->pTail = pNewNode;

	printf("[%d] 번째 데이터 %s 추가\n", pList->numData, pData->szName);
	(pList->numData)++;
	return SUCCESS;
}


// 데이터 조회, 첫번째로
void list_init_iter(List *pList)
{
	pList->pCurrent = pList->pHead;
}

// 데이터 조회 : 다음번 있나?
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)   // '다음것' 여부를 체크한다.
		return FAIL;

	return SUCCESS;
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
	{
		printf("수정실패: %d 번째 데이터가 없습니다\n", n);
		return FAIL;
	}

	// 일단 여기까지는 최소한 데이터가 1개 이상은 있다는 거다.

	pList->pCurrent = pList->pHead->pNext;

	int i;
	for (i = 0; i < n; i++)
		pList->pCurrent = pList->pCurrent->pNext;

	// 데이터 수정
	pList->pCurrent->pData->age = pData->age;
	pList->pCurrent->pData->grade = pData->grade;
	strcpy(pList->pCurrent->pData->szName, pData->szName);  // 문자열 복사

	printf("%d 번째 데이터 수정\n", n);
	return SUCCESS;
}

// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;
}

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("%d 번째 데이터가 없습니다\n", n);
		return FAIL;
	}

	// 일단 여기까진 데이터가 1개 이상 있다는 사실

	pList->pCurrent = pList->pHead->pNext;

	int i;
	for (i = 0; i < n; i++)
		pList->pCurrent = pList->pCurrent->pNext;

	// 매개변수에 값 담아줌
	pData->age = pList->pCurrent->pData->age;
	pData->grade = pList->pCurrent->pData->grade;
	strcpy(pData->szName, pList->pCurrent->pData->szName);

	return SUCCESS;
}

// 데이터 삭제
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
	{
		printf("삭제실패: %d 번째 데이터는 없습니다\n", n);
		return FAIL;
	}

	// 일단 여기까지는 최소한 데이터가 1개 이상은 있다는 거다.

	// n번째  위치를 찾아야 하는데
	// 직전 위치도 알아야 한다.
	int i = 0;
	Node *pPrev = pList->pHead;
	pList->pCurrent = pList->pHead->pNext;   // <-- 최소한 1개는 있으니까!   <-- 일단 #0번째 데이터다
	
	for (i = 0; i < n; i++)  // <-- #1번째 부터 ~ n번째까지 찾아가기
	{
		pPrev = pList->pCurrent;					 // prev 와 current 가 같이 움직인다.
		pList->pCurrent = pList->pCurrent->pNext;
	}

	// 삭제가 매우 단순 (배열에 비해)
	pPrev->pNext = pList->pCurrent->pNext;

	// 만약 tail 이 삭제 데이터였다면 tail값도 수정해야 한다
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;

	// Node 동적 할당 반.드.시 해제
	free(pList->pCurrent->pData);   // ★ 데이터 꼭 삭제!
	free(pList->pCurrent);     // Node 삭제

	pList->numData--;  // 리스트 size 감소
	printf("%d 번째 데이터 삭제\n", n);
	return SUCCESS;
}



// 리스트 소멸
// head까지 완전 소멸이다.
void list_destroy(List *pList)
{
	int cnt = 0;  // 삭제된 node 개수

	//pList->pCurrent = pList->pHead->pNext;
	//
	//while(pList->pCurrent != NULL)
	//{
	//	Node *pTmp = pList->pCurrent;  // 삭제될 노드
	//	pList->pCurrent = pList->pCurrent->pNext;  // 지우기 전에 current 이동

	//	free(pTmp->pData);   // 데이터 삭제
	//	free(pTmp);          // 노드 삭제
	//	cnt++;
	//}

	int i;
	int num = pList->numData;
	for (i = 0; i < num; i++)
	{
		list_remove(pList, 0);
		cnt++;
	}

	// dummy node 삭제
	free(pList->pHead);   // dummy 에는 데이터 없으니 데이터는 신경쓰지 않아도 된다.

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("리스트 제거 %d 개의 node 삭제\n", cnt);
}

