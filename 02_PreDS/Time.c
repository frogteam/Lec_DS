#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/*
	C, C++ 에서 시작 측정하기
	방법1:  time() 사용
	방법2:  clock() 사용

	C 에서 프로그램 실행 지연 시키기
		_sleep() 사용
*/
int main()
{
	// time() 함수
	{
		// 방법: time.h 의 time(NULL) 사용
		time_t start, end;
		double result;
		int i, j;
		int sum = 0;
		printf("time() 측정시작\n");
		start = time(NULL); // 시간 측정 시작

		for (i = 0; i < 100000; i++) {
			for (j = 0; j < 10000; j++) {
				sum += i * j;
			}
		}

		end = time(NULL); // 시간 측정 끝
		result = (double)(end - start);
		printf("%f s\n", result); //결과 출력
	}


	// 시간측정 : clock() 사용
	{
		// 방법2 : 
		clock_t start, end;
		long result;
		int i, j;
		int sum = 0;

		printf("clock() 측정시작\n");
		start = clock(); //시간 측정 시작

		for (i = 0; i < 100000; i++) {
			for (j = 0; j < 10000; j++) {
				sum += i * j;
			}
		}

		end = clock(); //시간 측정 끝
		result = end - start;
		printf("%ld ms\n", result);
	}


	// sleep() 주기
	{		
		clock_t start, end;
		long result;
		int sum = 0;

		printf("sleep() 측정시작\n");
		start = clock(); //시간 측정 시작

		_sleep(5000);  // 윈도우즈 에선 stdlib.h 에 정의

		end = clock(); //시간 측정 끝
		result = end - start;
		printf("%ld ms\n", result);
	}


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}
