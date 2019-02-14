#include <stdio.h>
#include "ArrayList.h"

// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	list_init_iter(pList);  // iteration ����
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}
	printf("]\n");
}

int main()
{
	List myList;
	list_init(&myList);   // ����Ʈ ����
	
	list_add(&myList, 100);  // ������ �߰�
	list_add(&myList, 50);   // ������ �߰�
	list_add(&myList, 100);   // ������ �߰�
	list_add(&myList, 20);   // ������ �߰�
	list_add(&myList, 45);   // ������ �߰�    - ����
	list_add(&myList, 70);   // ������ �߰�    - ����

	list_destroy(&myList);  // ����Ʈ ����
	return 0;
} // end main()

