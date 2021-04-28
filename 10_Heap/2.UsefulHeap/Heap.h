#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define SUCCESS	1
#define FAIL	0

/*** Heap�� ������ ****/
#define HEAP_LEN	100

typedef int HData;

// d1�� �켱������ ���ٸ� 0���� ū �� ����
// d2�� �켱������ ���ٸ� 0���� ���� �� ����
// d1�� d2�� �켱������ ���ٸ� 0�� ����
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	HData heapArr[HEAP_LEN];  // �迭�� ����
	int numData;    // ��� �ִ� ������ ����
	fnPriorityComp * comp;  // �켱���� �� �Լ�
} Heap;

/*** Heap �� ���� ****/
void heap_init(Heap *ph, fnPriorityComp pc);  // �� �ʱ�ȭ
int heap_is_empty(Heap *ph);  // ���� ����ֳ�?

void heap_insert(Heap *ph, HData data);  // ���� ������ �߰�
HData heap_delete(Heap *ph);   // ������ ���� (root ����) �Ͽ� ����

#endif