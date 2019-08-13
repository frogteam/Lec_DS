#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**
	문자열 1
**/

int main(int argc, char** argv)
{
	// 우선 용량에 대해 신경 써야 한다
	{
		char name[10] = "Kim";
		printf("name: %s\n", name);
		printf("sizeof name[10] : %d\n", sizeof(name));   // 10 이 나온다!   name은  char[] 이기 때문

		// 문자열은 기본적으로 char 의 배열이다   :  name 은 char[] 배열.  동작은 char* 상수이다.
		printf("%c, %c, %c, \n", name[0], name[4], name[5]);

		// name이 포인터이기 때문에 아래와 같은 포인터 연산 가능
		printf("%c, %c, %c, \n", *(name + 0), *(name + 4), *(name + 5));


		name[0] = 'J';  // 가능!
		printf("name: %s\n", name);

		//name = "Lee";   // 불가   name 은 char[]  즉  포인터 상수다
	}

	printf("\n");
	{
		char name[] = "Hello";   // size 6 짜리 char[] 배열 생성되어 대입
		printf("name: %s\n", name);
		printf("sizeof name[] : %d\n", sizeof(name));  // 6 이 나온다.  'H', 'e', 'l', 'l', 'o', '\0'  
		printf("%c, %c, %c, \n", name[0], name[4], name[5]);
		name[0] = 'J';  // 가능!
		printf("name: %s\n", name);
		//name = "Lee";   // 불가   name 은 char[]  즉  포인터 상수다
	}

	printf("\n");
	{
		char *name = "Lake";    // name 은 char* 즉 포인터 변수다  ,  그러나 "Lake" 는 상수 영역애 생성
		printf("name: %s\n", name);
		printf("sizeof *name : %d\n", sizeof(name));  // 4 다!     왜 ?  name 은 char* 이기 때문
		printf("%c, %c, %c, \n", name[0], name[2], name[4]);
		//name[0] = 'J';  // 불가!   상수영역이라 건드릴수 없다.
		//printf("name: %s\n", name);

		name = "Lee";   // 가능!!!
		printf("name: %s\n", name);
	}

	printf("\n");
	{
		// 기본 문자열 함수

		// strlen()
		char name1[10] = "man";
		printf("strlen(name1): %d\n", strlen(name1));    // 절대로 sizeof() 로 문자열 길이 측정 말기!

		//name1[3] = 'o';   // 끝에다 'o';
		//printf("strlen : %d\n", strlen(name1));  // 과연?

		char name2[10] = "This is SPARTA!!";   // VS 에서는 warning 띄어줌.
		printf("strlen(name2) : %d\n", strlen(name2));   // 장담 못함
		printf("name2 : %s\n", name2);

	}

	printf("\n");
	{
		// strcpy()
		char name1[10] = "man";
		char name2[10];
		strcpy(name2, name1);  // name2 <-- name1
		printf("name2 : %s\n", name2);    // 몇 byte 가 copy 되었나?


		// 실수 가능성1!
		char *title1 = "Gozilla";
		char *title2;
		//strcpy(title2, title1);   // 헉!!!!  에러는 아니나.  예외 발생.  title2 값이 무슨주소인줄 알고??
		//printf("title2: %s\n", title2);     // 

		// 실수 가능성2
		title2 = "King Kong";
		//strcpy(title2, title1);     // 에러는 아니나.  동작은?  사실상 에러.   상수 영역을 건드림
		//printf("title2: %s\n", title2);     // 

		// strcpy 할시
		// 복사 받는 쪽 (destination) 이 
		// 메모리 영역이 확실히 할당된 상태에서 할것!!
		// ex) 배열, 동적메모리

		title2 = (char*)malloc(20);
		strcpy(title2, title1);
		printf("title2: %s\n", title2);
		free(title2); title2 = NULL;  // 동적 메모리 할당은 반드시 나중에 할당해체 하기.
	}

	printf("\n");
	{
		// strcmp()
		// 같으면 0,

		char* str1 = "abc";
		char* str2 = "abc";

		printf("strcmp() : %d\n", strcmp(str1, str2));  // 0

		str2 = "def";
		printf("strcmp() : %d\n", strcmp(str1, str2));  // -1      "abc" < "def"

		str2 = "aaa";
		printf("strcmp() : %d\n", strcmp(str1, str2));   // 1      "abc" > "aaa"

		str2 = "ABC"; // 과연?
		printf("strcmp() : %d\n", strcmp(str1, str2));   // 1       "abc" > "ABC"  대문자보다 소문자가 훨씬 뒤에 있다.

		printf("a:%d, A:%d\n", 'a', 'A');
	}



	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




