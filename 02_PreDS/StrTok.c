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
	printf("\n");
	{
		// '문자' 를 기준으로 '문자열' 자르기
		char str[40] = "This is C ds";
		printf("str[] = %s\n", str);


		char *delim = " ";   // delimeter 구분자
								// 안에 있는 글자 하나하나로 구분자 매칭됨.

		char *ptr = strtok(str, delim);   // " ", " i" 등으로 시도해보자
		// strtok(대상문자열, 기준문자);
		// 자른 문자열을 반환, 더 이상 자를 문자열이 없으면 NULL을 반환


		while (ptr != NULL)
		{
			printf("%s\n", ptr);
			ptr = strtok(NULL, delim);
			// 첫번째 매개변수 NULL 이면, '다음 문자열' 잘라서 포인터 리턴
			// 정확히는
			// NULL을 넣었을 때는 직전 strtok 함수에서 처리했던 문자열에서 
			// 잘린 문자열만큼 다음 문자로 '이동'한 뒤 다음 문자열을 자릅니다

			// '이동' 하고 그곳에 NULL 이 대입됨

		// ※ 만약 strtok(str, delim): 하면... 무한반복.
		}


		// 주의!!
		// 원본의 변화 생김
		printf("strtok() 후 str[] = %s\n", str);

	}

	printf("\n");
	{
		char str[40] = "10-20/100+1";
				//"10 + 20 * 100"
				// "10-20/100+1"    // 음.. 안돼.. 피연산자까지 토큰으로 나오려면?
		char *delim = "+-*/ ";
		char *ptr = strtok(str, delim);

		while (ptr != NULL)
		{
			printf("%s\n", ptr);
			ptr = strtok(NULL, delim);
		}
	}

	printf("\nstrspan()---------------------------\n");
	// https://en.cppreference.com/w/cpp/string/byte/strspn
	{
		char* str = "   hello world, friend of mine!";
		char* delim = " ,!";
		// ↓ str 문자열 '초반'에서 delim 으로만 구성되어 있는 
		// 최대 문자열 길이
		printf("%d\n", strspn(str, delim));
	}
	
	// strpbrk() 함수
	// strpbrk( const char* dest, const char* breakset );
	// string point break set ?
	// https://en.cppreference.com/w/cpp/string/byte/strpbrk
	printf("\nstrpbrk()---------------------------\n");
	{
		char* str = "hello   world, friend of mine!";
		char* delim = " ,!";

		unsigned int cnt = 0;

		// str 로부터 시작하여 delim 에 해당하는 
		// '첫위치;를 발견하여 해당위치 주소 리턴.
		// 없으면 NULL 리턴
		//printf("%s\n", strpbrk(str, delim)); // find separator
		//printf("%s\n", strpbrk(str, delim)); // find separator

		do {
			str = strpbrk(str, delim); // find separator
			//quoted(str) << '\n';
			if (str)
			{
				cnt++;
				printf("%d: %s\n", cnt, str);
				str += strspn(str, delim); // skip separator
			}
		} while (str && *str);

		printf("There are %d words\n", cnt);
	}


	printf("\n공백은 빼고 연산자 까지 토큰으로 분리되어 나오기---\n");
	{
		char str[40] = "++10-20.4/100*(12-30)+1";
		//"10 + 20 * 100"
		// "10-20/100+1"    // 음.. 안돼.. 피연산자까지 토큰으로 나오려면?

		// 1. 공백 구분으로 토큰 자르고
		// 2. 각 잘려진 토큰을 연산자와 피연산자 토큰으로 나누기

		char *delim = " \t";  // 공백과 탭
		char *opDelim = "+-/*(){}[]";   // 구분해야 할 연산자, 괄호
		char *sepNum = "0123456789.";
		char pBuf[10];
		int i;
		char *ptr;
		ptr = strtok(str, delim);
		while (ptr != NULL)
		{
			int n;
			printf("%s\n", ptr);  //확인용

			char *p = ptr;

			while (*p != '\0')
			{
				n = strspn(p, sepNum);    // 숫자로 시작하나?
				if (n > 0)
				{
					strncpy(pBuf, p, n);
					pBuf[n] = '\0';
					printf("%s\n", pBuf);
					p += n;
				}
				n = strspn(p, opDelim);    // 연산자로 시작하나?
				if (n > 0)
				{
					for (i = 0; i < n; i++)
					{
						sprintf(pBuf, "%c", p[i]);
						printf("%s\n", pBuf);
					}
					p += n;
				}
			} // end while



			ptr = strtok(NULL, delim);  // 다음 토큰
		} // end while (공백 구분 토큰)
	}

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




