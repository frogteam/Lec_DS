#ifndef __SORT_H__
#define __SORT_H__

void printArr(int arr[], int n);
void genRandom(int arr[], int n); // 무작위 배열 1 ~ n 범위
void genIncSorted(int arr[], int n);    // 오름 차순 배열 생성 
void genDecSorted(int arr[], int n);    // 내림 차순 배열 생성										
void shuffleArr(int arr[], int n);		// 배열 섞기

//-------------------------------------------
typedef void fnSort(int arr[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle);

//-------------------------------------------
void BubbleSort(int arr[], int n);     // 버블 정렬 
void SelectionSort(int arr[], int n);   // 선택 정렬
void InsertionSort(int arr[], int n);   // 삽입 정렬

#endif
