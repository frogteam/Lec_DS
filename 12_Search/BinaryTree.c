#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() �� ���� C �Լ��� ���� ����

#include "BinaryTree.h"
#include "ListQueue.h"

// Ʈ�� ��� ����
BTreeNode * btree_make_node(void)
{
	BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	newNode->data = 0;

	return newNode;
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

void btree_make_left(BTreeNode *main, BTreeNode *sub)
{
	if(main->pLeft != NULL)
		free(main->pLeft);   // ???????

	main->pLeft = sub;
}

void btree_make_right(BTreeNode * main, BTreeNode * sub)
{
	if(main->pRight != NULL)
		free(main->pRight);

	main->pRight = sub;
}

void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL)  // �������
		return;  

	// C -> L -> R
	action(bt->data);
	btree_preorder_traverse(bt->pLeft, action);
	btree_preorder_traverse(bt->pRight, action);
}
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL)
		return;   // ��� ����

	// L -> C -> R
	btree_inorder_traverse(bt->pLeft, action);
	action(bt->data);
	btree_inorder_traverse(bt->pRight, action);
}
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL)
		return;   // ��� ����

	// L -> R -> C
	btree_postorder_traverse(bt->pLeft, action);
	btree_postorder_traverse(bt->pRight, action);
	action(bt->data);
}


void btree_delete(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	// ������ post order ������� ������ �Ѵ�

	// �ڱ� �ڽ��� ����� ���� left, right ���� ������ �Ѵ�
	btree_delete(bt->pLeft);
	btree_delete(bt->pRight);

	// �ڱ��ڽ� ����
	//printf("��� ���� : %d \n", bt->data);
	free(bt);
}

// level-order traversing ����!
// breath-first ����

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	Queue q;
	queue_init(&q);

	// �ϴ� root �� ���� enq
	queue_enq(&q, bt);

	while (!queue_is_empty(&q))
	{
		BTreeNode *btCurrent;

		// 1. dequeue �Ͽ� ���
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


//----------------------------------------------------------------------
BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	BTreeNode * delNode = NULL;

	if (bt != NULL) {
		delNode = bt->pLeft;
		bt->pLeft = NULL;
	}
	return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
	BTreeNode * delNode = NULL;

	if (bt != NULL) {
		delNode = bt->pRight;
		bt->pRight = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->pLeft = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->pRight = sub;
}