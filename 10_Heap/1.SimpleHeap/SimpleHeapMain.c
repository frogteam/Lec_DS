#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	heap_init(&heap);

	heap_insert(&heap, 'A', 1);
	heap_insert(&heap, 'B', 2);
	heap_insert(&heap, 'C', 3);
	printf("%c \n", heap_delete(&heap));

	heap_insert(&heap, 'A', 1);
	heap_insert(&heap, 'B', 2);
	heap_insert(&heap, 'C', 3);
	printf("%c \n", heap_delete(&heap));

	while(!heap_is_empty(&heap))
		printf("%c \n", heap_delete(&heap));

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}
