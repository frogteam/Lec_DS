#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#include "ArrayStack.h"

// 스택 초기화
void stack_init(Stack * pStack)
{
	pStack->topIndex = -1;   // 초기값은 -1.  (즉 증가는 index++ 그리고 나서 data 겠죠)
	printf("스택 초기화\n");
}

// 스택 제거
void stack_destroy(Stack* pStack)
{
	printf("스택 제거\n");
}

// 스택 비우기
int stack_empty(Stack * pStack)
{
	printf("스택 비우기\n");
}

void stack_push(Stack * pStack, Data data);
Data stack_pop(Stack * pStack);
Data stack_peek(Stack * pStack);






