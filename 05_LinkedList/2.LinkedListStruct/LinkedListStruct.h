#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList 의 ADT
*/

#define SUCCESS 1
#define FAIL 0

// 데이터 구조체
typedef struct _student
{
	char szName[20]; // 이름
	int age;     // 나이      
	char grade;  // 성적 등급  (ex 'A', 'B', .)
} Student;

typedef Student Data;     // 데이터가 Student!

// 노드 타입 정의
typedef struct _node
{
	Data *pData; // 노드 데이터 ★포인터
	struct _node *pNext;  // 다음 노드
} Node;

// Linked List 타입 정의
typedef struct _linkedList
{
	Node *pHead;   // 시작 노드
	Node *pTail;   // 끝 노드

	Node *pCurrent;   // iteration 용
	int numData;     // 노드의 개수
}LinkedList;

typedef LinkedList List;

/* LinkedList 동작 */
void list_init(List *pList);   // 리스트 초기화  
void list_destroy(List *pList);   // 리스트 소멸

int list_add(List *pList, Data *pData);  // 데이터 추가 ★데이터는 포인터로 받는다
int list_remove(List *pList, int n);  // 데이터 삭제
int list_set(List *pList, int n, Data *pData);  // 데이터 수정 ★데이터는 포인터로 받는다
int list_length(List *pList);  // 데이터 개수

void list_init_iter(List *pList);   // 데이터 조회, 첫번째로
int list_hasNext(List *pList);  // 데이터 조회 : 다음 노드 있나?
Data *list_next(List *pList);  // 데이터 조회, 다음 데이터  ★데이터 포인터로 리턴


int list_get(List* pList, int n, Data *pData);  // 데이터 조회 : n번째 데이터 값 읽기


#endif