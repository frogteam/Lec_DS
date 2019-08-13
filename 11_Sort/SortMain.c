#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

#define LEN 3000

#include "Sort.h"
#include "Heap.h"
#include "QuickSort.h"
/**

**/



int main(int argc, char** argv)
{
	//int srcArr[LEN] = {10, 40, 60, 20, 30};
	
	int srcArr[LEN];
	genRandom(srcArr, LEN, LEN);  // 무작위

	//genIncArr(srcArr, LEN);     // 오름차순 
	//genDecSorted(srcArr, LEN);  // 내림차순
	//printArr(srcArr, LEN);

	int workArr[LEN];

	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//chkTimeLap(BubbleSort, workArr, LEN, "버블정렬");
	//printArr(workArr, LEN);

	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//chkTimeLap(SelectionSort, workArr, LEN, "선택정렬");
	//printArr(workArr, LEN);

	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//chkTimeLap(InsertionSort, workArr, LEN, "삽입정렬");
	//printArr(workArr, LEN);


	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//Heap hp;
	//heap_init(&hp, LEN);
	//chkTimeLap(HeapSort, workArr, LEN, "힙 정렬");
	//heap_destroy(&hp);
	//printArr(workArr, LEN);

	// 퀵 정렬 (Quick Sort)
	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(QuickSortMain, workArr, LEN, "퀵 정렬");
	//printArr(workArr, LEN);

	// 아래는 LEN 3000 정도로 하자.  커지면 재귀호출 하다 죽는다.
	genIncSorted(workArr, LEN);  // 이미 오름차순 정렬 배열
	chkTimeLap(QuickSortMain, workArr, LEN, "퀵-오름차순");  // 재귀호출 하다 죽는다..


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




