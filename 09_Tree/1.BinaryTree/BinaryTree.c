#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제

#include "BinaryTree.h"
#include "ListQueue.h"

// 트리 노드 생성
BTreeNode * btree_make_node(void)
{
	BTreeNode *pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}

BTData btree_get_data(BTreeNode *bt)
{
	return bt->data;
}

void btree_set_data(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

BTreeNode * btree_get_left(BTreeNode *bt)
{
	return bt->pLeft;
}

BTreeNode * btree_get_right(BTreeNode * bt)
{
	return bt->pRight;
}

void btree_make_left(BTreeNode *bt, BTreeNode *sub)
{
	if (bt->pLeft != NULL)
		//free(bt->pLeft);   // ???????
		btree_delete(bt->pLeft);

	bt->pLeft = sub;
}

void btree_make_right(BTreeNode * bt, BTreeNode * sub)
{
	if(bt->pRight != NULL)
		//free(bt->pRight);
		btree_delete(bt->pRight);

	bt->pRight = sub;
}

void btree_delete(BTreeNode *bt)
{
	if (bt == NULL) return;

	// 삭제는 post order 방식(L -> R -> C) 순서로 지워야 한다

	// 자기 자신을 지우기 전에 left, right 부터 지워야 한다
	btree_delete(bt->pLeft);  // L
	btree_delete(bt->pRight); // R

							  // 자기자신 삭제
	printf("노드 삭제 : %d \n", bt->data);  // C
	free(bt);
}

// Traversing--------------------------------------------------------
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return; // 재귀종료

	// C -> L -> R
	action(bt->data);  // C
	btree_preorder_traverse(bt->pLeft, action);  // L : 재귀호출
	btree_preorder_traverse(bt->pRight, action);  // R : 재귀호출
}
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;   // 재귀 종료

	// L -> C -> R
	btree_inorder_traverse(bt->pLeft, action);  // L
	action(bt->data);  // C
	btree_inorder_traverse(bt->pRight, action); // R
}
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;   // 재귀 종료

	// L -> R -> C
	btree_postorder_traverse(bt->pLeft, action); // L
	btree_postorder_traverse(bt->pRight, action); // R
	action(bt->data); // C
}




// level-order traversing 도전!
// breath-first 도전

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	Queue q;
	queue_init(&q);

	// 일단 root 를 먼저 enq
	queue_enq(&q, bt);

	while (!queue_is_empty(&q))
	{
		BTreeNode *btCurrent;

		// 1. dequeue 하여 출력
		queue_deq(&q, &btCurrent);
		action(btCurrent->data);

		// 2. left -> enqueue
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);
		// 3. right -> enqueue
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}
	queue_destroy(&q);
}
