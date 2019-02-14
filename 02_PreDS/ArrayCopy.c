#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#pragma warning(disable:4477)   // unsigned <--> signed 관련 warning 

void printArr(int *arr, int length)
{
	int i;
	printf("[");
	for (i = 0; i < length; i++)
	{
		printf("%d,", arr[i]);
	}
	printf("]\n");
}

int main()
{
	{
		// 배열의 복사?
		int arr1[3] = { 10, 20, 30 };
		int arr2[3];
		int len = 3;

		// arr2 = arr1;   // 불가!!!   배열변수는 포인터 상수다!
							// arr2 자체를 못바꾼다.
		
		// 방법1 : for문
		int i;
		for (i = 0; i < len; i++)
			arr2[i] = arr1[i];

		printArr(arr2, len);


		// 방법2 : memcpy
		memcpy(arr2, arr1, sizeof(arr1));
		printArr(arr2, len);


		
	}

	{
		// memcpy() 가 for 보다 성능히 훨씬 앞선다.

		int len = 10000;   // 10000 개짜리 int[] 배열 생성
		int *arr1 = (int*)malloc(sizeof(int) *  len);
		int *arr2 = (int*)malloc(sizeof(int) *  len);

		int i, cnt, loop = 100000;
		clock_t start, end;

		printf("clock() for 측정시작\n");
		start = clock(); //시간 측정 시작
		for (cnt = 0; cnt < loop; cnt++)
		{
			for (i = 0; i < len; i++)
				arr2[i] = arr1[i];
		}
		end = clock(); //시간 측정 끝
		printf("%ld ms\n", end - start);


		printf("clock() memcpy 측정시작\n");
		start = clock(); //시간 측정 시작
		for (cnt = 0; cnt < loop; cnt++)
		{
			memcpy(arr2, arr1, sizeof(int) * len);
		}
		end = clock(); //시간 측정 끝
		printf("%ld ms\n", end - start);

	}

	{
		// 문자열 - 배열 복사
		char *szName = "Hello World";
		char arrName[20];
		char arrName2[20];

		// arrName = szName   // 당연히 안된다.

		// 방법1 : 문자열 함수 사용
		strcpy(arrName, szName);
		printf("%s\n", arrName);

		// 방법2 : memcpy 가능
		memcpy(arrName2, szName, strlen(szName) + 1);  //  \0 문자 잊지 않길
		printf("%s\n", arrName2);

	}

	printf("\n");
	{
		// 문자열 복사에서는 
		// memcpy 와 strcpy 는 성능이 비슷한듯.   (물론 for 보다는 압도적으로 빠름)
		char str1[20] = "Hello World";
		char str2[20];

		int i, cnt, loop = 100000000;
		clock_t start, end;
		int strLen = strlen(str1);

		printf("clock() strcpy 측정시작\n");
		start = clock(); //시간 측정 시작
		for (cnt = 0; cnt < loop; cnt++)
		{
			strcpy(str2, str1);
		}
		end = clock(); //시간 측정 끝
		printf("%ld ms\n", end - start);


		printf("clock() memcpy 측정시작\n");
		start = clock(); //시간 측정 시작
		for (cnt = 0; cnt < loop; cnt++)
		{
			memcpy(str2, str1, strLen + 1);
		}
		end = clock(); //시간 측정 끝
		printf("%ld ms\n", end - start);



	}


}