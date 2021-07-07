#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#include "BinarySearchTree.h"

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot)
{
	*ppRoot = NULL;
}

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
int bst_insert(BTreeNode **ppRoot, BTData data)
{
	BTreeNode *parentNode = NULL;    // parent node
	BTreeNode *curNode = *ppRoot;    // current node : �ϴ� root ���� �����Ѵ�.
	BTreeNode *newNode = NULL;    // new node

	// ���ο� ��尡 �߰��� ��ġ�� ã�´�.
	// root ���� �����Ͽ� (���� ����) ��ġ�� ã�������� ������ ��������.
	while (curNode != NULL)    // ���������� ����, �ٷ� �װ��� ���Ե� ��ġ
	{
		if (data == btree_get_data(curNode))
			return FAIL;   // BST ���� key �� �ߺ��� ������� ����

		// ���� BST ���� Ű���� �ߺ����� �ʴ´�

		parentNode = curNode;   // �ϴ� parent node �� current node �� �ΰ�

		if (btree_get_data(curNode) > data)   // �����Ϸ��� data�� ����� �����ͺ��� �� �۴ٸ�. current node �� left �� �̵�
			curNode = btree_get_left(curNode);
		else                          // �����Ϸ��� data�� ����� �����ͺ��� �� ũ�ٸ�  currnet node �� right �� �̵�
			curNode = btree_get_right(curNode);
	}

	// �߰��� �� ����� ����
	newNode = btree_make_node();  // �� ����� ����  
	btree_set_data(newNode, data); // �� ��忡 ������ ����

	// parentNode�� ���� ��忡 �� ��带 �߰�
	if (parentNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,  (root )��ġ��� NULL �� ���´�.
	{
		if (data < btree_get_data(parentNode))     // �θ��� �����ͺ��� �۴ٸ�  left �� ���̰�
			btree_make_left(parentNode, newNode);
		else                                  // �θ��� �����ͺ��� ũ�� right �� ���δ�
			btree_make_right(parentNode, newNode);
	}
	else    // ù��° ����� ���, �� ��尡 ��Ʈ ��ġ�̱⿡ parentNode �� NULL �� ���´�
	{
		*ppRoot = newNode;  // ��Ʈ ����!
	}

	return SUCCESS;
}

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* bst_search(BTreeNode *pRoot, BTData data)
{
	BTreeNode *curNode = pRoot;    // current node �� root ���� Ž�� ����
	BTData curData;    // current data

	while (curNode != NULL) // Ž���� �� �������ٰ� ���������� �����ϸ� �ᱹ Ž�������� ���̴�.
	{
		curData = btree_get_data(curNode);   // ���� ����� ������

		if (data == curData)
			return curNode;       // �߰�!!!  ��� ������ �����ϰ�, Ž�� ����

		if (data < curData)          // data ���� ����� �����ͺ��� �۴ٸ� left �� �̵�
			curNode = btree_get_left(curNode);
		else                            // �����Ͱ��� curData ���� ũ�ٸ� right ����Ʈ���� �̵��Ͽ� Ž��
			curNode = btree_get_right(curNode);
	}

	return NULL;  // Ž�� ��� ����
}

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* bst_remove(BTreeNode **ppRoot, BTData data)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.

	BTreeNode * pVRoot = btree_make_node();    // ���� ��Ʈ ���;

	BTreeNode * parentNode = pVRoot;    // parent node
	BTreeNode * curNode = *ppRoot;    // current node
	BTreeNode * delNode;    // delete node

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ ���� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *ppRoot);

	// ���� ����� ������ ��� Ž��
	while (curNode != NULL && btree_get_data(curNode) != data)
	{
		parentNode = curNode;

		if (data < btree_get_data(curNode)) 
			curNode = btree_get_left(curNode);  
		else
			curNode = btree_get_right(curNode);
	}

	if (curNode == NULL)    // ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	delNode = curNode;    // ���� ����� dNode�� ����Ű�� �Ѵ�.

	// ù ��° ���: ������ ��尡 �ܸ� ����� ���
	if (btree_get_left(delNode) == NULL && btree_get_right(delNode) == NULL)
	{
		if (btree_get_left(parentNode) == delNode)
			RemoveLeftSubTree(parentNode);
		else
			RemoveRightSubTree(parentNode);
	}

	// �� ��° ���: �ϳ��� �ڽ� ��带 ���� ���
	else if (btree_get_left(delNode) == NULL || btree_get_right(delNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node�� �ڽ� ���

		if (btree_get_left(delNode) != NULL)
			dcNode = btree_get_left(delNode);
		else
			dcNode = btree_get_right(delNode);

		if (btree_get_left(parentNode) == delNode)
			ChangeLeftSubTree(parentNode, dcNode);
		else
			ChangeRightSubTree(parentNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode * mNode = btree_get_right(delNode);    // mininum node
		BTreeNode * mpNode = delNode;    // mininum node�� �θ� ���
		int delData;

		// ������ ��带 ��ü�� ��带 ã�´�.
		while (btree_get_left(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = btree_get_left(mNode);
		}

		// ��ü�� ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = btree_get_data(delNode);    // ���� �� ������ ���
		btree_set_data(delNode, btree_get_data(mNode));

		// ��ü�� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (btree_get_left(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, btree_get_right(mNode));
		else
			ChangeRightSubTree(mpNode, btree_get_right(mNode));

		delNode = mNode;
		btree_set_data(delNode, delData);    // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� ó��
	if (btree_get_right(pVRoot) != *ppRoot)
		*ppRoot = btree_get_right(pVRoot);

	free(pVRoot);
	return delNode;
}