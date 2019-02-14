#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList �� ADT
*/

#define TRUE 1
#define FALSE 0

typedef int Data;     // �����ʹ� int

// ��� Ÿ�� ����
typedef struct _node
{
	Data data;     // ��� ������
	struct _node *pNext;  // ���� ���
	struct _node *pPrev;  // ���� ���  �ڡ�
} Node;

// Linked List Ÿ�� ����
typedef struct _linkedList
{
	Node *pHead;   // ���� ���
	Node *pTail;   // �� ���

	Node *pCurrent;   // iteration ��
	int numData;     // ����� ����

}LinkedList;


/* LinkedList ���� */
typedef LinkedList List;

void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
void list_destroy(List *pList);   // ����Ʈ �Ҹ�

int list_add(List *pList, Data data);  // ������ �߰� (����)

// ����� ���Ḯ��Ʈ���� ���� ����
int list_init_iter(List *pList, Data* pData);   // ù��°�� ������ ��������
int list_last(List *pList, Data* pData);    // ������ ������ ��������
int list_next(List *pList, Data* pData);  // ���� ������ ��������
int list_prev(List *pList, Data* pData);  // ���� ������ ��������

int list_remove(List *pList, int n);  // ������ ����
int list_set(List *pList, int n, Data data);  // ������ ����
int list_length(List *pList);  // ������ ����

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�

#endif