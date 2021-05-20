#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "ArrayListEx.h"

// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	list_first(pList);  // iteration ����
	
	// ����Ҷ��� �迭����ũ��,  ��������� ������ ����
	printf("%d : %d [", pList->maxLen, pList->numData);
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}
	printf("]\n");
}
void printListShort(List *pList)
{
	printf("%d : %d\n", pList->maxLen, pList->numData);
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
	list_add(&myList, 100);   // ������ ����!
	printList(&myList);
	list_add(&myList, 70);    // ������ ����!
	printList(&myList);
	list_add(&myList, 80);    // ������ ����!
	printList(&myList);
	list_add(&myList, 300);    // ������ ����!
	printList(&myList);

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

	list_remove(&myList, 0);
	printList(&myList);
	printf("������ ������ %d\n", list_size(&myList));

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
		printListShort(&myList);
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
		printListShort(&myList);
		printf("%ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������");
		_getch();

	}


	list_destroy(&myList);  // ����Ʈ �Ҹ�, �����Ҵ� ����
	return 0;
} // end main()
