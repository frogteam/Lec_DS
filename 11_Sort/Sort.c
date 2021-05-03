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

// 1 ~ bound 사이의 무작위 정수 n개 
void genRandom(int arr[], int n, int bound)
{
	// 무작위 정수
	//srand(time(NULL));
	//for (int i = 0; i < n; i++)
	//{
	//	//arr[i] = getRandomInt(bound);
	//	arr[i] = rand() % bound + 1;
	//}

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	
	shuffleArr(arr, n);
}

// 오름차순 배열 1 ~ n
void genIncSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
}

// 내림차순 배열 n ~ 1
void genDecSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
}

// 배열 섞기
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1)  // 배열길이 2개 이상인 경우만 shuffle
	{
		for (int i = 0; i < n - 1; i++)
		{
			// i 와 임의의 i오른쪽의 j번째와 swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}


// 시간 체크
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle)
{
	clock_t start, end;
	start = clock(); //시간 측정 시작
	sort(arr, n);  // 정렬 수행
	end = clock(); 
	printf("%s (size: %d) 수행결과 : %ld ms\n", szTitle, n, end - start);
}


//---------------------------------------------------
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++)   // cycle 회전 횟수. 처음에는 n-1번 비교,  그 다음부터 n-2, n-3 ... 1 번 비교
	{
		for (j = 0; j < (n - i) - 1; j++)   // for 안의 for .. O(n^2) 이다 
		{
			// 1. 인접한 두개 비교
			if (arr[j] > arr[j + 1])  // 2. 크기가 반대라면   << 비교 >>
			{                         // 값 교환(swap)
				temp = arr[j];       // << 이동 >>  한 사이클당 최대 (n-i) -1 번 발생
				arr[j] = arr[j + 1]; // << 이동 >>
				arr[j + 1] = temp;   // << 이동 >>
			}
		}
		// 중간과정 출력
		//printArr(arr, n);
	}
}

//---------------------------------------
void SelectionSort(int arr[], int n)
{
	int i, j;
	int min_idx;
	int temp;

	for (i = 0; i < n - 1; i++) // i 는 0 부터 N - 2 까지 사이클 진행(N - 1)번의 사이클
	{
		// i번째 우측(i + 1) 부터 시작하여 우측에서 i번째 보다 작은 것중 가장 최소값을 찾을거다.
		// 최소값의 위치(min_idx) 를 '선택'하는 것이 목표다!
		min_idx = i; 

		// [i+1 .. n-1] 범위에서 '가장 작은 값의 위치 min_idx' 를 찾는다
		for (j = i + 1; j < n; j++)   // 최소값 탐색 (i 다음 부터 끝까지)
		{
			if (arr[min_idx] > arr[j])   // 혹시 기존의 min_idx번째 값보다 더 작은 것이 발견되었다면? <<비교>>
				min_idx = j;             // min_idx 는 이번에 발견한 더 작은 값으로 선택하기!
		}
		// for 문이 끝나면
		// min_idx 의 값은 i번째 이후의 원소 중에서 가장 작은 값을 가리키고 있을터이다.
		// 그러면 이제 i 값과 min_idx 의 값을 교환하면 된다.
		/* << 교환 >> */
		if (i != min_idx) {  // i 보다 작은것이 없었다면 pass
			temp = arr[i];          // << 이동 >>  <-- 1cycle 당 많아야 1회 발생
			arr[i] = arr[min_idx];  // << 이동 >>
			arr[min_idx] = temp;    // << 이동 >>
		}

		// 중간단계 출력
		//printArr(arr, n);
	}
}


// 삽입 정렬
void InsertionSort(int arr[], int n)
{
	int insData;

	for (int i = 1; i < n; i++)   // i = 1부터 시작!
	{
		insData = arr[i];   // i번째 데이터 선택(insData에 임시 저장), 나중에 INSERT 될 위치 정해지면 그 자리에 '삽입'

		int j;
		for (j = i - 1; j >= 0; j--)  // j 를 i 왼쪽부터 왼쪽으로 검색해 나감
		{
			if (arr[j] > insData)   // 삽입하려는 데이터 insData 보다  j번째 데이터가 크면 << 비교 >>
				arr[j + 1] = arr[j];    // j번째 데이터를 우측으로 한칸씩 이동 << 이동 >>
			else
				break;  // 멈춘 그곳이 삽입될 위치.  삽입위치 찾았으니 멈춤
		}

		// 결정된 j 위치의 바로 오른쪽이 삽입(INSERT) 될 위치
		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입!  << 이동 >>  1 cycle 당 1번

		//  중간과정 출력
		//printArr(arr, n);
	}
}
