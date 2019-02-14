#include <stdio.h>
#include "ArrayList.h"

// 리스트 출력 도우미 함수
void printList(List *pList)
{
	list_init_iter(pList);  // iteration 시작
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}
	printf("]\n");
}

int main()
{
	List myList;
	list_init(&myList);   // 리스트 생성
	
	list_add(&myList, 100);  // 데이터 추가
	list_add(&myList, 50);   // 데이터 추가
	list_add(&myList, 100);   // 데이터 추가
	list_add(&myList, 20);   // 데이터 추가
	list_add(&myList, 45);   // 데이터 추가    - 실패
	list_add(&myList, 70);   // 데이터 추가    - 실패

	list_destroy(&myList);  // 리스트 제거
	return 0;
} // end main()

