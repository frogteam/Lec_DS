#pragma once
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
/*
	LinkedList �� ADT
*/

#define TRUE 1
#define FALSE 0

typedef int Data;     // �����ʹ� int

typedef struct _ArrayList
{
	Data arr[MAX_LIST_LEN];  // ������(��)
	int numData;           // ����Ʈ ���� ������ ����
	int curPosition;      // iteration
} ArrayList;

/* ArrayList ���� */
typedef ArrayList List;

void list_init(List *pList);   // ����Ʈ �ʱ�ȭ  
int list_add(List *pList, Data data);  // ������ �߰�

void list_first(List *pList);   // ������ ��ȸ, ù��°��
Data list_next(List *pList);  // ������ ��ȸ, ���� ������
int list_hasNext(List *pList);  // ������ ��ȸ : ������ �ֳ�?

int list_remove(List *pList, int n);  // ������ ����
int list_set(List *pList, int n, Data data);  // ������ ����
int list_size(List *pList);  // ������ ����

int list_get(List* pList, int n, Data *pData);   // ������ ��ȸ : n��° ������ �� �б�



#endif