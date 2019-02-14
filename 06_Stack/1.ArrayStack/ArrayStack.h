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

void stack_init(Stack * pStack);   // ���� �ʱ�ȭ
void stack_destroy(Stack* pStack);   // ���� ����
int stack_empty(Stack * pStack);    // ���� ����

void stack_push(Stack * pStack, Data data);
Data stack_pop(Stack * pStack);
Data stack_peek(Stack * pStack);

