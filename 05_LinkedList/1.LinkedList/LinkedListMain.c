#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "LinkedList.h"

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


	// ������ ����
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); 
	printList(&myList);

	// ������ ����
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

	{
		printf("�������ϸ� ����: ������");
		_getch();

		clock_t start, end;

		// �������ϸ�
		unsigned int i = 0;
		start = clock(); //�ð� ���� ����
		for (i = 0; i < 10000; i++)
		{
			list_add(&myList, i);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));

		printf("%ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ������ ���۵˴ϴ�: ������");
		_getch();
		start = clock(); //�ð� ���� ����
		for (i = 0; i < 10000; i++)
		{
			list_remove(&myList, 0);
			printf("���� %d\n", i);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("%ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������");
		_getch();

	}


	list_destroy(&myList);

	printf("���α׷��� �����մϴ�. �ƹ�Ű�� �����ּ���\n");
	_getch();
	return 0;
} // end main()