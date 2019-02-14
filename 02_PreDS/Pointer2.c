#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#pragma warning(disable:4477)   // unsigned <--> signed 관련 warning 

int main()
{
	// 포인터와 배열
	{
		int arr[] = { 10, 20, 30 };
		printf("arr[0] : %d\n", arr[0]);
		printf("arr[0] : %d\n", arr[1]);

		printf("arr: %p\n", arr);
		//printf("&arr: %p\n", &arr);    // arr 값과 &arr 은 같다!!!
		//printf("&&arr: %p\n", &(&arr));  // 불가ㄹ
		printf("arr + 1 : %p\n", arr + 1);    // +4 증가    int* 이기 때문

		printf("*arr: %d\n", *arr);
		printf("*(arr + 1) : %d\n", *(arr + 1));

		// 배열 첨자 연산은 곧 포인터 연산으로 수행됨!!
		// 공식:  arr[n] <=> *(arr + n)
	}

	// 포인터 연산 +, -
	{
		short arr[] = { 10, 20, 30 };

		short *p = arr;

		printf("p : %p\n", p);
		printf("p + 1 : %p\n", p + 1);  // +2 증가

		// TODO 
		// p 를 사용하여 
		// arr 의 [2] 번째 원소 값을 50 으로 바꾸기
		// printf("arr[2] : %d\n", arr[2]); --> 50
		*(p + 2) = 50;
		p[2] = 50;   // 이렇게 해도 된다
		printf("arr[2] : %d\n", arr[2]);

	}

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;

}