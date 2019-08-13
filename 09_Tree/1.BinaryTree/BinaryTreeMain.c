#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() �� ���� C �Լ��� ���� ����
#include "BinaryTree.h"

void printData(BTData data)
{
	printf("%d ", data);
}


int main(void)
{
	// 1. �ϴ� make �ϰ� �����ϴ� �� �����غ���
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

	// b1 �� left �� data ��?
	printf("%d \n",
		btree_get_data(btree_get_left(bt1)));

	// b1 �� left �� left �� �����ʹ�?
	printf("%d \n",
		btree_get_data(btree_get_left(btree_get_left(bt1))));

	// 2. traversing �߰�
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

	// 3. ����
	btree_delete(bt1);


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()
