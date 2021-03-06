#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	ArrayList 의 ADT
*/

#define TRUE 1
#define FALSE 0

/* ArrayList 의 정의 */
#define LIST_INC_LEN	3  // 증감분

typedef int Data;     // 데이터는 int

typedef struct _ArrayList
{
	Data *arr;  // 데이터(들) 포인터로 변경
	int maxLen;           // 준비된 배열 공간
	int numData;           // 리스트 안의 데이터 개수
	int curPosition;      // iteration
} ArrayList;

/* ArrayList 동작 */
typedef ArrayList List;

void list_init(List *pList);   // 리스트 초기화  
void list_destroy(List *pList);   // 리스트 소멸

int list_add(List *pList, Data data);  // 데이터 추가

void list_first(List *pList);   // 데이터 조회, 첫번째로
Data list_next(List *pList);  // 데이터 조회, 다음 데이터
int list_hasNext(List *pList);  // 데이터 조회 : 다음번 있나?

int list_remove(List *pList, int n);  // 데이터 삭제
int list_set(List *pList, int n, Data data);  // 데이터 수정
int list_size(List *pList);  // 데이터 개수

int list_get(List* pList, int n, Data *pData);   // 데이터 조회 : n번째 데이터 값 읽기



#endif