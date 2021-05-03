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
	//	genRandom(srcArr, DATA_SIZE, DATA_SIZE);
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
	//	genRandom(srcArr, DATA_SIZE, DATA_SIZE);  // �������� ����
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
	//	int srcArr[DATA_SIZE];
	//	genRandom(srcArr, DATA_SIZE, DATA_SIZE);  // #1 ����
	//	//genIncSorted(srcArr, DATA_SIZE);     // #2 �������� �̹� ���ĵ� �迭
	//	//genDecSorted(srcArr, DATA_SIZE);  // #3 �������� �����ĵ� �迭
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	//}


	//printf("\nHeapSort\n");
	//{
	//	int srcArr[DATA_SIZE];
	//	genRandom(srcArr, DATA_SIZE, DATA_SIZE);

	//	int workArr[DATA_SIZE];
	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

	//	Heap hp;
	//	heap_init(&hp, DATA_SIZE);

	//	//printArr(workArr, DATA_SIZE); // ������  (�ص����׽�Ʈ�� DATA_SIZE 10 ���� ����)

	//	chkTimeLap(HeapSort, workArr, DATA_SIZE, "������");

	//	//printArr(workArr, DATA_SIZE); // ������

	//	heap_destroy(&hp);
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
	}



	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




