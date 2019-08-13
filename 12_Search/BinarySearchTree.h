#ifndef __BST_H__
#define __BST_H__

#include "BinaryTree.h"

#ifndef __COMMON_DATA__
#define __COMMON_DATA__

#define SUCCESS 1
#define FAIL 0

#endif

// 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot);

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
int bst_insert(BTreeNode **ppRoot, BTData data);

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* bst_search(BTreeNode *pRoot, BTData data);

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다.
BTreeNode* bst_remove(BTreeNode **ppRoot, BTData data);



#endif