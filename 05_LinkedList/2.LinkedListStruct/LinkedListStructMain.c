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
	list_init_iter(pList);  // iteration 시작
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]\n");
}

int main()
{
	Data stu[] = {
		{"홍길동", 20, 'A'},
		{"김지원", 34, 'B'},
		{"허준", 30, 'D'},
		{"제시현", 23, 'E'},
		{"박수찬", 77, 'C'},
		{"마이클", 38, 'C'}
	};

	List myList;
	list_init(&myList);

	list_add(&myList, stu + 0);
	list_remove(&myList, 0);
	printList(&myList);

	// 데이터 추가
	printList(&myList);
	list_add(&myList, stu + 0); // ↔ &stu[0]
	printList(&myList);
	list_add(&myList, stu + 1);
	printList(&myList);
	list_add(&myList, stu + 2);
	printList(&myList);
	list_add(&myList, stu + 3);
	printList(&myList);
	list_add(&myList, stu + 4);
	printList(&myList);

	// 데이터 수정
	list_set(&myList, 0, stu + 5);
	list_set(&myList, 2, stu + 5);
	printList(&myList);

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));

	// 데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) printData(&data);
	if (list_get(&myList, 6, &data)) printData(&data);
	if (list_get(&myList, 4, &data)) printData(&data);
	printf("\n");

	// 데이터 삭제
	//list_remove(&myList, 0);
	//list_remove(&myList, 3);
	//printList(&myList);
	//list_remove(&myList, 0);
	//list_remove(&myList, 1);
	//printList(&myList);
	//list_remove(&myList, 0);
	//list_remove(&myList, 0);
	//printList(&myList);

	//{
	//	printf("프로파일링 시작: 스냅샷");
	//	_getch();

	//	clock_t start, end;

	//	// 프로파일링
	//	unsigned int i = 0;
	//	start = clock(); //시간 측정 시작
	//	for (i = 0; i < 10000; i++)
	//	{
	//		list_add(&myList, stu + (i % 6));
	//	}
	//	end = clock(); //시간 측정 끝
	//	printf("현재 리스트 size : %d\n", list_length(&myList));

	//	printf("%ld ms 경과\n", end - start);

	//	printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷");
	//	_getch();
	//	start = clock(); //시간 측정 시작
	//	for (i = 0; i < 10000; i++)
	//	{
	//		list_remove(&myList, 0);
	//		printf("삭제 %d\n", i);
	//	}
	//	end = clock(); //시간 측정 끝
	//	printf("현재 리스트 size : %d\n", list_length(&myList));
	//	printf("%ld ms 경과\n", end - start);

	//	printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷");
	//	_getch();
	//}

	// 검색성능 체크
	// 일단 
	//int i;
	//for (i = 0; i < 3000; i++)
	//{
	//	list_add(&myList, stu + 0);
	//}

	//clock_t start, end;
	//long result;
	//int sum = 0;
	//int j;
	//printf("clock() 측정시작\n");
	//start = clock(); //시간 측정 시작

	//for (j = 0; j < 1000; j++)
	//{
	//	for (i = 0; i < 2000; i++)
	//	{
	//		list_get(&myList, i, &data);
	//	}
	//}

	//end = clock(); //시간 측정 끝
	//result = end - start;
	//printf("%ld ms\n", result);

	list_destroy(&myList);

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()