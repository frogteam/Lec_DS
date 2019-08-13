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
	bst_insert(&pRoot, 10);
	bst_insert(&pRoot, 5);
	bst_insert(&pRoot, 14);
	bst_insert(&pRoot, 6);
	bst_insert(&pRoot, 12);
	// 시간을 갖고 확인해보자
	
	// level_order_traverse 하기 쉽다
	btree_levelorder_traverse(pRoot, printNodeData);



	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




