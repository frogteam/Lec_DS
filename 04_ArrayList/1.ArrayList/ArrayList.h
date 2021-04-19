#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	ArrayList 의 ADT

	ArrayList 의
	장점 : n번째 조회 빠르다
	단점 : 삭제, 삽입 느리다.

	장점 : 용량
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList 의 데이터 정의 */
//#define LIST_LEN	4
#define LIST_LEN	30000    // 프로파일링용

typedef int Data;     // 데이터는 int

typedef struct _ArrayList
{
	Data arr[LIST_LEN];  // 데이터(들)
	int numData;           // 리스트 안의 데이터 개수
	int curPosition;      // iteration
} ArrayList;

typedef ArrayList List;

/* ArrayList 동작 */
void list_init(List *pList);   // 리스트 초기화  
void list_destroy(List *pList);   // 리스트 제거

int list_add(List *pList, Data data);  // 데이터 추가
int list_remove(List *pList, int n);  // n번째 데이터 삭제
int list_set(List *pList, int n, Data data);  // n번째 데이터 수정
int list_length(List *pList);  // 데이터 개수

void list_init_iter(List *pList);   // 데이터 조회, iteration 초기화
Data list_next(List *pList);  // 데이터 조회, iteration 다음 데이터 추출
int list_hasNext(List *pList);  // 데이터 조회, iteration 다음 데이터 있나?

int list_get(List* pList, int n, Data *pData);   // 데이터 조회 : n번째 데이터 값 읽기

// 
int list_insert(List* pList, int n, Data data);  // 데이터 삽입: n번째 위치에 데이터 삽입


#endif