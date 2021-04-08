#include <stdio.h>
#include "QuickSort.h"

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}	


int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽! 
	int low = left + 1;   // 피벗 오른쪽부터 시작
	int high = right;      // 가장 오른쪽에서부터 시작

	while (low <= high)    // 교차되지 않을 때가지 반복하며 low, high 이동
	{
		//while (pivot > arr[low])
		//	low++;

		//while (pivot < arr[high])
		//	high--;

		// low 와 high 는 개별적으로 움직인다.

		// low 우측 이동,  pivot 보다 큰 것을 만날때까지!
		while(pivot >= arr[low] && low <= right)  
			low++;

		// high 좌측 이동, pivot 보다 작은것을 만날때까지!
		while(pivot <= arr[high] && high >= (left+1))
			high--;

		// low 와 high 가 멈추면!
		if (low <= high)  // low, high 가 교차되지 않은 상태라면  Swap 진행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환

		// 이 while 문이 돌때ㅁ다.
	}

	// '피벗'과 'high'가 가리키는 대상 교환
	Swap(arr, left, high);    
	// 이 시점에서 high 의 우측으로는 pivot 보다 큰 것들이
	// pivot 의 좌측으로는 high 보다 작은 것들이 자리잡게 된다.

	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot - 1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);    // 오른쪽 영역을 정렬
	}
}

void QuickSortMain(int arr[], int n)
{
	QuickSort(arr, 0, n - 1);
}


// 퀵정렬 동작 확인
//int main(void)
//{
////	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
//	int arr[3] = {3, 3, 3};
//
//	int len = sizeof(arr) / sizeof(int);
//
//	QuickSort(arr, 0, len - 1);
//
//	for(int i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//
//	printf("\n");
//	return 0;
//}