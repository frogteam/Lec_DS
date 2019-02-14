#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "LinkedList.h"

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


	// 데이터 수정
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); 
	printList(&myList);

	// 데이터 개수
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

	{
		printf("프로파일링 시작: 스냅샷");
		_getch();

		clock_t start, end;

		// 프로파일링
		unsigned int i = 0;
		start = clock(); //시간 측정 시작
		for (i = 0; i < 10000; i++)
		{
			list_add(&myList, i);
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));

		printf("%ld ms 경과\n", end - start);

		printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷");
		_getch();
		start = clock(); //시간 측정 시작
		for (i = 0; i < 10000; i++)
		{
			list_remove(&myList, 0);
			printf("삭제 %d\n", i);
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("%ld ms 경과\n", end - start);

		printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷");
		_getch();

	}


	list_destroy(&myList);

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()