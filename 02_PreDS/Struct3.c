#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**
	매개변수 구조체?  
	무조건 포인터로!
	Call By Reference
**/

typedef struct _Node
{
	int arr[100000];
} Node;

void func1(Node node) {}   // 호출시 Node 크기 만큼의 매개변수 복사 발생

void func2(Node *pNode) {}   // 호출시 포인터 (4byte) 만큼의 복사 발생

int main(int argc, char** argv)
{
	{
		Node data;
		printf("sizeof data : %d\n", sizeof(data));    // 제법 큰 구조체

		int i, loop = 100000;
		clock_t start, end;
		

		printf("clock() func1() 측정시작\n");
		start = clock(); //시간 측정 시작
		for (i = 0; i < loop; i++)
		{
			func1(data);   // 함수호출시 구조체 매개변수의 복사(data -> node)가 발생된다.  '복사' 다
		}
		end = clock(); //시간 측정 끝
		printf("%ld ms\n", end - start);

		printf("clock() func2() 측정시작\n");
		start = clock(); //시간 측정 시작
		for (i = 0; i < loop; i++)
		{
			func2(&data);   // 함수호출시 포인터 매개변수의 복사(&data -> pNode)가 발생된다.
		}
		end = clock(); //시간 측정 끝
		printf("%ld ms\n", end - start);

	}

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




