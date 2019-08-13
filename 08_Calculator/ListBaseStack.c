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

int stack_push(Stack * pstack, Data *pData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->str = (char*)malloc(strlen(pData) + 1);  // ��
	strcpy(newNode->str, pData); // ���ڿ� ���� ��

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
		strcpy(pData, pStack->pTop->str);  // ��

	pCurrent = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;   // top �̵�
	
	free(pCurrent->str);   // data ����   ��
	free(pCurrent);  // pop �� ��� ����

	return SUCCESS;
}

int stack_peek(Stack *pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		//printf("peek:Empty Stack");  // ��
		return FAIL;
	}

	//*pData = pstack->pTop->str;   // top �� �����͸� ����
	if (pData != NULL)
		strcpy(pData, pstack->pTop->str);  // ��

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