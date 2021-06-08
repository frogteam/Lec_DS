#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
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
	if (n > 1)  // 배열길이 2개 이상인 경우만 shuffle
	{
		for (i = 0; i < n - 1; i++)
		{
			// i 와 임의의 j번째와 swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}
// 배열로 부터 list 생성
void genList(List *pList, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		list_add(pList, arr[i]);
}


// 배열로 부터 BST 생성
void genBST(BTreeNode **ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		bst_insert(ppRoot, arr[i]);
}

//-------------------------------------------------------------------------------
typedef void* fnSearch(void *, int);   // 검색함수 타입

// 특정 data 하나 탐색 : 시간 체크
//void chkTimeLapData(fnSearch search, void *collection, int data, char *title)
//{
//	int cnt = 0;
//	clock_t start, end;
//	start = clock(); //시간 측정 시작
//	search(collection, data);  // 탐색 수행
//	end = clock();
//	printf("%s (탐색: %d) 수행결과 : %ld ms\n", title, data, end - start);
//}

// collection 에서 arr[] 의 data들을 탐색하여
// 평균 검색 시간을 체크
void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title)
{
	int cnt = 0;   // Search 성공한 개수
	clock_t start, end;
	long duration = 0;

	// 각 개별적인 search 의 누적합산 한뒤 평균을 구한다.
	for (int i = 0; i < n; i++) {
		start = clock();
		if (search(collection, arr[i]) != NULL) cnt++;  // 탐색수행
		end = clock();
		duration += end - start;
	}
	// %.3f 소숫점 3자리까지 출력해야 느낌이 올듯
	printf("%s (%d/%d개 탐색) 수행결과: %.3f ms\n", title, cnt, n, (double)duration / n); // 평균수행시간
}



int main(int argc, char** argv)
{

	// 중복된 값이 없는 랜덤 배열 생성 
	int srcArr[DATA_SIZE];
	int workArr[DATA_SIZE];

	genIncSorted(srcArr, DATA_SIZE);

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	shuffleArr(workArr, DATA_SIZE);
	//printArr(workArr, DATA_SIZE);

	
	List list;
	list_init(&list);
	genList(&list, workArr, DATA_SIZE);  // list <- workArr
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "리스트탐색");
	list_destroy(&list);

	BTreeNode *pRoot;   // BST 의 루트
	bst_make_init(&pRoot);   // BST 초기화

	//genBST(&pRoot, srcArr, 10);  // 동작테스트, 1 ~ 10
	//BTreeNode *p = NULL;
	//for(int i = 1; i <= 10; i++)
	//	if (p = bst_search(pRoot, i)) printf("발견 %d\n", p->data);


	genBST(&pRoot, workArr, DATA_SIZE);  // BST <- workArr
	chkTimeLapArray(bst_search, pRoot, srcArr, DATA_SIZE, "BST탐색");
	btree_delete(pRoot);  // binary Tree 삭제

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




