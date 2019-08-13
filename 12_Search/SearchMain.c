#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#include "LinkedList.h"
#include "BinarySearchTree.h"


#define LEN 10000

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
	// 무작위 정수
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
// 배열 섞기
void shuffleArr(int arr[], int n)
{
	int i;
	if (n > 1)
	{
		for (i = 0; i < n - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
}
// 배열로 부터 list 생성
void genList(List *pList, int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		list_add(pList, arr[i]);
}


// 배열로 부터 BST 생성
void genBST(BTreeNode **ppRoot, int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		bst_insert(ppRoot, arr[i]);
}

//-------------------------------------------------------------------------------
typedef void* fnSearch(void *, int);   // 검색함수 타입

// 특정 data 탐색 : 시간 체크
void chkTimeLapData(fnSearch search, void *collection, int data, char *title)
{
	int cnt = 0;
	clock_t start, end;
	start = clock(); //시간 측정 시작
	search(collection, data);  // 탐색 수행
	end = clock();
	printf("%s (탐색: %d) 수행결과 : %ld ms\n", title, data, end - start);
}

// 여러 data 탐색 : 시간 체크
void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title)
{
	int cnt = 0;
	clock_t start, end;
	start = clock(); //시간 측정 시작
	int i;
	for (i = 0; i < n; i++) // 탐색 수행
		if (search(collection, arr[i]) != NULL) cnt++;

	end = clock();
	printf("%s (%d/%d개 탐색) 수행결과 : %ld ms\n", title, cnt, n, end - start);
}



int main(int argc, char** argv)
{
	List list;

	// 랜덤 배열
	int srcArr[LEN];
	int workArr[LEN];

	genIncSorted(srcArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	shuffleArr(workArr, LEN);
	//printArr(workArr, LEN);

	
	list_init(&list);
	genList(&list, workArr, LEN);
	chkTimeLapArray(list_search, &list, srcArr, LEN, "리스트탐색");
	list_destroy(&list);

	BTreeNode *pRoot;   // BST 의 루트
	bst_make_init(&pRoot);   // BST 초기화
	genBST(&pRoot, workArr, LEN);
	chkTimeLapArray(bst_search, pRoot, srcArr, LEN, "BST탐색");
	btree_delete(pRoot);  // binary Tree 삭제

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




