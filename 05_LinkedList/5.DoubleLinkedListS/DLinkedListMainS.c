#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "DLinkedListS.h"

// 리스트 출력 도우미 함수
void printData(Data* pData)
{
	printf("%s/%d살/%c, ", pData->szName, pData->age, pData->grade);
}

void printList(List *pList)
{
	list_init_forward(pList);  // ★ forward iteration 시작
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]");

	list_init_backward(pList);  // ★ backward iteration 시작
	printf("[");
	while (list_hasPrev(pList))
	{
		printData(list_prev(pList));
	}
	printf("]\n");
}


int main()
{
	printf("<< 이중 연결 리스트 >>\n\n");
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

	// 데이터 추가
	printList(&myList);
	list_add(&myList, stu + 0);
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

	//데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) { printData(&data); printf("\n");}
	if (list_get(&myList, 6, &data)) { printData(&data); printf("\n"); }
	if (list_get(&myList, 4, &data)) { printData(&data); printf("\n"); }
	printf("\n");

	// 데이터 삭제
	list_remove(&myList, 0);
	list_remove(&myList, 3);
	printList(&myList);
	list_remove(&myList, 0);
	list_remove(&myList, 1);
	printList(&myList);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);


	// 검색성능 체크
	// 일단 
	int i;
	for (i = 0; i < 3000; i++)
	{
		list_add(&myList, stu + 0);
	}

	clock_t start, end;
	long result;
	int sum = 0;
	int j;

	printf("clock() 측정시작\n");
	start = clock(); //시간 측정 시작

	for (j = 0; j < 1000; j++)
	{
		for (i = 0; i < 2000; i++)
		{
			list_get(&myList, i, &data);
		}
	}


	end = clock(); //시간 측정 끝
	result = end - start;
	printf("%ld ms\n", result);




	list_destroy(&myList);

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()