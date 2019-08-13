#ifndef __BST_H__
#define __BST_H__

#include "BinaryTree.h"

#ifndef __COMMON_DATA__
#define __COMMON_DATA__

#define SUCCESS 1
#define FAIL 0

#endif

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot);

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
int bst_insert(BTreeNode **ppRoot, BTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* bst_search(BTreeNode *pRoot, BTData data);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* bst_remove(BTreeNode **ppRoot, BTData data);



#endif