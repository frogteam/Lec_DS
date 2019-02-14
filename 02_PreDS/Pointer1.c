#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#pragma warning(disable:4477)   // unsigned <--> signed 관련 warning 
int main()
{
	// 주소
	{
		int n = 10;

		printf("n = %d\n", n);
		
		// 주소연산자 &
		printf("n 의 주소는 %x\n", &n);  
		printf("n 의 주소는 %p\n", &n);  // 주소연산자 &
	}

	printf("\n");

	// 주소를 담는 타입 : 포인터
	{
		int n = 100;
		int *p;   // p 는 int 타입이 아니라 int* 포인터 타입!
		//p = n;   X
		p = &n;  // 포인터는 주소를 담아야 합니다.
		printf("p = %p, &n = %p  같다 \n", p, &n);

		// 참조연산자 *
		printf("*p = %d, n = %d 같다 \n", *p, n);
	}

	printf("\n");

	// 포인터의 포인터 (이중포인터)
	{
		int n1 = 300, n2 = 500;
		int *p = &n1;
		int **pp = &p;  // int* 포인터 변수에 대한 포인터, 타입은 int**

		// QUIZ : pp 변수로 300 값을 출력해보세요
		//printf("%d", ??);
		printf("**pp = %d\n", **pp);

		// QUIZ : pp 변수를 사용하여
		// p 가 n1 이 아닌 n2 를 가리게 하기
		// 이중포인터 
		// printf("%d\n", *p);  --> 500 이 나오게 하기

		*pp = &n2;
		printf("*p = %d\n", *p);


		// QUIZ : pp 변수를 사용하여
		// n2 값을  800 으로 바꾸기
		// printf("n2 = %d\n", n2); --> 800
		
		// *pp  -> p
		// **pp -> *p
		**pp = 800;

		printf("n2 = %d\n", n2);
	}

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;


}