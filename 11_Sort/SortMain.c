#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
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
	genRandom(srcArr, LEN, LEN);  // ������

	//genIncArr(srcArr, LEN);     // �������� 
	//genDecSorted(srcArr, LEN);  // ��������
	//printArr(srcArr, LEN);

	int workArr[LEN];

	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//chkTimeLap(BubbleSort, workArr, LEN, "��������");
	//printArr(workArr, LEN);

	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//chkTimeLap(SelectionSort, workArr, LEN, "��������");
	//printArr(workArr, LEN);

	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//chkTimeLap(InsertionSort, workArr, LEN, "��������");
	//printArr(workArr, LEN);


	//memcpy(workArr, srcArr, sizeof(int) * LEN);
	//Heap hp;
	//heap_init(&hp, LEN);
	//chkTimeLap(HeapSort, workArr, LEN, "�� ����");
	//heap_destroy(&hp);
	//printArr(workArr, LEN);

	// �� ���� (Quick Sort)
	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(QuickSortMain, workArr, LEN, "�� ����");
	//printArr(workArr, LEN);

	// �Ʒ��� LEN 3000 ������ ����.  Ŀ���� ���ȣ�� �ϴ� �״´�.
	genIncSorted(workArr, LEN);  // �̹� �������� ���� �迭
	chkTimeLap(QuickSortMain, workArr, LEN, "��-��������");  // ���ȣ�� �ϴ� �״´�..


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




