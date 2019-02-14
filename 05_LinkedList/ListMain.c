#include <stdio.h>
#include "ArrayList.h"

// 리스트 출력 도우미 함수
void printList(List *pList)
{
	list_first(pList);  // iteration 시작
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
	list_init(&myList);

	/** add() 동작 확인 **/
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 50);   // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);   // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);   // 불가
	list_add(&myList, 70);    // 불가

	// 데이터 수정
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);  // 수정 실패
	printList(&myList);

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_size(&myList));

	// 데이터 삭제
	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 0);
	printList(&myList);

	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);

	printf("데이터 개수는 %d\n", list_size(&myList));

	return 0;
} // end main()