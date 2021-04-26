#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* Binary Tree 데이터 */
typedef int BTData;        // ※ 이 예제에선 이를 Data 라 하지 말자.. 나중에 Queue 와 같이 써야 해서리

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *pLeft;  // left child node
	struct _bTreeNode *pRight;
} BTreeNode;      // ※ 이 예제에선 이를 Node 로 typedef 하지 말자
					// 나중에 Queue 와 같이 써야 하기에..

/* Binary Tree 동작 */

BTreeNode* btree_make_node(void);   // 트리 노드 생성
BTData btree_get_data(BTreeNode *bt);   // 노드 데이터 읽기
void btree_set_data(BTreeNode *bt, BTData data);  // 노드 데이터 쓰기

BTreeNode* btree_get_left(BTreeNode *bt);  // 노드의 Left sub tree
BTreeNode* btree_get_right(BTreeNode *bt);  // 노드의 Right sub tree

void btree_make_left(BTreeNode *main, BTreeNode *sub);  // main 의 left 에 sub tree 연결
void btree_make_right(BTreeNode *main, BTreeNode *sub);  // main 의 right 에 sub tree 연결

void btree_delete(BTreeNode *bt);    // 현재 노드 부터 삭제



// Traversing-----------------------------------
// 노드를 visit 하여 노드의 데이터에 대해 수행할 함수 (함수포인터) 타입 선언
typedef void fnVisitNode(BTData data);  

// 주어진 노드 bt 부터 시작하여 preorder traversing 하면서 
// node 를 visit 할때마다 action() 수행
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action);


#endif