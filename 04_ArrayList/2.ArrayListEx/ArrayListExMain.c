#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "ArrayListEx.h"

// 리스트 출력 도우미 함수
void printList(List *pList)
{
	list_first(pList);  // iteration 시작
	
	// 출력할때도 배열가용크기,  실제저장된 데이터 개수
	printf("%d : %d [", pList->maxLen, pList->numData);
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}
	printf("]\n");
}
void printListShort(List *pList)
{
	printf("%d : %d\n", pList->maxLen, pList->numData);
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
	list_add(&myList, 100);   // 이제는 가능!
	printList(&myList);
	list_add(&myList, 70);    // 이제는 가능!
	printList(&myList);
	list_add(&myList, 80);    // 이제는 가능!
	printList(&myList);
	list_add(&myList, 300);    // 이제는 가능!
	printList(&myList);

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

	list_remove(&myList, 0);
	printList(&myList);
	printf("데이터 개수는 %d\n", list_size(&myList));

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
		printListShort(&myList);
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
		printListShort(&myList);
		printf("%ld ms 경과\n", end - start);

		printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷");
		_getch();

	}


	list_destroy(&myList);  // 리스트 소멸, 동적할당 제거
	return 0;
} // end main()
