#include <stdio.h>

// 
#define MAX_LENGTH 4

#define TRUE 1
#define FALSE 0


typedef struct _IterArray
{
	int arr[MAX_LENGTH];
	int curPosition;   // iterator 구현을 위한 값
} IterArray;


// iterator 초기화
void iter_init(IterArray* p)
{
	printf("Iterator 초기화\n");
	p->curPosition = -1;  // 다시 줄 세운다.
}

// 다음에 추출할 데이터 있나?
int iter_hasNext(IterArray* p)
{
	if(p->curPosition + 1 < MAX_LENGTH) 
	{
		return TRUE;
	}
	else 
	{
		printf("더이상 추출할 데이터가 없습니다\n");
		return FALSE;
	}
}

int iter_next(IterArray* p)
{
	p->curPosition++;                 // position 이 next로 먼저 증가하고
	return p->arr[p->curPosition];    // 그 다음에 값을 가져온다.
}

int main()
{
	IterArray data = {{10, 20, 30, 40}, -1};
	iter_init(&data);

	while(iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// 다시 iterator 돌리려 하면..
	while(iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// iterator 는 새로 동작시켜야 한다
	iter_init(&data);
	while(iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");
}