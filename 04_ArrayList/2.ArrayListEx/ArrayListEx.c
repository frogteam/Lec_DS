#include <stdio.h>
#include <string.h>   // memset()
#include <stdlib.h>    // realloc
#include "ArrayListEx.h"

/* 매개변수 유효성 검증은 생략 */

// 리스트 초기화
void list_init(List* pList)
{
	// 초기 배열 크기 지정
	pList->arr = (Data*)malloc(sizeof(Data) * LIST_INC_LEN);
	pList->maxLen = LIST_INC_LEN;  // 최초 배열 크기 (개수단위)

	pList->numData = 0;        
	pList->curPosition = -1;   // iterating 에 대해
	memset(pList->arr, 0, sizeof(pList->arr));
	printf("리스트 초기화\n");
}

// 리스트 소멸
void list_destroy(List* pList)
{
	free(pList->arr);
	printf("리스트 소멸\n");
}


int list_add(List* pList, Data data)
{
	if(pList->numData >= pList->maxLen)
	{
		int newSize = sizeof(Data) * (pList->maxLen + LIST_INC_LEN);
		// 기존배열보다 '증감분'만큼 증가시킨 새배열 할당
		Data* pNerArr = (Data*)malloc(newSize);
		// 기존배열을 새배열에 '복사'
		memcpy(pNerArr, pList->arr, sizeof(Data) * (pList->maxLen));

		//pList->arr = realloc(pList->arr, newSize);

		free(pList->arr);  // 동적할당된 배열은 반드시 제거
		pList->arr = pNerArr;
		pList->maxLen += LIST_INC_LEN;  // 새로 생성된 배열 
	}

	pList->arr[pList->numData] = data;

	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;
	return TRUE;
}

// 데이터 조회, 첫번째로
void list_first(List *pList)
{
	pList->curPosition = -1;
}

// 데이터 조회, 다음번
Data list_next(List *pList)
{
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];
	
	return result ;
}

// 데이터 조회 : 다음번 있나?
int list_hasNext(List *pList)
{
	if (pList->curPosition + 1 < pList->numData) 
		return TRUE;

	return FALSE;
}

// 데이터 수정
// 
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FALSE;
	
	pList->arr[n] = data;
	printf("%d 번째 데이터 수정\n", n);
	return TRUE;
}

// 데이터 개수
int list_size(List *pList)
{
	return pList->numData;  // 솔직히 배열이니까 numData 유지중
}

// 데이터 삭제
int list_remove(List *pList, int n)
{
	// 배열이니까 중간 삭제하면 뒤의 것도 당겨야 한다.
	if (n >= pList->numData) return FALSE;

	int i;
	for (i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numData--;  // 리스트 size 감소

	// 배열 전체 크기 resizing
	if (pList->numData > 0 && pList->maxLen - pList->numData >= LIST_INC_LEN)
	{
		int newSize = sizeof(Data) * (pList->maxLen - LIST_INC_LEN);
		//Data *pNewArr = (Data*)malloc(newSize);
		pList->arr = (Data*)realloc(pList->arr, newSize);
		pList->maxLen -= LIST_INC_LEN;
	}

	printf("%d 번째 데이터 삭제\n", n);
	return TRUE;
}
//
//int list_get(List* pList, int n, Data *pData);   // 데이터 조회 : n번째 데이터 값 읽기
