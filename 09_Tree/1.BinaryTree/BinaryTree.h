#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* Binary Tree ������ */
typedef int BTData;        // �� �� �������� �̸� Data �� ���� ����.. ���߿� Queue �� ���� ��� �ؼ���

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *pLeft;  // left child node
	struct _bTreeNode *pRight;
} BTreeNode;      // �� �� �������� �̸� Node �� typedef ���� ����
					// ���߿� Queue �� ���� ��� �ϱ⿡..

/* Binary Tree ���� */

BTreeNode* btree_make_node(void);   // Ʈ�� ��� ����
BTData btree_get_data(BTreeNode *bt);   // ��� ������ �б�
void btree_set_data(BTreeNode *bt, BTData data);  // ��� ������ ����

BTreeNode* btree_get_left(BTreeNode *bt);  // ����� Left sub tree
BTreeNode* btree_get_right(BTreeNode *bt);  // ����� Right sub tree

void btree_make_left(BTreeNode *main, BTreeNode *sub);  // main �� left �� sub tree ����
void btree_make_right(BTreeNode *main, BTreeNode *sub);  // main �� right �� sub tree ����

void btree_delete(BTreeNode *bt);    // ���� ��� ���� ����



// Traversing-----------------------------------
// ��带 visit �Ͽ� ����� �����Ϳ� ���� ������ �Լ� (�Լ�������) Ÿ�� ����
typedef void fnVisitNode(BTData data);  

// �־��� ��� bt ���� �����Ͽ� preorder traversing �ϸ鼭 
// node �� visit �Ҷ����� action() ����
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action);


#endif