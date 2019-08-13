#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList �� ADT
*/
#define SUCCESS 1
#define FAIL 0

// ������ ����ü
typedef struct _student
{
	char szName[20]; // �̸�
	int age;     // ����      
	char grade;  // ���� ���  (ex 'A', 'B', .)
} Student;

typedef Student Data;     // �����Ͱ� Student!

// ��� Ÿ�� ����
typedef struct _node
{
	Data *pData; // ��� ������
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

typedef LinkedList List;

/* LinkedList ���� */
void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
void list_destroy(List *pList);   // ����Ʈ �Ҹ�

int list_add(List *pList, Data *pData);  // ������ �߰� 
int list_remove(List *pList, int n);  // ������ ����
int list_set(List *pList, int n, Data *pData);  // ������ ���� 
int list_length(List *pList);  // ������ ����

// ����� ���Ḯ��Ʈ ���� iteration ����� ����
void list_init_forward(List *pList);   //�� forward iteration �ʱ�ȭ
int list_hasNext(List *pList);  // ������ ��ȸ : ���� ��� �ֳ�?
Data *list_next(List *pList);  // ������ ��ȸ, ���� ��� ������ 

void list_init_backward(List *pList);    //�� backward iteration �ʱ�ȭ
int list_hasPrev(List *pList);  //�� ������ ��ȸ : ���� ��� �ֳ�?
Data *list_prev(List *pList);  //�� ������ ��ȸ, ���� ��� ������ 

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�

int list_move_current(List* pList, int n);   // current �̵� :  doubly linked list �� ����

#endif