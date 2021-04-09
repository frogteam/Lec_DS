#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


// 리스트 초기화  
void list_init(List *pList)
{
	// head용 dummy node 방식
	pList->pHead = (Node*)malloc(sizeof(Node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead;  // 최초에는 tail 과 head 동일
	
	//pList->pHead = NULL;
	//pList->pTail = NULL;
	pList->numData = 0;

	//printf("리스트 초기화\n");
}

// 데이터 추가 : 
int list_add(List *pList, Data data)
{
	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	// tail 이 가리키던 next 를 새로운 node 에 연결
	pList->pTail->pNext = pNewNode;

	//if (pList->pHead == NULL)
	//{
	//	// 첫 node 라면?
	//	pList->pHead = pNewNode;
	//}
	//else 
	//{
	//	// tail 은 새로운 node (끝 node) 가리키게 함
	//	pList->pTail->pNext = pNewNode;
	//}
	
	pList->pTail = pNewNode;    // tail 이동

	//printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;     // 개수 증가
	return TRUE;
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
		return FALSE;

	return TRUE;
}

// 데이터 조회, 다음번
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 우선 current 이동
	Data result = pList->pCurrent->data;
	return result;
}

// 데이터 수정
// 
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) 
		return FALSE;

	list_init_iter(pList);  // iteration 시작
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) 
			break;
		i++;
	}

	pList->pCurrent->data = data;  // 데이터 수정

	//printf("%d 번째 데이터 수정\n", n);
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

	// n번째  위치를 찾아야 하는데
	// 직전 위치도 알아야 한다.
	list_init_iter(pList);  // iteration 시작
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

	// 만약 tail 이 삭제 데이터였다면 tail값도 수정해야 한다
	if (tmp == pList->pTail)
		pList->pTail = pPrev;

	// Node 동적 할당 반.드.시 해제
	free(tmp);

	pList->numData--;  // 리스트 size 감소
	//printf("%d 번째 데이터 삭제\n", n);
	return TRUE;
}

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
		return FALSE;

	list_init_iter(pList);  // iteration 시작
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n)
			break;
		i++;
	}

	// 매개변수에 값 담아줌
	*pData = pList->pCurrent->data;

	//printf("get %d 번째 데이터 %d\n", n, *pData);

	return TRUE;
}

// 리스트 소멸
// head까지 완전 소멸이다.
void list_destroy(List *pList)
{
	list_init_iter(pList);  // iteration 시작
	int i = 0;
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);
		free(pPrev);
	}
	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	//printf("리스트 소멸\n");
}

// 탐색-------------------------------------
Node* list_search(List *pList, int data)
{
	//int d;
	//list_init_iter(pList);
	//while (list_hasNext(pList))
	//{
	//	d = list_next(pList);
	//	if (d == data)
	//		return pList->pCurrent;  // 찾으면 해당 노드 리턴
	//}

	pList->pCurrent = pList->pHead;
	while (pList->pCurrent->pNext != NULL)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		if (pList->pCurrent->data == data)
			return pList->pCurrent;   // 찾으면 해당 노드 리턴
	}

	return NULL;   // 없으면 NULL 리턴
}

