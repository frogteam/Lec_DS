#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "DLinkedList.h"

// 리스트 출력 도우미 함수
void printList(List *pList)
{
	int data;
	// 정방향
	printf("[");
	if (list_init_iter(pList, &data))
	{
		printf("%d ", data);
		while (list_next(pList, &data))
		{
			printf("%d ", data);
		}
	}
	printf("]");
	// 역방향
	printf("[");
	if (list_last(pList, &data))
	{
		printf("%d ", data);
		while (list_prev(pList, &data))
		{
			printf("%d ", data);
		}
	}
	printf("]");
	printf("\n");
}

int main()
{
	printf("<< 이중 연결 리스트 >>\n\n");

	List myList;
	list_init(&myList);

	///** add() 동작 확인 **/
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 50);   // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);   // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);   // 데이터 추가
	list_add(&myList, 70);    // 데이터 추가
	printList(&myList);

	// get()
	Data data;
	if(list_get(&myList, 4, &data))
		printf("  data=%d\n", data);
	if (list_get(&myList, 5, &data))
		printf("  data=%d\n", data);


	//// 데이터 수정
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); 
	printList(&myList);

	//// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));


	// 데이터 삭제
	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 0);
	printList(&myList);

	list_remove(&myList, 2);
	printList(&myList);


	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);

	printf("데이터 개수는 %d\n", list_length(&myList));

	list_destroy(&myList);

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()