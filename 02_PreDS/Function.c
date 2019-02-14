#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**

**/

void incValue(int v)  // Call By Value
{
	v++;
	printf("incValue 호출: %d\n", v);
}

void incValue2(int *p)
{
	(*p)++;
	printf("incValue2 호출: %d\n", *p);
}

// 배열 매개변수
void incArray(int* arr, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		arr[i]++;
	}
}

// 배열을 리턴 (지역변수)
int* createArray(int n)
{
	int arr[3] = { n * 1, n * 10, n * 100 };
	return arr;
}

// 동적할당된 배열 리턴
int* createArray2(int n)
{
	int* arr = (int*)malloc(sizeof(int) * 3); 
	arr[0] = n + 1;
	arr[1] = n + 10;
	arr[2] = n + 100;
	return arr;
}


int main(int argc, char** argv)
{
	{
		// Call By Value  : 호출에 있어 원본 변화 안함
		int a = 100;
		incValue(a);    
		printf("함수 호출후 : %d\n", a);  // 변경 안됨


		// Call By Reference : 호출에 있어 원본 변화 가능
		int b = 300;
		incValue2(&b);
		printf("함수 호출후 : %d\n", b);  // 변경 됨

		// C 언어에서 매개변수를 '포인터' 로 넘겨주면 Call By Reference  (즉, 호출측 원본 변화 가능)
	}

	printf("\n");
	{
		// 배열 이름은 포인터다.   그러니까, 배열을 매개변수로 넘겨줌은 포인터, 즉 Call By Reference

		int arr[3] = { 10, 20, 30 };   // 배열 이름은 포인터다!
		incArray(arr, 2);   // 앞의 두개만 1증가,  

		// 함수 호출후 원본값은? 
		int i;
		for (i = 0; i < 3; i++) {
			printf("%d ", arr[i]);      // 원본 변경되어 있다 --> Call By Reference
		}
		printf("\n");  
	}

	// 배열을 리턴하는 경우, 포인터를 리턴하는 경우. 주의
	printf("\n");
	{
		int* arr = createArray(3);

		printf("%d %d %d\n", arr[0], arr[1], arr[2]);   // 매우 위험,  결과는 나올지 모르나 항상 보장되진 않는다.
													//  warning C4172: 지역 변수 또는 임시: arr의 주소를 반환하고 있습니다.


		int* arr2 = createArray2(3);
		printf("%d %d %d\n", arr2[0], arr2[1], arr2[2]);  // 결과는 안정적... 그러나...
		
		free(arr2);  // 호출한 쪽에서 책임지고 동적메모리 해제를 해주지 않으면 memory leak 발생!  <-- C 프로그래밍 어려운 점!
	}


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




