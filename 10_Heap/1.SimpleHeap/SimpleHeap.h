#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define SUCCESS	1
#define FAIL	0

/* Heap �� ������ */
#define HEAP_LEN	100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
	Priority pr;	// ���� �������� ���� �켱����
	HData data;
} HeapElem;

typedef struct _heap
{
	int numData;    // Heap �� ������ ����
	HeapElem heapArr[HEAP_LEN];
} Heap;

/* Heap �� ���� */
void heap_init(Heap * ph);
int heap_is_empty(Heap * ph);

void heap_insert(Heap * ph, HData data, Priority pr);
HData heap_delete(Heap * ph);

#endif