#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#include "LinkedList.h"
#include "BinarySearchTree.h"


#define DATA_SIZE 30000  

void printArr(int arr[], int n)
{
	printf("[");
	int i;
	for (i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n");  // backspace
}
void genRandom(int arr[], int n, int bound)
{
	// ������ ����
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++)
	{
		//arr[i] = getRandomInt(bound);
		arr[i] = rand() % bound + 1;
	}
}
void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}
void genDecSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
}
// �迭 ����
void shuffleArr(int arr[], int n)
{
	int i;
	if (n > 1)  // �迭���� 2�� �̻��� ��츸 shuffle
	{
		for (i = 0; i < n - 1; i++)
		{
			// i �� ������ j��°�� swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}
// �迭�� ���� list ����
void genList(List *pList, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		list_add(pList, arr[i]);
}


// �迭�� ���� BST ����
void genBST(BTreeNode **ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		bst_insert(ppRoot, arr[i]);
}

//-------------------------------------------------------------------------------
typedef void* fnSearch(void *, int);   // �˻��Լ� Ÿ��

// Ư�� data �ϳ� Ž�� : �ð� üũ
//void chkTimeLapData(fnSearch search, void *collection, int data, char *title)
//{
//	int cnt = 0;
//	clock_t start, end;
//	start = clock(); //�ð� ���� ����
//	search(collection, data);  // Ž�� ����
//	end = clock();
//	printf("%s (Ž��: %d) ������ : %ld ms\n", title, data, end - start);
//}

// collection ���� arr[] �� data���� Ž���Ͽ�
// ��� �˻� �ð��� üũ
void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title)
{
	int cnt = 0;   // Search ������ ����
	clock_t start, end;
	long duration = 0;

	// �� �������� search �� �����ջ� �ѵ� ����� ���Ѵ�.
	for (int i = 0; i < n; i++) {
		start = clock();
		if (search(collection, arr[i]) != NULL) cnt++;  // Ž������
		end = clock();
		duration += end - start;
	}
	// %.3f �Ҽ��� 3�ڸ����� ����ؾ� ������ �õ�
	printf("%s (%d/%d�� Ž��) ������: %.3f ms\n", title, cnt, n, (double)duration / n); // ��ռ���ð�
}



int main(int argc, char** argv)
{

	// �ߺ��� ���� ���� ���� �迭 ���� 
	int srcArr[DATA_SIZE];
	int workArr[DATA_SIZE];

	genIncSorted(srcArr, DATA_SIZE);

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	shuffleArr(workArr, DATA_SIZE);
	//printArr(workArr, DATA_SIZE);

	
	List list;
	list_init(&list);
	genList(&list, workArr, DATA_SIZE);  // list <- workArr
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "����ƮŽ��");
	list_destroy(&list);

	BTreeNode *pRoot;   // BST �� ��Ʈ
	bst_make_init(&pRoot);   // BST �ʱ�ȭ

	//genBST(&pRoot, srcArr, 10);  // �����׽�Ʈ, 1 ~ 10
	//BTreeNode *p = NULL;
	//for(int i = 1; i <= 10; i++)
	//	if (p = bst_search(pRoot, i)) printf("�߰� %d\n", p->data);


	genBST(&pRoot, workArr, DATA_SIZE);  // BST <- workArr
	chkTimeLapArray(bst_search, pRoot, srcArr, DATA_SIZE, "BSTŽ��");
	btree_delete(pRoot);  // binary Tree ����

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




