#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#include "BinaryTree.h"
#include "BinarySearchTree.h"


void printNodeData(BTData data) 
{
	printf("%d ", data);
}


int main(int argc, char** argv)
{
	BTreeNode *pRoot;   // BST 의 루트
	BTreeNode *pSearchNode;    // 탐색 노드

	bst_make_init(&pRoot);   // BST 초기화

	// 디버깅 해보자
	bst_insert(&pRoot, 12);
	bst_insert(&pRoot, 8);
	bst_insert(&pRoot, 9);
	bst_insert(&pRoot, 17);
	bst_insert(&pRoot, 10);
	bst_insert(&pRoot, 4);
	bst_insert(&pRoot, 21);
	bst_insert(&pRoot, 2);
	bst_insert(&pRoot, 13);
	bst_insert(&pRoot, 7);
	// 시간을 갖고 확인해보자

/*
*             12
*          ↙     ↘
*         8        17
*       ↙ ↘     ↙  ↘
*      4    9    13   21
*   ↙  ↘   ↘ 
*   2   7    10
*/
	
	// level_order_traverse 하기 쉽다
	btree_levelorder_traverse(pRoot, printNodeData);  // 12 8 17 4 9 13 21 2 7 10
	printf("\n");

	//----------------------------------------------------
	// ※ (여력이 되면) 삭제도 추가해보고 아래 동작 확인해보자.
	
	// 단말노드 제거 : 7 제거한 결과를 예측해보자
	bst_remove(&pRoot, 7);  
/*
*             12
*          ↙     ↘
*         8        17
*       ↙ ↘     ↙  ↘
*      4    9    13   21
*    ↙      ↘
*    2        10
*/
	btree_levelorder_traverse(pRoot, printNodeData); // 12 8 17 4 9 13 21 2 10
	printf("\n");

	// 하나의 자식만 갖는 노드 제거 : 4 제거한 결과를 예측해보자
	bst_remove(&pRoot, 4);   
/*
*             12
*          ↙     ↘
*         8        17
*       ↙ ↘     ↙  ↘
*      2    9    13   21
*           ↘
*             10
*/

	btree_levelorder_traverse(pRoot, printNodeData); // 12 8 17 2 9 13 21 10
	printf("\n");
	

	// 두개의 자식이 있는 경우 제거 : 8 을 제거해보자
	bst_remove(&pRoot, 8);
/*
*             12
*          ↙     ↘
*         9        17
*       ↙ ↘     ↙  ↘
*      2    19    13   21
*/	
	btree_levelorder_traverse(pRoot, printNodeData); // 12 9 17 2 10 13 21
	printf("\n");

	// 두개의 자식이 있는 경우 제거 : 12 제거해보자
	bst_remove(&pRoot, 12);
/*
*             13
*          ↙     ↘
*         9        17
*       ↙ ↘         ↘
*      2    19         21
*/
	btree_levelorder_traverse(pRoot, printNodeData); // 13 9 17 2 10 21
	printf("\n");

	//-----------------------------------------------
	btree_delete(pRoot);  // BTree 제거

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




