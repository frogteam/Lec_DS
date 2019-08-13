#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "ListBaseStack.h"

void stack_init(Stack * pstack)
{
	pstack->pTop = NULL;
}

int stack_is_empty(Stack * pstack)
{
	if(pstack->pTop == NULL)
		return SUCCESS;
	else
		return FAIL;
}

int stack_push(Stack * pstack, Data *pData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->str = (char*)malloc(strlen(pData) + 1);  // ★
	strcpy(newNode->str, pData); // 문자열 복사 ★

	newNode->pNext = pstack->pTop;

	pstack->pTop = newNode;
	return SUCCESS;
}

int stack_pop(Stack * pStack, Data *pData)
{
	Node *pCurrent;

	if(stack_is_empty(pStack)) {
		printf("pop:Empty Stack");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pStack->pTop->str);  // ★

	pCurrent = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;   // top 이동
	
	free(pCurrent->str);   // data 제거   ★
	free(pCurrent);  // pop 된 노드 제거

	return SUCCESS;
}

int stack_peek(Stack *pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		//printf("peek:Empty Stack");  // ★
		return FAIL;
	}

	//*pData = pstack->pTop->str;   // top 의 데이터만 리턴
	if (pData != NULL)
		strcpy(pData, pstack->pTop->str);  // ★

	return SUCCESS;
}

void stack_destroy(Stack *pStack)
{
	// 데이터 pop
	while (!stack_is_empty(pStack))
	{
		stack_pop(pStack, NULL);
	}
}