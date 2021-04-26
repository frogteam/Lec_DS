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

	// ������ post order ���(L -> R -> C) ������ ������ �Ѵ�

	// �ڱ� �ڽ��� ����� ���� left, right ���� ������ �Ѵ�
	btree_delete(bt->pLeft);  // L
	btree_delete(bt->pRight); // R

							  // �ڱ��ڽ� ����
	printf("��� ���� : %d \n", bt->data);  // C
	free(bt);
}

// Traversing--------------------------------------------------------
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return; // �������

	// C -> L -> R
	action(bt->data);  // C
	btree_preorder_traverse(bt->pLeft, action);  // L : ���ȣ��
	btree_preorder_traverse(bt->pRight, action);  // R : ���ȣ��
}
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;   // ��� ����

	// L -> C -> R
	btree_inorder_traverse(bt->pLeft, action);  // L
	action(bt->data);  // C
	btree_inorder_traverse(bt->pRight, action); // R
}
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;   // ��� ����

	// L -> R -> C
	btree_postorder_traverse(bt->pLeft, action); // L
	btree_postorder_traverse(bt->pRight, action); // R
	action(bt->data); // C
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
