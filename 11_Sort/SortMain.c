#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

#define DATA_SIZE  40000

#include "Sort.h"
#include "Heap.h"
#include "QuickSort.h"
/**

**/



int main(int argc, char** argv)
{
	int length; 

	//printf("BubbleSort 동작\n");
	//{
	//	int data[] = { 3, 2, 7, 5, 1 };
	//	length = sizeof(data) / sizeof(int);
	//	BubbleSort(data, length);
	//	printArr(data, length);
	//}
	//{ 
	//	int data[] = { 11, 3, 28, 43, 9, 4 };
	//	length = sizeof(data) / sizeof(int);
	//	BubbleSort(data, 6);
	//	printArr(data, 6);
	//}

	//printf("\nSelectionSort 동작\n");
	//{
	//	int data[] = { 29, 10, 14, 37, 13 };
	//	length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, length);
	//	printArr(data, length);
	//}
	//{
	//	int data[] = { 11, 3, 28, 43, 9, 4 };
	//	length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, 6);
	//	printArr(data, 6);
	//}

	//printf("\nInsertionSort 동작\n");
	//{
	//	int data[] = { 29, 10, 14, 37, 13 };
	//	length = sizeof(data) / sizeof(int);
	//	InsertionSort(data, length);
	//	printArr(data, length);
	//}
	//{
	//	int data[] = { 11, 3, 28, 43, 9, 4 };
	//	length = sizeof(data) / sizeof(int);
	//	InsertionSort(data, 6);
	//	printArr(data, 6);
	//}

	//------------------------------------------------
	//{   // 우선 도우미 함수 동작 확인 , 일단 DATA_SIZE 는 10 정도로 테스트
	//	int srcArr[DATA_SIZE];
	//	genRandom(srcArr, DATA_SIZE);
	//	printArr(srcArr, DATA_SIZE);
	//	genIncSorted(srcArr, DATA_SIZE);
	//	printArr(srcArr, DATA_SIZE);
	//	genDecSorted(srcArr, DATA_SIZE);
	//	printArr(srcArr, DATA_SIZE);
	//}

	//-------------------------------------------------
	//printf("\nTime Complexity\n");
	//{
	//	int srcArr[DATA_SIZE];  // DATA_SIZE 를 20000, 40000 .. 테스트 해보자.
	//	genRandom(srcArr, DATA_SIZE);  // 랜덤으로 생성
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);  // workArr <- srcArr 배열 복사
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	//}


	//-------------------------------------------------
	//printf("\nWORST vs BEST case\n");
	//{
	//	// 랜덤 배열
	//	int srcArr[DATA_SIZE];   // 일단 20000
	//	genRandom(srcArr, DATA_SIZE);  // #1 램덤
	//	//genIncSorted(srcArr, DATA_SIZE);     // #2 오름차순 이미 정렬된 배열
	//	//genDecSorted(srcArr, DATA_SIZE);  // #3 내림차순 역정렬된 배열
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");  // 램덤, 오름, 역정렬

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	//}

	printf("HeapSort 동작\n");
	{
		int data[] = { 3, 2, 7, 5, 1 };
		length = sizeof(data) / sizeof(int);

		Heap hp;
		heap_init(&hp, length);

		HeapSort(data, length);
		printArr(data, length);   // 1, 2, 3, 5, 7

		heap_destroy(&hp);
	}


	//printf("\nHeapSort\n");
	//{
	//	int srcArr[DATA_SIZE];  // (※동작테스트는 DATA_SIZE 10 으로 하자)
	//	genRandom(srcArr, DATA_SIZE);

	//	int workArr[DATA_SIZE];
	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

	//	Heap hp;
	//	heap_init(&hp, DATA_SIZE);

	//	//printArr(workArr, DATA_SIZE); // 정렬전  

	//	chkTimeLap(HeapSort, workArr, DATA_SIZE, "힙정렬");

	//	//printArr(workArr, DATA_SIZE); // 정렬후

	//	heap_destroy(&hp);
	//}

	//printf("\n퀵소트 동작 확인\n");
	//{
	//	int arr[] = { 40, 50, -30, -11, -333, 349, 23};
	//	int len = sizeof(arr) / sizeof(int);

	//	printArr(arr, len);  // 퀵정렬 전
	//	QuickSort(arr, 0, len - 1);
	//	printArr(arr, len);  // 퀵정렬 후
	//}

	// 퀵 정렬 (Quick Sort)
	printf("\nQuickSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		//printArr(workArr, DATA_SIZE);  // ※ 동작확인은 DATA_SIZE 10
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬 랜덤");  // 성능확인은 20000, 40000
		//printArr(workArr, DATA_SIZE);

		
		// 아래는 DATA_SIZE 3000 정도로 하자.  커지면 재귀호출 하다 죽는다.
		//genIncSorted(workArr, DATA_SIZE);  // 이미 오름차순 정렬 배열
		//chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵-오름차순");  // 재귀호출 하다 죽는다..

		// ※ 프로젝트 속성 - 링커 - 시스템 - 스택예약크기 => 4194304 (4M)
		// 위와 같이 하면 DATA_SIZE 10000 동작 가능
	}



	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()

  /*
  버블정렬 (size: 20000) 수행결과: 829 ms
  선택정렬 (size: 20000) 수행결과: 383 ms
  삽입정렬 (size: 20000) 수행결과: 178 ms

  버블정렬 (size: 40000) 수행결과: 3424 ms
  선택정렬 (size: 40000) 수행결과: 1520 ms
  삽입정렬 (size: 40000) 수행결과: 650 ms

  버블정렬 (size: 80000) 수행결과: 12992 ms
  선택정렬 (size: 80000) 수행결과: 6117 ms
  삽입정렬 (size: 80000) 수행결과: 1964 ms

  --------------------------------------
  WORST vs. BEST case
  버블랜덤 (size: 20000) 수행결과: 834 ms
  선택랜덤 (size: 20000) 수행결과: 378 ms
  삽입랜덤 (size: 20000) 수행결과: 174 ms

  버블오름 (size: 20000) 수행결과: 439 ms
  선택오름 (size: 20000) 수행결과: 387 ms
  삽입오름 (size: 20000) 수행결과: 0 ms

  버블역정렬 (size: 20000) 수행결과: 607 ms
  선택역정렬 (size: 20000) 수행결과: 346 ms
  삽입역정렬 (size: 20000) 수행결과: 396 ms

  HeapSort
  힙정렬 (size: 20000) 수행결과: 6 ms
  힙정렬 (size: 40000) 수행결과: 13 ms
  힙정렬 (size: 80000) 수행결과: 26 ms

  QuickSort
  퀵정렬 랜덤 (size: 20000) 수행결과: 3 ms
  퀵정렬 랜덤 (size: 40000) 수행결과: 8 ms
  퀵정렬 랜덤 (size: 80000) 수행결과: 16 ms

  QuickSort : BEST vs. WORST.
  퀵정렬 랜덤 (size: 3000) 수행결과: 1 ms
  퀵-오름차순 (size: 3000) 수행결과: 8 ms

  퀵정렬 랜덤 (size: 10000) 수행결과: 2 ms
  퀵-오름차순 (size: 10000) 수행결과: 96 ms

  */


