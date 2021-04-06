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
	//	int data[] = { 3, 2, 7, 5, 6 };
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

	//-------------------------------------------------
	printf("\nTime Complexity\n");
	{
		int srcArr[DATA_SIZE];  // DATA_SIZE 를 20000, 40000 .. 테스트 해보자.
		genRandom(srcArr, DATA_SIZE, DATA_SIZE);  // 랜덤으로 생성
		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	}


	//-------------------------------------------------
	//printf("\nWORST vs BEST case\n");
	//{
	//	// 랜덤 배열
	//	int srcArr[DATA_SIZE];
	//	genRandom(srcArr, DATA_SIZE, DATA_SIZE);  // #1 램덤
	//	//genIncSorted(srcArr, DATA_SIZE);     // #2 오름차순 
	//	//genDecSorted(srcArr, DATA_SIZE);  // #3 내림차순
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	//}


	//memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//Heap hp;
	//heap_init(&hp, DATA_SIZE);
	//chkTimeLap(HeapSort, workArr, DATA_SIZE, "힙 정렬");
	//heap_destroy(&hp);
	//printArr(workArr, DATA_SIZE);

	// 퀵 정렬 (Quick Sort)
	//memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵 정렬");
	//printArr(workArr, DATA_SIZE);

	// 아래는 DATA_SIZE 3000 정도로 하자.  커지면 재귀호출 하다 죽는다.
	//genIncSorted(workArr, DATA_SIZE);  // 이미 오름차순 정렬 배열
	//chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵-오름차순");  // 재귀호출 하다 죽는다..


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




