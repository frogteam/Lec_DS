#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "BinaryTree.h"

void printData(BTData data)
{
	printf("%d ", data);
}


int main(void)
{
	// 1. 일단 make 하고 연결하는 것 실행해보기
	BTreeNode *bt1 = btree_make_node();
	BTreeNode *bt2 = btree_make_node();
	BTreeNode *bt3 = btree_make_node();
	BTreeNode *bt4 = btree_make_node();

	btree_set_data(bt1, 1);
	btree_set_data(bt2, 2);
	btree_set_data(bt3, 3);
	btree_set_data(bt4, 4);

	btree_make_left(bt1, bt2);
	btree_make_right(bt1, bt3);
	btree_make_left(bt2, bt4);

	// b1 의 left 의 data 는?
	printf("%d \n",
		btree_get_data(btree_get_left(bt1)));

	// b1 의 left 의 left 의 데이터는?
	printf("%d \n",
		btree_get_data(btree_get_left(btree_get_left(bt1))));

	// 2. traversing 추가
	printf("Preorder : ");
	btree_preorder_traverse(bt1, printData);
	printf("\n");
	printf("Inorder : ");
	btree_inorder_traverse(bt1, printData);
	printf("\n");
	printf("Postorder : ");
	btree_postorder_traverse(bt1, printData);
	printf("\n");

	// 4. level-order 
	printf("level-order : ");
	btree_levelorder_traverse(bt1, printData);
	printf("\n");

	// 3. 삭제
	btree_delete(bt1);


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()
