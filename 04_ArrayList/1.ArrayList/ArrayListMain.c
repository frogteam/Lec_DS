#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "ArrayList.h"

// 리스트 출력 도우미 함수
void printList(List *pList)
{
	list_init_iter(pList);  // iteration 시작
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d,", list_next(pList));
	}
	printf("\b]\n");
}

int main()
{
	List myList;
	list_init(&myList);   // 리스트 초기화
	
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);		 // [100]
	list_add(&myList, 50);   // 데이터 추가
	printList(&myList);      // [100, 50]
	list_add(&myList, 100);   // 데이터 추가
	printList(&myList);       // [100, 50, 100]
	list_add(&myList, 20);   // 데이터 추가
	printList(&myList);       // [100, 50, 100, 20]
	list_add(&myList, 45);   // 데이터 추가    - 실패
	printList(&myList);
	list_add(&myList, 70);   // 데이터 추가    - 실패
	printList(&myList);

	// 데이터 수정
	list_set(&myList, 0, 40);  // 0번째 데이터를 100 --> 40으로 수정
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);  // 수정 실패
	printList(&myList);

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList)); // 4

	// 데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) printf("0번째 : %d\n", data); // 40
	if (list_get(&myList, 6, &data)) printf("6번째 : %d\n", data); // 실패
	if (list_get(&myList, 2, &data)) printf("2번째 : %d\n", data); // 100
	

	// 데이터 삭제
	printf("삭제전\n");
	printList(&myList); // [40, 30, 100, 20] 삭제전
	list_remove(&myList, 2);
	printList(&myList); // [40, 30, 20]
	list_remove(&myList, 2);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);
	printf("데이터 개수는 %d\n", list_length(&myList));


	// insert 테스트
	printf("\n");
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList);  // [10, 20]
	list_insert(&myList, 1, 40);
	printList(&myList);  // [10, 40, 20]
	list_insert(&myList, 0, 5);
	printList(&myList);   // [5, 10, 40, 20]
	list_insert(&myList, 0, 5);  // 실패

	list_init(&myList);
	list_insert(&myList, 0, 5);
	list_insert(&myList, 0, 25);
	list_insert(&myList, 0, 45);
	list_insert(&myList, 0, 55);
	list_insert(&myList, 0, 85);
	printList(&myList);


	list_init(&myList);
	list_insert(&myList, 0, 5);
	list_insert(&myList, 1, 25);
	list_insert(&myList, 2, 45);
	list_insert(&myList, 3, 55);
	list_insert(&myList, 4, 85);
	printList(&myList);

	list_init(&myList);
	list_insert(&myList, 1, 5);
	list_insert(&myList, 2, 5);
	list_insert(&myList, 3, 5);
	list_insert(&myList, 4, 5);
	list_insert(&myList, 5, 5);
	printList(&myList);

	list_destroy(&myList);  // 리스트 제거


	// ※ Linked List 후 프로파일링
	// ArrayList.h 에서 LIST_LEN	30000 설정하고 오자
	{
		printf("--------------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("프로파일링 시작: 스냅샷 - 아무키나 누르세요\n");
		_getch();

		printf("%d 개 insert...\n", test_size);
		// ※ list_add, list_insert, list_delete, list_get 의 printf 를 주석처리하고 진행

		// 프로파일링
		start = clock(); // 시간측정 시작 (현재시간 저장)
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_insert(&myList, 0, i);  // 0번째에 insert!
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("insert 결과 : %ld ms 경과\n", end - start);

		//----------------------------------------
		printf("아무키나 누르시면 다음 테스트 진행합니다\n");
		_getch();
		printf("%d 개 get...\n", test_size);

		// 프로파일링
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_get(&myList, i, &data);
		}
		end = clock(); //시간 측정 끝
		printf("get 결과 : %ld ms 경과\n", end - start);

		printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷\n");
		_getch();
		printf("%d 개 remove...\n", test_size);
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("remove 결과 : %ld ms 경과\n", end - start);

		printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷\n");
		_getch();
		list_destroy(&myList);
	}


	printf("아무키나 누르면 종료됩니다");
	_getch();
	return 0;
} // end main()

