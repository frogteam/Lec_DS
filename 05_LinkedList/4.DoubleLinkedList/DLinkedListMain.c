#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "DLinkedList.h"

// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	int data;
	// ������
	printf("[");
	if (list_init_iter(pList, &data))
	{
		printf("%d ", data);
		while (list_next(pList, &data))
		{
			printf("%d ", data);
		}
	}
	printf("]");
	// ������
	printf("[");
	if (list_last(pList, &data))
	{
		printf("%d ", data);
		while (list_prev(pList, &data))
		{
			printf("%d ", data);
		}
	}
	printf("]");
	printf("\n");
}

int main()
{
	printf("<< ���� ���� ����Ʈ >>\n\n");

	List myList;
	list_init(&myList);

	///** add() ���� Ȯ�� **/
	printList(&myList);
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 50);   // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);   // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);   // ������ �߰�
	list_add(&myList, 70);    // ������ �߰�
	printList(&myList);

	// get()
	Data data;
	if(list_get(&myList, 4, &data))
		printf("  data=%d\n", data);
	if (list_get(&myList, 5, &data))
		printf("  data=%d\n", data);


	//// ������ ����
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); 
	printList(&myList);

	//// ������ ����
	printf("������ ������ %d\n", list_length(&myList));


	// ������ ����
	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 2);
	printList(&myList);

	list_remove(&myList, 0);
	printList(&myList);

	list_remove(&myList, 2);
	printList(&myList);


	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);

	printf("������ ������ %d\n", list_length(&myList));

	list_destroy(&myList);

	printf("���α׷��� �����մϴ�. �ƹ�Ű�� �����ּ���\n");
	_getch();
	return 0;
} // end main()