#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() �� ���� C �Լ��� ���� ����
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	heap_init(&heap);

	heap_insert(&heap, 'A', 1);
	heap_insert(&heap, 'B', 2);
	heap_insert(&heap, 'C', 3);
	printf("%c \n", heap_delete(&heap));

	heap_insert(&heap, 'A', 1);
	heap_insert(&heap, 'B', 2);
	heap_insert(&heap, 'C', 3);
	printf("%c \n", heap_delete(&heap));

	while(!heap_is_empty(&heap))
		printf("%c \n", heap_delete(&heap));

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}
