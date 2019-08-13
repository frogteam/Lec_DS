#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#include "Sort.h"

void printArr(int arr[], int n)
{
	printf("[");
	int i;
	for (i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n");  // backspace
}

void genRandom(int arr[], int n, int bound)
{
	// 무작위 정수
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		//arr[i] = getRandomInt(bound);
		arr[i] = rand() % bound + 1;
	}
}

void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}
void genDecSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
}



// 시간 체크
void chkTimeLap(fnSort sort, int arr[], int n, char *title)
{
	clock_t start, end;
	start = clock(); //시간 측정 시작
	sort(arr, n);  // 정렬 수행
	end = clock(); 
	printf("%s (size: %d) 수행결과 : %ld ms\n", title, n, end - start);
}


//---------------------------------------------------
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++)   // 처음에는 n-1번 비교,  그 다음부터 n-2, n-3 ... 1 번 비교
	{
		for (j = 0; j < (n - i) - 1; j++)   // for 안의 for .. O(n제곱) 이다 
		{
			// 인접한 두개 비교
			if (arr[j] > arr[j + 1])  // 크기가 반대라면 
			{                         // 교환(swap)
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//---------------------------------------
void SelectionSort(int arr[], int n)
{
	int L, j;
	int X;
	int temp;

	for (L = 0; L < n - 1; L++)  // L : 0 부터 N-2 까지
	{
		X = L;    // 정렬 순서상 가장 앞서는 데이터의 index

		// [L...n−1] 범위에서 ‘가장 작은 값의 위치 X ‘ 를 찾는다
		for (j = L + 1; j < n; j++)   // 최소값 탐색 (L 다음 부터 끝까지)
		{
			if (arr[X] > arr[j])   // 혹시 기존의 X번째 값보다 더 작은 것이 발견되었다면?
				X = j;             // X 는 이번에 발견한 더 작은 값을 가리키기!
		}
		// for 문이 끝나면
		// X 의 값은 L번째 이후의 원소 중에서 가장 작은 값을 가리키고 있을터이다.
		// 그러면 이제 L 값과 X 의 값을 교환하면 된다.
		/* 교환 */
		temp = arr[L];
		arr[L] = arr[X];
		arr[X] = temp;
	}
}


// 삽입 정렬
void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)   // i = 1부터 시작!
	{
		insData = arr[i];   // i번째 데이터는 insData에 임시 저장

		for (j = i - 1; j >= 0; j--)  // i 왼쪽부터 왼쪽으로 검색
		{
			if (arr[j] > insData)   // insData 보다  j번째 데이터가 크면
				arr[j + 1] = arr[j];    // j번째 데이터를 우측으로 이동
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}

		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입!
	}
}
