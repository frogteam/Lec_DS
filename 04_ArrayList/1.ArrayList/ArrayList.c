#include <stdio.h>
#include <string.h>   // memset()
#include "ArrayList.h"

/* 매개변수 유효성 검증은 생략 */

// 리스트 초기화
void list_init(List* pList)
{
	pList->numData = 0;
	pList->curPosition = -1;   // iterating 에 대해
	memset(pList->arr, 0, sizeof(pList->arr));
	printf("리스트 초기화\n");
}

// 리스트 제거
void list_destroy(List* pList)
{
	pList->numData = 0;
	printf("리스트 제거\n");
}

int list_add(List* pList, Data data)
{
	if(pList->numData >= LIST_LEN)
	{
		printf("데이터 추가 불가\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data;

	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;
	return SUCCESS;
}

// 데이터 조회, 첫번째로
void list_init_iter(List *pList)
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
		return SUCCESS;

	return FAIL;
}

// 데이터 수정
// 
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) {
		printf("%d번째 데이터 수정 실패\n", n);
		return FAIL;
	}
	
	printf("%d 번째 데이터 수정 %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;
	return SUCCESS;
}

// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;  // 솔직히 배열이니까 numData 유지중
}

// 데이터 삭제
int list_remove(List *pList, int n)
{
	// 배열이니까 중간 삭제하면 뒤의 것도 당겨야 한다.
	if (n >= pList->numData)
	{
		printf("%d번째 데이터 삭제 실패\n", n);
		return FAIL;
	}

	int i;
	for (i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numData--;  // 리스트 size 감소

	printf("%d 번째 데이터 삭제\n", n);
	return SUCCESS;
}

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	*pData = pList->arr[n];  // 데이터 값,  포인터로 리턴

	return SUCCESS;
}

// 데이터 삽입: n번째 위치에 데이터 삽입
int list_insert(List* pList, int n, Data data)
{
	// 이미 다 차있으면 불가
	if (pList->numData >= LIST_LEN)
	{
		printf("데이터 삽입 불가\n");
		return FAIL;
	}

	// '중간' 및 '끝' 삽입은 허용
	if (n > pList->numData)
	{
		printf("%d 번째 위치에 삽입 불가\n", n);
		return FAIL;
	}

	// 기존의 n번째 부터 한칸씩 뒤로 밀려나야 한다.
	// 맨 뒤에서부터!!! 부터 n 앞의 것들은 한칸씩 우측으로 복사
	int i;
	for (i = pList->numData; i - 1 >= n ; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[n] = data; // n번째 새 데이터 
	pList->numData++;  // 데이터 개수 증가
	printf("%d번째 데이터 %d 삽입 성공\n", n, data);

	return SUCCESS;
}
