#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)
#include "BinarySearchTree.h"

// 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot)
{
	*ppRoot = NULL;
}

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
int bst_insert(BTreeNode **ppRoot, BTData data)
{
	BTreeNode *parentNode = NULL;    // parent node
	BTreeNode *curNode = *ppRoot;    // current node : 일단 root 부터 시작한다.
	BTreeNode *newNode = NULL;    // new node

	// 새로운 노드가 추가될 위치를 찾는다.
	// root 부터 시작하여 (위에 세팅) 위치를 찾을때까지 밑으로 내려간다.
	while (curNode != NULL)    // 종단점까지 가면, 바로 그곳이 삽입될 위치
	{
		if (data == btree_get_data(curNode))
			return FAIL;   // BST 에선 key 의 중복을 허용하지 않음

		// 절대 BST 에서 키값은 중복되지 않는다

		parentNode = curNode;   // 일단 parent node 를 current node 로 두고

		if (btree_get_data(curNode) > data)   // 삽입하려는 data가 노드의 데이터보다 더 작다면. current node 를 left 로 이동
			curNode = btree_get_left(curNode);
		else                          // 삽입하려는 data가 노드의 데이터보다 더 크다면  currnet node 를 right 로 이동
			curNode = btree_get_right(curNode);
	}

	// 추가할 새 노드의 생성
	newNode = btree_make_node();  // 새 노드의 생성  
	btree_set_data(newNode, data); // 새 노드에 데이터 저장

	// parentNode의 서브 노드에 새 노드를 추가
	if (parentNode != NULL)    // 새 노드가 루트 노드가 아니라면,  (root )위치라면 NULL 인 상태다.
	{
		if (data < btree_get_data(parentNode))     // 부모의 데이터보다 작다면  left 로 붙이고
			btree_make_left(parentNode, newNode);
		else                                  // 부모의 데이터보다 크면 right 로 붙인다
			btree_make_right(parentNode, newNode);
	}
	else    // 첫번째 노드의 경우, 새 노드가 루트 위치이기에 parentNode 는 NULL 인 상태다
	{
		*ppRoot = newNode;  // 루트 세팅!
	}

	return SUCCESS;
}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* bst_search(BTreeNode *pRoot, BTData data)
{
	BTreeNode *curNode = pRoot;    // current node 는 root 부터 탐색 시작
	BTData curData;    // current data

	while (curNode != NULL) // 탐색을 해 내려가다가 종단점까지 도달하면 결국 탐색실패한 것이다.
	{
		curData = btree_get_data(curNode);   // 현재 노드의 데이터

		if (data == curData)
			return curNode;       // 발견!!!  노드 포인터 리턴하고, 탐색 종료

		if (data < curData)          // data 값이 노드의 데이터보다 작다면 left 로 이동
			curNode = btree_get_left(curNode);
		else                            // 데이터값이 curData 보다 크다면 right 서브트리로 이동하여 탐색
			curNode = btree_get_right(curNode);
	}

	return NULL;  // 탐색 결과 없슴
}

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다.
BTreeNode* bst_remove(BTreeNode **ppRoot, BTData data)
{
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.

	BTreeNode * pVRoot = btree_make_node();    // 가상 루트 노드;

	BTreeNode * parentNode = pVRoot;    // parent node
	BTreeNode * curNode = *ppRoot;    // current node
	BTreeNode * delNode;    // delete node

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 서브 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *ppRoot);

	// 삭제 대상을 저장한 노드 탐색
	while (curNode != NULL && btree_get_data(curNode) != data)
	{
		parentNode = curNode;

		if (data < btree_get_data(curNode)) 
			curNode = btree_get_left(curNode);  
		else
			curNode = btree_get_right(curNode);
	}

	if (curNode == NULL)    // 삭제 대상이 존재하지 않는다면,
		return NULL;

	delNode = curNode;    // 삭제 대상을 dNode가 가리키게 한다.

	// 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
	if (btree_get_left(delNode) == NULL && btree_get_right(delNode) == NULL)
	{
		if (btree_get_left(parentNode) == delNode)
			RemoveLeftSubTree(parentNode);
		else
			RemoveRightSubTree(parentNode);
	}

	// 두 번째 경우: 하나의 자식 노드를 갖는 경우
	else if (btree_get_left(delNode) == NULL || btree_get_right(delNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node의 자식 노드

		if (btree_get_left(delNode) != NULL)
			dcNode = btree_get_left(delNode);
		else
			dcNode = btree_get_right(delNode);

		if (btree_get_left(parentNode) == delNode)
			ChangeLeftSubTree(parentNode, dcNode);
		else
			ChangeRightSubTree(parentNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode * mNode = btree_get_right(delNode);    // mininum node
		BTreeNode * mpNode = delNode;    // mininum node의 부모 노드
		int delData;

		// 삭제할 노드를 대체할 노드를 찾는다.
		while (btree_get_left(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = btree_get_left(mNode);
		}

		// 대체할 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = btree_get_data(delNode);    // 대입 전 데이터 백업
		btree_set_data(delNode, btree_get_data(mNode));

		// 대체할 노드의 부모 노드와 자식 노드를 연결한다.
		if (btree_get_left(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, btree_get_right(mNode));
		else
			ChangeRightSubTree(mpNode, btree_get_right(mNode));

		delNode = mNode;
		btree_set_data(delNode, delData);    // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 처리
	if (btree_get_right(pVRoot) != *ppRoot)
		*ppRoot = btree_get_right(pVRoot);

	free(pVRoot);
	return delNode;
}