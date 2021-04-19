#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList �� ADT

	����: ����, ���� ����
	����: ��ȸ�� �Ҹ�

	����: ArrayList�� ���� �뷮 UP
*/

#define TRUE 1
#define FALSE 0

/* List �� ������  */

typedef int Data;     // �����ʹ� int

// ��� Ÿ�� ����
typedef struct _node
{
	Data data;     // ��� ������
	struct _node *pNext;  // ���� ���
} Node;

// Linked List Ÿ�� ����
typedef struct _linkedList
{
	Node *pHead;   // ���� ���
	Node *pTail;   // �� ���

	Node *pCurrent;   // iteration ��
	int numData;     // ����� ����

}LinkedList;

typedef LinkedList List;

/* List ���� */

void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
void list_destroy(List *pList);   // ����Ʈ ����

int list_add(List *pList, Data data);  // ������ �߰�
int list_remove(List *pList, int n);  // n��° ������ ����
int list_set(List *pList, int n, Data data);  // n��° ������ ����
int list_length(List *pList);  // ������ ����

void list_init_iter(List *pList);   // iteration �ʱ�ȭ
Data list_next(List *pList);  // ������ ��ȸ, ���� ������
int list_hasNext(List *pList);  // ������ ��ȸ : ������ �ֳ�?

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�


int list_insert(List* pList, int n, Data data);   // ������ ����: n��° ��ġ�� ������ ����

#endif