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

// 스택이 비었는지 확인
int stack_is_empty(Stack * pstack)
{
	if(pstack->pTop == NULL) return SUCCESS;  // 비어있으면 '참'

	return FAIL;
}

// top 에 데이터 추가 (push)
int stack_push(Stack * pstack, Data data)
{
	// 새로운 노드 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;

	// 노드를 스택에 추가
	pNewNode->pNext = pstack->pTop;
	// top 은 새로이 push 된 노드를 가리킨다
	pstack->pTop = pNewNode;

	return SUCCESS;
}

int stack_pop(Stack * pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		printf("Empty Stack!\n");
		return FAIL;
	}

	Node *deleteNode = pstack->pTop;   // 삭제할 노드 포인터 기억

	if(pData != NULL)
		*pData = pstack->pTop->data;     // 데이터 읽기 (꺼내기)

	pstack->pTop = pstack->pTop->pNext;   // top 이동
	
	free(deleteNode);  // pop 된 노드 제거

	return SUCCESS;
}

// top 의 데이터 미리보기 (peek)
int stack_peek(Stack * pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		printf("Empty Stack!\n");
		return FAIL;
	}

	if(pData != NULL)   // ※ 꼭 필요함 아래 stack_destroy에서 사용된다
		*pData = pstack->pTop->data;   // top 의 데이터만 읽기

	return SUCCESS;
}

void stack_destroy(Stack *pStack)
{
	// 스택이 다 비어질때까지 pop 시키기
	while (!stack_is_empty(pStack))
	{
		stack_pop(pStack, NULL); 
	}
}