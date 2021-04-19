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

	printf("리스트 초기화\n");
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

	(pList->numData)++;     // 데이터 개수 증가
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
	if (pList->pCurrent->pNext == NULL)  // '다음노드' 존재 여부를 체크한다
		return FALSE;

	return TRUE;
}

// 데이터 조회, 다음번
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 우선 current 한발 앞으로 이동
	Data result = pList->pCurrent->data;  // 데이터 추출
	return result;
}

// n번째 데이터 수정
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FALSE;

	// head부터시작해서 n번째 노드 찾기,  iteration 사용
	list_init_iter(pList);  // iteration 시작
	int i = 0;  // 현재 몇번째 노드?
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) break;  // n번째 노드 찾음! 
		i++;
	}
	// 위 while 문이 끝나면 pCurrent 는 n번째 노드를 가리키고 있슴

	printf("%d 번째 데이터 수정 %d  --> %d\n", n, pList->pCurrent->data, data);

	pList->pCurrent->data = data;  // 데이터 수정

	return TRUE;
}

// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;
}

// n번째 데이터 삭제
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
		return FALSE;

	// n번째 노드 삭제하려면
	// n번째 뿐 아니라 n-1 번째 노드 정보도 알아야 한다
	// 즉. 이전 노드(previous node) 또한 알아야 한다.
	list_init_iter(pList);  // iteration 시작
	int i = 0;
	Node *pPrev = NULL;  // 이전 노드를 가리킬 포인터
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent; // pCurrent 를 이동하기 전의 pCurrent 값을 이전노드 로 기억해야 한다
		list_next(pList);    // pCurrent 이동
		if (i >= n)	break;
		i++;
	}

	// 위 while 문이 끝나면 
	// pCurrent (n번째 노드), pPrev(n-1번째 노드) 가 결정됨.

	// 순서 잘 생각해야 한다.  순서 바뀌면 엉망된다.

	// 삭제진행: 매우 단순 (배열에 비해)
	pPrev->pNext = pList->pCurrent->pNext;

	// 만약 tail 이 삭제할 노드였다면 tail값도 수정해야 한다
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;  // tail 을 이전 노드로 이동

	// n번째 노드삭제 동적 메모리 할당 해제! 꼭!
	free(pList->pCurrent);

	pList->numData--;  // 리스트 데이터 개수 -1 감소
	
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
		if (i >= n) break; // n 번째 발견!
		i++;
	}
	// 위 while문이 끝나면 pCurrent 값은 n번째 node를 가리키고 있다.

	// 매개변수에 n번째 노드 데이터 담아줌
	*pData = pList->pCurrent->data;

	//printf("get %d 번째 데이터 %d\n", n, *pData);

	return TRUE;
}

// 리스트 소멸
// head까지 완전 소멸이다.
void list_destroy(List *pList)
{
	list_init_iter(pList);  // iteration 시작
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);  // 일단 pCurrent 다음노드 이동
		free(pPrev);  // 노드 삭제
	}
	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("리스트 소멸\n");
}

// 데이터 삽입: n번째 위치에 데이터 삽입
// 맨뒤에 삽입(추가) 하는 것도 허용
int list_insert(List* pList, int n, Data data)
{
	if (n > pList->numData) return FALSE;  // >= 이 아니라 > 이다!


	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	
	if (pList->numData == 0)  // 1.첫번째 데이터인 경우
	{
		pList->pHead->pNext = pNewNode;
		pList->pTail = pNewNode;
	} 
	else if (n == pList->numData)  // 2.맨 끝에 추가면
	{
		pList->pTail->pNext = pNewNode; // add() 와 동일
		pList->pTail = pNewNode;
	}
	else
	{
		// 3. n번째 노드에 삽입하려면
		// n-1번째 노드, 직전노드(previoud node) 또한 알아야 한다.
		list_init_iter(pList);  // iteration 시작
		int i = 0;
		Node *pPrev = NULL;  // 이전 노드를 가리킬 포인터
		while (list_hasNext(pList))
		{
			pPrev = pList->pCurrent; // pCurrent 를 이동하기 전의 pCurrent 값을 이전노드 로 기억해야 한다
			list_next(pList);    // pCurrent 이동
			if (i >= n)	break;
			i++;
		}

		// 위 while 문이 끝나면 
		// pCurrent (n번째 노드), pPrev(n-1번째 노드) 가 결정됨.

		// 삽입동작 수행
		pPrev->pNext = pNewNode;  // 이전 노드는 새로운 노드를 가리키고
		pNewNode->pNext = pList->pCurrent;   // 새로운 노드는 기존의 n번째 노드를 가리키면 된다
	}

	//printf("[%d] 번째 데이터 %d 삽입\n", n, data);
	
	(pList->numData)++;     // 데이터 개수 증가
	return TRUE;
}