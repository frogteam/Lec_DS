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
	bst_insert(&pRoot, 10);
	bst_insert(&pRoot, 5);
	bst_insert(&pRoot, 14);
	bst_insert(&pRoot, 6);
	bst_insert(&pRoot, 12);
	// �ð��� ���� Ȯ���غ���
	
	// level_order_traverse �ϱ� ����
	btree_levelorder_traverse(pRoot, printNodeData);



	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




