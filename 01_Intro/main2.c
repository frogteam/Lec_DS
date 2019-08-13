#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**

**/

int main(int argc, char** argv)
{
	{
		printf("argc = %d\n", argc);

		int i = 0;
		for (i = 0; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}

	}


	printf("%d\n", 1 - (2 + 3 + (4 - 5 * 6) * 7) + 8 * 9);
	printf("%d\n", 24 + 4 - 15 * 8 / (2 + 5 * 2 - 8) + 4);

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




