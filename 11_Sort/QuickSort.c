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
	int pivot = arr[left];    // �ǹ��� ��ġ�� ���� ����! 
	int low = left + 1;   // �ǹ� �����ʺ��� ����
	int high = right;      // ���� �����ʿ������� ����

	while (low <= high)    // �������� ���� ������ �ݺ��ϸ� low, high �̵�
	{
		//while (pivot > arr[low])
		//	low++;

		//while (pivot < arr[high])
		//	high--;

		// low �� high �� ���������� �����δ�.

		// low ���� �̵�,  pivot ���� ū ���� ����������!
		while(pivot >= arr[low] && low <= right)  
			low++;

		// high ���� �̵�, pivot ���� �������� ����������!
		while(pivot <= arr[high] && high >= (left+1))
			high--;

		// low �� high �� ���߸�!
		if (low <= high)  // low, high �� �������� ���� ���¶��  Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ

		// �� while ���� ��������.
	}

	// '�ǹ�'�� 'high'�� ����Ű�� ��� ��ȯ
	Swap(arr, left, high);    
	// �� �������� high �� �������δ� pivot ���� ū �͵���
	// pivot �� �������δ� high ���� ���� �͵��� �ڸ���� �ȴ�.

	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // �ѷ� ������ 
		QuickSort(arr, left, pivot - 1);    // ���� ������ ����
		QuickSort(arr, pivot + 1, right);    // ������ ������ ����
	}
}

void QuickSortMain(int arr[], int n)
{
	QuickSort(arr, 0, n - 1);
}


// ������ ���� Ȯ��
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