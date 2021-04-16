#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#include "BinaryTree.h"
#include "BinarySearchTree.h"


void printNodeData(BTData data) 
{
	printf("%d ", data);
}


int main(int argc, char** argv)
{
	BTreeNode *pRoot;   // BST �� ��Ʈ
	BTreeNode *pSearchNode;    // Ž�� ���

	bst_make_init(&pRoot);   // BST �ʱ�ȭ

	// ����� �غ���
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
	// �ð��� ���� Ȯ���غ���

/*
*             12
*          ��     ��
*         8        17
*       �� ��     ��  ��
*      4    9    13   21
*   ��  ��   �� 
*   2   7    10
*/
	
	// level_order_traverse �ϱ� ����
	btree_levelorder_traverse(pRoot, printNodeData);  // 12 8 17 4 9 13 21 2 7 10
	printf("\n");

	//----------------------------------------------------
	// �� (������ �Ǹ�) ������ �߰��غ��� �Ʒ� ���� Ȯ���غ���.
	
	// �ܸ���� ���� : 7 ������ ����� �����غ���
	bst_remove(&pRoot, 7);  
/*
*             12
*          ��     ��
*         8        17
*       �� ��     ��  ��
*      4    9    13   21
*    ��      ��
*    2        10
*/
	btree_levelorder_traverse(pRoot, printNodeData); // 12 8 17 4 9 13 21 2 10
	printf("\n");

	// �ϳ��� �ڽĸ� ���� ��� ���� : 4 ������ ����� �����غ���
	bst_remove(&pRoot, 4);   
/*
*             12
*          ��     ��
*         8        17
*       �� ��     ��  ��
*      2    9    13   21
*           ��
*             10
*/

	btree_levelorder_traverse(pRoot, printNodeData); // 12 8 17 2 9 13 21 10
	printf("\n");
	

	// �ΰ��� �ڽ��� �ִ� ��� ���� : 8 �� �����غ���
	bst_remove(&pRoot, 8);
/*
*             12
*          ��     ��
*         9        17
*       �� ��     ��  ��
*      2    19    13   21
*/	
	btree_levelorder_traverse(pRoot, printNodeData); // 12 9 17 2 10 13 21
	printf("\n");

	// �ΰ��� �ڽ��� �ִ� ��� ���� : 12 �����غ���
	bst_remove(&pRoot, 12);
/*
*             13
*          ��     ��
*         9        17
*       �� ��         ��
*      2    19         21
*/
	btree_levelorder_traverse(pRoot, printNodeData); // 13 9 17 2 10 21
	printf("\n");

	//-----------------------------------------------
	btree_delete(pRoot);  // BTree ����

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




