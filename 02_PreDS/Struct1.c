#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**
	구조체
**/

int main(int argc, char** argv)
{
	{
		struct Student
		{
			int age;
			char gender;
		};

		struct Student stu1;

		// 구조체 멤버 접근  :  멤버접근연산자 (memeber access operator) .(dot) 사용
		stu1.age = 10;
		stu1.gender = 'F';


		// 구조체 포인터
		struct Student *pStu;
		pStu = &stu1;

		// 구조페 포인터로 멤버 접근 : -> (arrow operator) 사용
		pStu->age = 10;
		pStu->gender = 'M';

		printf("%d, %d\n", stu1.age, stu1.gender);
		printf("%d, %d\n", pStu->age, pStu->gender);
	}

	// 구조체의 '정의'도 블럭 안에서 소멸된다
	//struct Student stu2;   // 에러    


	{
		// 구조체의 size (byte) 주의

		typedef struct _Student
		{
			int age;
			char gender;
		} Student;

		Student stu1;   // typedef 로 사용하면 편리

		// 명심 size	
		printf("size fo Student = %d\n", sizeof(stu1));     // 과연 5 byte 일까?
	}
	
	//Student stu2;    // typedef 도 정의해 놓은 블럭 내에서만 유효하다

	{
		// 구조체 에 적용되는 byte padding
		// 구조체 멤버에
		// [ 4 ] [ 4 ]
		struct Student
		{
			// 아래는 8byte  (
			/*
			char grade;
			char gender;
			int age;
			*/

			// 요거는 12byte
			char grade;
			int age;
			char gender;
		};
		
		struct Student stu1;
		printf("size fo Student = %d\n", sizeof(stu1));
	}
	

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




