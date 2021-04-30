#include <stdio.h>  // 표준입출력 header 
#include <stdlib.h> // malloc, rand, atoi, .. 동적메모리, 난수, 문자열 변환..
#include <string.h>  // memcpy, strcpy 메모리블럭, 문자열 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock ... 시간 날짜 함수
#pragma warning(disable:4996)  //scanf() 등 전통 C함수 에러메세지 무시
#pragma warning(disable:4477)  // unsigned ↔ signed  관련 에러메세지 무시


typedef void fnAction(int);  // 측정할 함수 타입

void chkTime(char* szTitle, fnAction action, int dataSize) {
	clock_t start, end;
	long result;

	printf("%s : size[%d] 측정시작\n", szTitle, dataSize);
	start = clock(); //시간 측정 시작

	action(dataSize);

	end = clock(); //시간 측정 끝
	result = end - start;
	printf("%s : size[%d] 경과시간 %ld ms\n", szTitle, dataSize, result);

}

void func1(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) { sum++; }
}

void func2(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) { 
		for (int j = 0; j < size; j++) {
			sum++; 
		}
	}
}

void func3(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				sum++;
			}
		}
	}
}


int main(int argc, char** argv)
{
	int size = 10000000;
	{
		size = 100000000;
		chkTime("O(n)", func1, size);
		chkTime("O(n)", func1, size * 2);
		chkTime("O(n)", func1, size * 4);
	}
	{
		size = 10000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size * 2);
		chkTime("O(n^2)", func2, size * 4);
	}
	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size * 2);
		chkTime("O(n^3)", func3, size * 4);
	}



	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()