#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define SUCCESS	1
#define FAIL	0

/*** Heap의 정의 ****/
//#define HEAP_LEN  40001    // ★★

typedef int HData;

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	fnPriorityComp * comp;
	int numData;
	//HData heapArr[HEAP_LEN];
	HData *heapArr;  // 동적메모리로 구현 ★
} Heap;

/*** Heap 관련 연산들 ****/
//void heap_init(Heap *ph, fnPriorityComp pc);  // 힙 초기화
void heap_init(Heap *ph, int len);  // 힙 초기화
void heap_destroy(Heap *ph);

int heap_is_empty(Heap *ph);  // 힙이 비어있나?

void heap_insert(Heap *ph, HData data);  // 힙에 데이터 추가
HData heap_delete(Heap *ph);   // 힙에서 root 삭제 (리턴)


// 힙정렬
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