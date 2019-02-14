#include <stdio.h>
#include "ArrayList.h"

// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	list_first(pList);  // iteration ����
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
	list_init(&myList);

	/** add() ���� Ȯ�� **/
	printList(&myList);
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 50);   // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);   // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);   // �Ұ�
	list_add(&myList, 70);    // �Ұ�

	// ������ ����
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);  // ���� ����
	printList(&myList);

	// ������ ����
	printf("������ ������ %d\n", list_size(&myList));

	// ������ ����
	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 0);
	printList(&myList);

	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);

	printf("������ ������ %d\n", list_size(&myList));

	return 0;
} // end main()