#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

void Swap(int arr[], int idx1, int idx2);  // 배열 두개값 바꾸기
int Partition(int arr[], int left, int right); // 배열 정렬영역 쪼개기 (쪼갤 index 리턴)
void QuickSort(int arr[], int left, int right);  // 재귀적으로 퀵정렬 수행

void QuickSortMain(int arr[], int n);  // main() 에서 호출할 것


#endif
