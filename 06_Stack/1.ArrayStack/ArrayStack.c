#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#include "ArrayStack.h"

// ���� �ʱ�ȭ
void stack_init(Stack * pStack)
{
	pStack->topIndex = -1;   // �ʱⰪ�� -1.  (�� ������ index++ �׸��� ���� data ����)
	printf("���� �ʱ�ȭ\n");
}

// ���� ����
void stack_destroy(Stack* pStack)
{
	printf("���� ����\n");
}

// ���� ����
int stack_empty(Stack * pStack)
{
	printf("���� ����\n");
}

void stack_push(Stack * pStack, Data data);
Data stack_pop(Stack * pStack);
Data stack_peek(Stack * pStack);






