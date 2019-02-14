#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "LinkedListStruct.h"



// 리스트 출력 도우미 함수
void printData(Data* pData)
{
	printf("%s/%d살/%c, ", pData->szName, pData->age, pData->grade);
}
void printList(List *pList)
{
	list_first(pList);  // iteration 시작
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]\n");
}

int main()
{
	List myList;
	list_init(&myList);

	Data stu[] = {
		{"홍길동", 20, 'A'},
		{"James", 34, 'B'},
		{"허준", 30, 'D'},
		{"제일형", 23, 'E'},
		{"하후", 77, 'C'},
		{"마이클", 38, 'C'}
	};

	printList(&myList);
	list_add(&myList, stu + 0);   // &stu[0] 로 해도 되다
	printList(&myList);
	list_add(&myList, stu + 1);
	printList(&myList);
	list_add(&myList, stu + 2);
	printList(&myList);
	list_add(&myList, stu + 3);
	printList(&myList);
	list_add(&myList, stu + 4);
	printList(&myList);


	Data result;
	list_get(&myList, 2, &result);
	printData(&result); printf("\n");
	list_get(&myList, 0, &result);
	printData(&result); printf("\n");

	printf("데이터 개수는 %d\n", list_size(&myList));

	// 수정
	list_set(&myList, 0, stu + 5);
	list_set(&myList, 2, stu + 5);
	printList(&myList);

	// 삭제
	list_remove(&myList, 0);
	list_remove(&myList, 3);
	printList(&myList);

	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);

	{
		printf("프로파일링 시작: 스냅샷");
		_getch();

		clock_t start, end;

		// 프로파일링
		unsigned int i = 0;
		start = clock(); //시간 측정 시작
		for (i = 0; i < 10000; i++)
		{
			list_add(&myList, stu + (i % 6));
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_size(&myList));

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
		printf("현재 리스트 size : %d\n", list_size(&myList));
		printf("%ld ms 경과\n", end - start);

		printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷");
		_getch();

	}

	list_destroy(&myList);

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()