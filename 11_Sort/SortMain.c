#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
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

	//printf("BubbleSort ����\n");
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

	//printf("\nSelectionSort ����\n");
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

	//printf("\nInsertionSort ����\n");
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
	//{   // �켱 ����� �Լ� ���� Ȯ�� , �ϴ� DATA_SIZE �� 10 ������ �׽�Ʈ
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
	//	int srcArr[DATA_SIZE];  // DATA_SIZE �� 20000, 40000 .. �׽�Ʈ �غ���.
	//	genRandom(srcArr, DATA_SIZE);  // �������� ����
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);  // workArr <- srcArr �迭 ����
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	//}


	//-------------------------------------------------
	//printf("\nWORST vs BEST case\n");
	//{
	//	// ���� �迭
	//	int srcArr[DATA_SIZE];   // �ϴ� 20000
	//	genRandom(srcArr, DATA_SIZE);  // #1 ����
	//	//genIncSorted(srcArr, DATA_SIZE);     // #2 �������� �̹� ���ĵ� �迭
	//	//genDecSorted(srcArr, DATA_SIZE);  // #3 �������� �����ĵ� �迭
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");  // ����, ����, ������

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	//}

	printf("HeapSort ����\n");
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
	//	int srcArr[DATA_SIZE];  // (�ص����׽�Ʈ�� DATA_SIZE 10 ���� ����)
	//	genRandom(srcArr, DATA_SIZE);

	//	int workArr[DATA_SIZE];
	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

	//	Heap hp;
	//	heap_init(&hp, DATA_SIZE);

	//	//printArr(workArr, DATA_SIZE); // ������  

	//	chkTimeLap(HeapSort, workArr, DATA_SIZE, "������");

	//	//printArr(workArr, DATA_SIZE); // ������

	//	heap_destroy(&hp);
	//}

	//printf("\n����Ʈ ���� Ȯ��\n");
	//{
	//	int arr[] = { 40, 50, -30, -11, -333, 349, 23};
	//	int len = sizeof(arr) / sizeof(int);

	//	printArr(arr, len);  // ������ ��
	//	QuickSort(arr, 0, len - 1);
	//	printArr(arr, len);  // ������ ��
	//}

	// �� ���� (Quick Sort)
	printf("\nQuickSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		//printArr(workArr, DATA_SIZE);  // �� ����Ȯ���� DATA_SIZE 10
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������ ����");  // ����Ȯ���� 20000, 40000
		//printArr(workArr, DATA_SIZE);

		
		// �Ʒ��� DATA_SIZE 3000 ������ ����.  Ŀ���� ���ȣ�� �ϴ� �״´�.
		//genIncSorted(workArr, DATA_SIZE);  // �̹� �������� ���� �迭
		//chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "��-��������");  // ���ȣ�� �ϴ� �״´�..

		// �� ������Ʈ �Ӽ� - ��Ŀ - �ý��� - ���ÿ���ũ�� => 4194304 (4M)
		// ���� ���� �ϸ� DATA_SIZE 10000 ���� ����
	}



	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()

  /*
  �������� (size: 20000) ������: 829 ms
  �������� (size: 20000) ������: 383 ms
  �������� (size: 20000) ������: 178 ms

  �������� (size: 40000) ������: 3424 ms
  �������� (size: 40000) ������: 1520 ms
  �������� (size: 40000) ������: 650 ms

  �������� (size: 80000) ������: 12992 ms
  �������� (size: 80000) ������: 6117 ms
  �������� (size: 80000) ������: 1964 ms

  --------------------------------------
  WORST vs. BEST case
  ������ (size: 20000) ������: 834 ms
  ���÷��� (size: 20000) ������: 378 ms
  ���Է��� (size: 20000) ������: 174 ms

  ������� (size: 20000) ������: 439 ms
  ���ÿ��� (size: 20000) ������: 387 ms
  ���Կ��� (size: 20000) ������: 0 ms

  �������� (size: 20000) ������: 607 ms
  ���ÿ����� (size: 20000) ������: 346 ms
  ���Կ����� (size: 20000) ������: 396 ms

  HeapSort
  ������ (size: 20000) ������: 6 ms
  ������ (size: 40000) ������: 13 ms
  ������ (size: 80000) ������: 26 ms

  QuickSort
  ������ ���� (size: 20000) ������: 3 ms
  ������ ���� (size: 40000) ������: 8 ms
  ������ ���� (size: 80000) ������: 16 ms

  QuickSort : BEST vs. WORST.
  ������ ���� (size: 3000) ������: 1 ms
  ��-�������� (size: 3000) ������: 8 ms

  ������ ���� (size: 10000) ������: 2 ms
  ��-�������� (size: 10000) ������: 96 ms

  */


