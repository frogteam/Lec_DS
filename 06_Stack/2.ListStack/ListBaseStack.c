#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() �� ���� C �Լ��� ���� ����
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

int stack_push(Stack * pstack, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	newNode->data = data;
	newNode->pNext = pstack->pTop;

	pstack->pTop = newNode;
	return SUCCESS;
}

int stack_pop(Stack * pstack, Data *pData)
{
	Node *pCurrent;

	if(stack_is_empty(pstack)) {
		printf("Empry Stack");
		return FAIL;
	}

	if(pData != NULL)
		*pData = pstack->pTop->data;     // ������ �б�
	
	pCurrent = pstack->pTop;

	pstack->pTop = pstack->pTop->pNext;   // top �̵�
	free(pCurrent);  // pop �� ��� ����

	return SUCCESS;
}

int stack_peek(Stack * pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		printf("Empry Stack");
		return FAIL;
	}

	if(pData != NULL)
		*pData = pstack->pTop->data;   // top �� �����͸� ����

	return SUCCESS;
}

void stack_destroy(Stack *pStack)
{
	// ������ pop
	while (!stack_is_empty(pStack))
	{
		stack_pop(pStack, NULL);
	}
}