#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	ArrayList �� ADT

	ArrayList ��
	���� : n��° ��ȸ ������
	���� : ����, ���� ������.

	���� : �뷮
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList �� ������ ���� */
//#define LIST_LEN	4
#define LIST_LEN	30000    // �������ϸ���

typedef int Data;     // �����ʹ� int

typedef struct _ArrayList
{
	Data arr[LIST_LEN];  // ������(��)
	int numData;           // ����Ʈ ���� ������ ����
	int curPosition;      // iteration
} ArrayList;

typedef ArrayList List;

/* ArrayList ���� */
void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
void list_destroy(List *pList);   // ����Ʈ ����

int list_add(List *pList, Data data);  // ������ �߰�
int list_remove(List *pList, int n);  // n��° ������ ����
int list_set(List *pList, int n, Data data);  // n��° ������ ����
int list_length(List *pList);  // ������ ����

void list_init_iter(List *pList);   // ������ ��ȸ, iteration �ʱ�ȭ
Data list_next(List *pList);  // ������ ��ȸ, iteration ���� ������ ����
int list_hasNext(List *pList);  // ������ ��ȸ, iteration ���� ������ �ֳ�?

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�

// 
int list_insert(List* pList, int n, Data data);  // ������ ����: n��° ��ġ�� ������ ����


#endif