#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#pragma warning(disable:4477)  // unsigned ↔ signed  관련 에러메세지 무시

#include "ListQueue.h"

int main(void)
{
	// Queue의 생성 및 초기화
	Queue q;
	Data data;
	queue_init(&q);  // 큐 초기화

	// 데이터 넣기 enqueue
	queue_enq(&q, 1);  queue_enq(&q, 2);
	queue_enq(&q, 3);  queue_enq(&q, 4);
	queue_enq(&q, 5);
	// front --> [1->2->3->4->5] <-- back


	// 데이터 꺼내기 dequeue
	while (!queue_is_empty(&q))
	{
		queue_deq(&q, &data);
		printf("deq --> %d\n", data); // 결과  1 2 3 4 5 순서
	}

	queue_destroy(&q);  // 큐 제거

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}