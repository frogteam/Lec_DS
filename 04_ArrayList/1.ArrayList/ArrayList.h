#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	ArrayList �� ADT
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList �� ���� */
#define LIST_INC_LEN	3

typedef int Data;     // �����ʹ� int

typedef struct _ArrayList
{
	Data arr[LIST_INC_LEN];  // ������(��)
	int numData;           // ����Ʈ ���� ������ ����
	int curPosition;      // iteration
} ArrayList;

/* ArrayList ���� */
typedef ArrayList List;

void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
void list_destroy(List *pList);   // ����Ʈ ����

int list_add(List *pList, Data data);  // ������ �߰�
int list_remove(List *pList, int n);  // ������ ����
int list_set(List *pList, int n, Data data);  // ������ ����
int list_length(List *pList);  // ������ ����

void list_init_iter(List *pList);   // ������ ��ȸ, �ʱ�ȭ
Data list_next(List *pList);  // ������ ��ȸ, ���� ������
int list_hasNext(List *pList);  // ������ ��ȸ : ������ �ֳ�?

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�

#endif