#include <stdio.h>

// 
#define MAX_LENGTH 4

#define TRUE 1
#define FALSE 0


typedef struct _IterArray
{
	int arr[MAX_LENGTH];
	int curPosition;   // iterator ������ ���� ��
} IterArray;


// iterator �ʱ�ȭ
void iter_init(IterArray* p)
{
	printf("Iterator �ʱ�ȭ\n");
	p->curPosition = -1;  // �ٽ� �� �����.
}

// ������ ������ ������ �ֳ�?
int iter_hasNext(IterArray* p)
{
	if(p->curPosition + 1 < MAX_LENGTH) 
	{
		return TRUE;
	}
	else 
	{
		printf("���̻� ������ �����Ͱ� �����ϴ�\n");
		return FALSE;
	}
}

// ���� ������ ����
int iter_next(IterArray* p)
{
	p->curPosition++;   // �켱! curPosition �� next �� +1 ����
	return p->arr[p->curPosition];   // curPosition�� ����Ű�� ���� ���� ����
}

int main()
{
	IterArray data = {{10, 20, 30, 40}, -1};
	iter_init(&data);

	while(iter_hasNext(&data)) // �� ������ ������ �ֳ�?
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");
	// �ϴ� ����!

	// �ٽ� iterator ������ �ϸ�..
	while(iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// iterator �� ���� ���۽��Ѿ� �Ѵ�
	iter_init(&data);
	while(iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");
}

/* ���� ��κ��� ���� ���鿡�� Iteration(�ݺ���) ������.
*
*	Python �� iterable��ü
*		ex) for a in b:  <-- b �� 'iterable' �ؾ� �Ѵ�.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection �� Iterator ��ü
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator 
*/