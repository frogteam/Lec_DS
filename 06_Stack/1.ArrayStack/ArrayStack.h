#pragma once

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void stack_init(Stack * pStack);   // 스택 초기화
void stack_destroy(Stack* pStack);   // 스택 제거
int stack_empty(Stack * pStack);    // 스택 비우기

void stack_push(Stack * pStack, Data data);
Data stack_pop(Stack * pStack);
Data stack_peek(Stack * pStack);

