#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList 의 ADT
*/

#define TRUE 1
#define FALSE 0

typedef int Data;     // 데이터는 int

// 노드 타입 정의
typedef struct _node
{
	Data data;     // 노드 데이터
	struct _node *pNext;  // 다음 노드
	struct _node *pPrev;  // 이전 노드  ★★
} Node;

// Linked List 타입 정의
typedef struct _linkedList
{
	Node *pHead;   // 시작 노드
	Node *pTail;   // 끝 노드

	Node *pCurrent;   // iteration 용
	int numData;     // 노드의 개수

}LinkedList;


/* LinkedList 동작 */
typedef LinkedList List;

void list_init(List *pList);   // 리스트 초기화  
void list_destroy(List *pList);   // 리스트 소멸

int list_add(List *pList, Data data);  // 데이터 추가 (끝에)

// 양방향 연결리스트에서 대폭 변경
int list_init_iter(List *pList, Data* pData);   // 첫번째로 데이터 가져오기
int list_last(List *pList, Data* pData);    // 마지막 데이터 가져오기
int list_next(List *pList, Data* pData);  // 다음 데이터 가져오기
int list_prev(List *pList, Data* pData);  // 이전 데이터 가져오기

int list_remove(List *pList, int n);  // 데이터 삭제
int list_set(List *pList, int n, Data data);  // 데이터 수정
int list_length(List *pList);  // 데이터 개수

int list_get(List* pList, int n, Data *pData);   // 데이터 조회 : n번째 데이터 값 읽기

#endif