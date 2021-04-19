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
	list_add(&myList, 120);   // 데이터 추가
	list_add(&myList, 70);    // 데이터 추가
	printList(&myList);      // [100 50 100 120 70]

	// 데이터 조회, get()
	Data data;
	if(list_get(&myList, 4, &data))
		printf("  data=%d\n", data);
	if (list_get(&myList, 5, &data))
		printf("  data=%d\n", data);


	// 데이터 수정
	// 직전까지 -> [100 50 100 120 70]
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); 
	printList(&myList);  // [40, 30, 100, 120, 30]

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));

	// [40, 30, 100, 120, 30]
	// 데이터 삭제
	list_remove(&myList, 2);
	printList(&myList);   // [40, 30, 120, 30]
	list_remove(&myList, 2);
	printList(&myList);   // [40, 30, 30]
	list_remove(&myList, 0);
	printList(&myList);   // [30, 30]
	list_remove(&myList, 2);  // 실패
	printList(&myList);    // [30, 30]

	list_remove(&myList, 0); // [30]
	list_remove(&myList, 0); // []
	list_remove(&myList, 0);  // 실패
	printList(&myList);   // []

	printf("데이터 개수는 %d\n", list_length(&myList));  // 0

	// 데이터 삽입
	list_insert(&myList, 0, 100);  
	printList(&myList);               // [100 ]
	list_insert(&myList, 0, 200);
	printList(&myList);                // [200 100 ]
	list_insert(&myList, 1, 400);
	printList(&myList);                 // [200 400 100 ]
	list_insert(&myList, 3, 500);
	printList(&myList);				// [200 400 100 500]
	list_insert(&myList, 6, 500);   // 실패
	printList(&myList);				// [200 400 100 500]
	list_insert(&myList, 3, 600);
	printList(&myList);				// [200 400 100 600 500]

	list_add(&myList, 800);   // tail 작동여부 확인
	printList(&myList);				// [200 400 100 600 500 800]
	printf("데이터 개수는 %d\n", list_length(&myList));
	list_destroy(&myList);

	
	// ※ ↓ 먼저 ArrayList 부터 한뒤에 에 그대로 복붙하여 LinkedList 진행
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
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_insert(&myList, 0, i);
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

	

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()