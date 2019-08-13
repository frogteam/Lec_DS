#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedListS.h"
#pragma warning(disable:4996)

// 리스트 초기화  
void list_init(List *pList)
{
	// head / tail 의 dummy node 방식
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));
	pList->pTail = (Node*)malloc(sizeof(Node));  // ★
	memset(pList->pTail, 0, sizeof(Node));  // ★

	pList->numData = 0;
	printf("리스트 초기화\n");
}

// 데이터 추가 (끝에)
int list_add(List *pList, Data *pData)
{
	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));   // prev 도 next 도 null 로 세팅
	
	pNewNode->pData = (Data*)malloc(sizeof(Data));
	memcpy(pNewNode->pData, pData, sizeof(Data)); // 데이터복사

	// ★ 데이터 노드가 없을때 와 한개라도 있을때 구분해야 한다.
	if (pList->numData == 0)   // 데이터 노드가 하나도 없을때
	{
		pList->pHead->pNext = pNewNode;  // ★
		pList->pTail->pPrev = pNewNode;  // ★
	}
	else  // 데이터 노드가 한개이상 있을때
	{
		// tail 이 가리키던 next 를 새로운 node 에 연결
		pList->pTail->pPrev->pNext = pNewNode;    // ★ ①   최초인 경우 pTail->pPrev   는 pHead 와 같다.
		pNewNode->pPrev = pList->pTail->pPrev;  // ★ ②
		pList->pTail->pPrev = pNewNode;  // ★ ③
	}

	printf("[%d] 번째 데이터 %s 추가\n", pList->numData, pData->szName);
	(pList->numData)++;
	return SUCCESS;
}

// forward 방향으로 초기화
void list_init_forward(List *pList)  // ★
{
	pList->pCurrent = pList->pHead;
}

// 데이터 조회 : 다음번 있나?
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)   // '다음 노드' 여부를 체크한다.
		return FAIL;

	return SUCCESS;
}

// 데이터 조회, 다음번
Data *list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 우선 current 이동
	return pList->pCurrent->pData;
}

// ★ backward iteration 초기화 
void list_init_backward(List *pList)
{
	pList->pCurrent = pList->pTail;
}
// ★데이터 조회 : 이전 노드 있나?
int list_hasPrev(List *pList)
{
	if (pList->pCurrent->pPrev == NULL)   // '이전 노드' 여부를 체크한다.
		return FAIL;

	return SUCCESS;
}

// ★데이터 조회, 이전 노드 데이터
Data *list_prev(List *pList)
{
	pList->pCurrent = pList->pCurrent->pPrev;  // 우선 current 이동
	return pList->pCurrent->pData;
}

// ★★★
// current 이동 :  doubly linked list 의 장점
// next 뿐 아니라 prev 도 갖고 있기 때문에  current 만 알면
// 삭제, 삽입 등의 조작 가능  
// (단방향 linkedlist 에선 코드에서 prev 에 대한 정보를 따로 관리 했어야 했기 때문에 current 만 안다고 해결 안되었다)
int list_move_current(List* pList, int n)
{
	// n 에 대한 검증은 사전에 한것으로 간주
	int i;
	if (n <= pList->numData / 2)
	{	// head 에서 부터
		pList->pCurrent = pList->pHead->pNext;
		for (i = 0; i < n; i++)
			pList->pCurrent = pList->pCurrent->pNext;
	}
	else
	{	// tail 에서 부터
		pList->pCurrent = pList->pTail->pPrev;
		for (i = 0; i < pList->numData - n - 1; i++)    // 몇번 loop
			pList->pCurrent = pList->pCurrent->pPrev;
	}
	return SUCCESS;
}



// 데이터 수정
int list_set(List *pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("수정실패: %d 번째 데이터가 없습니다\n", n);
		return FAIL;
	}

	// 일단 여기까지는 최소한 데이터가 1개 이상은 있다는 거다.

	list_move_current(pList, n);  // ★ current 이동 --> n번째 노드

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

	// 일단 여기까지는 최소한 데이터가 1개 이상은 있다는 거다.

	list_move_current(pList, n);  // ★ current 이동 --> n번째 노드

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

	list_move_current(pList, n);  // ★ current 이동 --> n번째 노드

	// ★ 이중연결리스트 는 current 만 알아도 '삭제' 가 편리하다 
	if(pList->pCurrent->pPrev != NULL)                           // ①첫번째 노드삭제가 아닌 경우   
		pList->pCurrent->pPrev->pNext = pList->pCurrent->pNext;  // ① current 의 prev 의 next 를 current 의 next 로 변경 
	else 
		pList->pHead->pNext = pList->pCurrent->pNext;    // 첫번째 노드삭제인 경우 head 쪽 변경

	if(pList->pCurrent->pNext != NULL)                           // ② 마지막 노드삭제가 아닌 경우 
		pList->pCurrent->pNext->pPrev = pList->pCurrent->pPrev;  // ② current 의 next 의 prev 를 current 의 prev 로 변경
	else
		pList->pTail->pPrev = pList->pCurrent->pPrev;   // 마지막 노드 삭제인 경우 tail 쪽 변경


	// Node 동적 할당 반.드.시 해제
	free(pList->pCurrent->pData);   // 데이터 삭제!
	free(pList->pCurrent);     // Node 삭제

	pList->numData--;  // 리스트 size 감소
	printf("%d 번째 데이터 삭제\n", n);
	return SUCCESS;
}

// 리스트 소멸
void list_destroy(List *pList)
{
	pList->pCurrent = pList->pHead->pNext;

	int cnt = 0;  // 삭제된 node 개수
	while (pList->pCurrent != NULL)
	{
		Node *pTmp = pList->pCurrent;  // 삭제될 노드
		pList->pCurrent = pList->pCurrent->pNext;  // 지우기 전에 current 이동

		free(pTmp->pData);   // 데이터 삭제
		free(pTmp);          // 노드 삭제
		cnt++;
	}

	// dummy node 삭제
	free(pList->pHead);   // dummy 에는 데이터 없으니 데이터는 신경쓰지 않아도 된다.
	free(pList->pTail);   // ★★

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;

	printf("리스트 제거 %d 개의 node 삭제\n", cnt);
}
