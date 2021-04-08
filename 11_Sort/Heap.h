#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define SUCCESS	1
#define FAIL	0

/*** Heap�� ���� ****/
//#define HEAP_LEN  40001    // �ڡ�

typedef int HData;

// d1�� �켱������ ���ٸ� 0���� ū ��
// d2�� �켱������ ���ٸ� 0���� ���� ��
// d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	fnPriorityComp * comp;
	int numData;
	//HData heapArr[HEAP_LEN];
	HData *heapArr;  // �����޸𸮷� ���� ��
} Heap;

/*** Heap ���� ����� ****/
//void heap_init(Heap *ph, fnPriorityComp pc);  // �� �ʱ�ȭ
void heap_init(Heap *ph, int len);  // �� �ʱ�ȭ
void heap_destroy(Heap *ph);

int heap_is_empty(Heap *ph);  // ���� ����ֳ�?

void heap_insert(Heap *ph, HData data);  // ���� ������ �߰�
HData heap_delete(Heap *ph);   // ������ root ���� (����)


// ������
Heap *g_hp;
void HeapSort(int arr[], int n);


//int ordAsc(HData ch1, HData ch2)
//{
//	return ch2 - ch1;    // min-heap
//}
//
//int ordDesc(HData ch1, HData ch2)
//{
//	return ch1 - ch2;    // max-heap
//}

#endif