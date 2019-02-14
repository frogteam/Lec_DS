#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList �� ADT
*/

#define TRUE 1
#define FALSE 0


typedef struct _student
{
	char szName[20];
	int age;           
	char grade;       // ���� ���  (�ѹ��� 'A', 'B', .. )
} Student;


typedef Student Data;     // �����Ͱ� Student!

// ��� Ÿ�� ����
typedef struct _node
{
	Data *pData;     // ��� ������ �������ͷ�!
	struct _node *pNext;  // ���� ���
} Node;

// Linked List Ÿ�� ����
typedef struct _linkedList
{
	Node *pHead;   // ���� ���
	//Node *pTail;   // �� ���   <-- ���� �������� tail �� �ʿ����.

	Node *pCurrent;   // iteration ��
	int numData;     // ����� ����

	int(*fnComp)(Data* d1, Data* d2);  // �񱳿� �Լ�

}LinkedList;


/* LinkedList ���� */
typedef LinkedList List;

void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
void list_destroy(List *pList);   // ����Ʈ �Ҹ�

int list_add(List *pList, Data *pData);  // ������ �߰� 

void list_first(List *pList);   // ������ ��ȸ, ù��°��
Data *list_next(List *pList);  // ������ ��ȸ, ���� ������
int list_hasNext(List *pList);  // ������ ��ȸ : ������ �ֳ�?

int list_remove(List *pList, int n);  // ������ ����
int list_set(List *pList, int n, Data *pData);  // ������ ����
int list_size(List *pList);  // ������ ����

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�

#endif