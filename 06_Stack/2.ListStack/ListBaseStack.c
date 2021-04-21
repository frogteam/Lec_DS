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

// ������ ������� Ȯ��
int stack_is_empty(Stack * pstack)
{
	if(pstack->pTop == NULL) return SUCCESS;

	return FAIL;
}

// top �� ������ �߰� (push)
int stack_push(Stack * pstack, Data data)
{
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;

	// ��带 ���ÿ� �߰�
	pNewNode->pNext = pstack->pTop;
	// top �� ������ push �� ��带 ����Ų��
	pstack->pTop = pNewNode;

	return SUCCESS;
}

int stack_pop(Stack * pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		printf("Empty Stack");
		return FAIL;
	}

	Node *pCurrent = pstack->pTop;   // ������ ��� ������ ���

	if(pData != NULL)
		*pData = pstack->pTop->data;     // ������ �б� (������)

	pstack->pTop = pstack->pTop->pNext;   // top �̵�
	
	free(pCurrent);  // pop �� ��� ����

	return SUCCESS;
}

// top �� ������ �̸����� (peek)
int stack_peek(Stack * pstack, Data *pData)
{
	if(stack_is_empty(pstack)) {
		printf("Empry Stack");
		return FAIL;
	}

	if(pData != NULL)   // �� �� �ʿ��� �Ʒ� stack_destroy���� ���ȴ�
		*pData = pstack->pTop->data;   // top �� �����͸� ����

	return SUCCESS;
}

void stack_destroy(Stack *pStack)
{
	// ������ �� ����������� pop ��Ű��
	while (!stack_is_empty(pStack))
	{
		stack_pop(pStack, NULL); 
	}
}