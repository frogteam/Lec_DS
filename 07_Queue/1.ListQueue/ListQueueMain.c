#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() �� ���� C �Լ��� ���� ����
#pragma warning(disable:4477)  // unsigned �� signed  ���� �����޼��� ����

#include "ListQueue.h"

int main(void)
{
	// Queue�� ���� �� �ʱ�ȭ
	Queue q;
	Data data;
	queue_init(&q);  // ť �ʱ�ȭ

	// ������ �ֱ� enqueue
	queue_enq(&q, 1);  queue_enq(&q, 2);
	queue_enq(&q, 3);  queue_enq(&q, 4);
	queue_enq(&q, 5);
	// front --> [1->2->3->4->5] <-- back


	// ������ ������ dequeue
	while (!queue_is_empty(&q))
	{
		queue_deq(&q, &data);
		printf("deq --> %d\n", data); // ���  1 2 3 4 5 ����
	}

	queue_destroy(&q);  // ť ����

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}