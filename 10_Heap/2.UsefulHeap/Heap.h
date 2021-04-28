#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define SUCCESS	1
#define FAIL	0

/*** Heap의 데이터 ****/
#define HEAP_LEN	100

typedef int HData;

// d1의 우선순위가 높다면 0보다 큰 값 리턴
// d2의 우선순위가 높다면 0보다 작은 값 리턴
// d1과 d2의 우선순위가 같다면 0을 리턴
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	HData heapArr[HEAP_LEN];  // 배열로 구현
	int numData;    // 담고 있는 데이터 개수
	fnPriorityComp * comp;  // 우선순위 비교 함수
} Heap;

/*** Heap 의 동작 ****/
void heap_init(Heap *ph, fnPriorityComp pc);  // 힙 초기화
int heap_is_empty(Heap *ph);  // 힙이 비어있나?

void heap_insert(Heap *ph, HData data);  // 힙에 데이터 추가
HData heap_delete(Heap *ph);   // 힙에서 삭제 (root 삭제) 하여 리턴

#endif