#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**
구조체끼리의 대입연산은?
발생하는 문제점은?
구조체 복사하려면?
구조체 멤버에 배열이 있으면?
멤버 포인터
**/


int main(int argc, char** argv)
{
	{
		// 구조체간 대입 문제
		typedef struct _Student
		{
			int age;
			char grade;
		}Student;

		Student stu1 = { 10, 'A' };   // 구조체 변수 선언과 동시에 초기화 가능.
		Student stu2 = { 23, 'B' };

		//stu1 = { 40, 'C' };  // 일단 선언된 이후에는 이런 구문 불가

		printf("stu1: %d, %c\n", stu1.age, stu1.grade);
		printf("stu2: %d, %c\n", stu2.age, stu2.grade);

		stu1 = stu2;   // 구조체끼리의 대입.  

		// 구조체끼리의 대입은 '멤버' 간 '복사' 발생
		printf("stu1: %d, %c\n", stu1.age, stu1.grade);
		printf("stu2: %d, %c\n", stu2.age, stu2.grade);

		// 사본여부 확인
		stu1.age = 50;  stu1.grade = 'D';
		printf("stu1: %d, %c\n", stu1.age, stu1.grade);
		printf("stu2: %d, %c\n", stu2.age, stu2.grade);
	}

	printf("\n");
	{
		// 구조체 멤버에 배열이 있다면?
		// 구조체 복사시 어떻게 동작하나?
		typedef struct _Student
		{
			char name[10];  // 배열  (고정크기)
			int age;
			char grade;
		}Student;

		Student stu1 = { "Choi", 19, 'A' };
		Student stu2;

		stu2 = stu1;  // 복사된다.  확인해보자

		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);   // 복사확인!
		// 무려 '배열' 멤버가 복사가 된다!?!?!

		// 정말 복사? 확인해보자
		sprintf(stu1.name, "%s", "Lee");  // stu1 만 변경
		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // stu2 는 변화없다
	}

	printf("\n");
	{
		// 주의!  구조체 멤버가 포인터라면??
		typedef struct _Student
		{
			char *name;  // 포인터다!!
			int age;
			char grade;
		}Student;


		Student stu1;
		stu1.name = (char*)malloc(sizeof(char) * 20);
		sprintf(stu1.name, "%s", "Jacob");
		stu1.age = 40;
		stu1.grade = 'F';

		Student stu2;
		
		stu2 = stu1;  // 복사된다.  확인해보자

		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);   // 복사확인!
		// 무려 '배열' 멤버가 복사가 된다!?!?!

		// 정말 복사? 확인해보자
		sprintf(stu1.name, "%s", "Lee");  // stu1 만 변경
		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // ★stu2 도 변경되었다★


		// 이유: 포인터의 복사만 발생됨.
		// 구조체에서 포인터 멤버 복사시 매우 주의 요망

		// 더 심각한건
		// stu1 을 먼저 해제한 경우
		free(stu1.name);
		
		printf("stu1.name 해체후\n");
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // 동작 보장 못함!!

		// 위와 같은 것은 얕은 복사 (shallow copy) 라고 함.
		
		// 해결하려면 깊은 복사 (deep copy) 를 해야 함
	}

	printf("\n");
	{
		// 깊은 복사 deep copy 
		// 구조체 복사가 발생할때
		// 동적메모리
		typedef struct _Student
		{
			char *name;  // 포인터다!!
			int age;
			char grade;
		}Student;

		Student stu1;
		stu1.name = (char*)malloc(sizeof(char) * 20);
		sprintf(stu1.name, "%s", "Jacob");
		stu1.age = 40;
		stu1.grade = 'F';

		Student stu2;
		// 깊은 복사
		stu2.name = (char*)malloc(sizeof(char) * 20);
		strcpy(stu2.name, stu1.name);
		stu2.age = stu1.age;
		stu2.grade = stu1.grade;

		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);   // 복사확인!
		// 무려 '배열' 멤버가 복사가 된다!?!?!

		// 정말 복사? 확인해보자
		sprintf(stu1.name, "%s", "Lee");  // stu1 만 변경
		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // stu2 는 그대로!

		free(stu1.name);
		free(stu2.name);
	}


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




