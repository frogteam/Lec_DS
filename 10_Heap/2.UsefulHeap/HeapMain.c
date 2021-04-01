#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "Heap.h"

int DataPriorityComp(HData ch1, HData ch2)
{
	// max heap, min heap 이 이 함수 기능으로 바뀐다.
	return ch2-ch1;    // min-heap
//	return ch1-ch2;   // max-heap
}

int main(void)
{
	Heap heap;
	heap_init(&heap, DataPriorityComp);

	//heap_insert(&heap, 9);
	//heap_insert(&heap, 20);
	//heap_insert(&heap, 30);
	//printf("%d \n", heap_delete(&heap));

	//heap_insert(&heap, 9);
	//heap_insert(&heap, 20);
	//heap_insert(&heap, 30);

	//      (30)
	//     ↙  ↘
	//   (9)    (20)

	//printf("%d \n", heap_delete(&heap));


	heap_insert(&heap, 10);
	heap_insert(&heap, 40);
	heap_insert(&heap, 60);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	while(!heap_is_empty(&heap))
		printf("%d ", heap_delete(&heap));  // delete 되는 순서 주목
	printf("\n");

	//---------------------------------------
	printf("\n");
	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);
	heap_insert(&heap, 3);  // 추가
	heap_insert(&heap, 2);  // 어떻게 되나?
	heap_insert(&heap, 10); // 어떻게 되나?
	heap_insert(&heap, 1);  // 어떻게 되나?

	while (!heap_is_empty(&heap))
		printf("%d ", heap_delete(&heap));
	printf("\n");


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}
