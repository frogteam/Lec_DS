#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "ListBaseStack.h"

int main(void)
{
	Stack stack; 
	Data data;

	stack_init(&stack); // Stack의 생성 및 초기화

	// 데이터 push
	stack_push(&stack, 1);  stack_push(&stack, 2);
	stack_push(&stack, 3);  stack_push(&stack, 4);
	stack_push(&stack, 5);

	// 데이터 pop
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data);  // 5
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data);  // 4

	while(!stack_is_empty(&stack))   // 3   2    1 
	{
		stack_pop(&stack, &data);
		printf("%d ", data); 
	}

	for (int i = 100; i <= 1000; i += 100) {
		stack_push(&stack, i);
	}

	while (!stack_is_empty(&stack))  // 1000 900 ... 100
	{
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	stack_destroy(&stack);  // 스택 제거

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}