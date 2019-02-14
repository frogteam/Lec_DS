#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "LinkedListStruct.h"



// ����Ʈ ��� ����� �Լ�
void printData(Data* pData)
{
	printf("%s/%d��/%c, ", pData->szName, pData->age, pData->grade);
}
void printList(List *pList)
{
	list_first(pList);  // iteration ����
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]\n");
}

int main()
{
	List myList;
	list_init(&myList);

	Data stu[] = {
		{"ȫ�浿", 20, 'A'},
		{"James", 34, 'B'},
		{"����", 30, 'D'},
		{"������", 23, 'E'},
		{"����", 77, 'C'},
		{"����Ŭ", 38, 'C'}
	};

	printList(&myList);
	list_add(&myList, stu + 0);   // &stu[0] �� �ص� �Ǵ�
	printList(&myList);
	list_add(&myList, stu + 1);
	printList(&myList);
	list_add(&myList, stu + 2);
	printList(&myList);
	list_add(&myList, stu + 3);
	printList(&myList);
	list_add(&myList, stu + 4);
	printList(&myList);


	Data result;
	list_get(&myList, 2, &result);
	printData(&result); printf("\n");
	list_get(&myList, 0, &result);
	printData(&result); printf("\n");

	printf("������ ������ %d\n", list_size(&myList));

	// ����
	list_set(&myList, 0, stu + 5);
	list_set(&myList, 2, stu + 5);
	printList(&myList);

	// ����
	list_remove(&myList, 0);
	list_remove(&myList, 3);
	printList(&myList);

	list_remove(&myList, 0);
	list_remove(&myList, 0);
	list_remove(&myList, 0);

	{
		printf("�������ϸ� ����: ������");
		_getch();

		clock_t start, end;

		// �������ϸ�
		unsigned int i = 0;
		start = clock(); //�ð� ���� ����
		for (i = 0; i < 10000; i++)
		{
			list_add(&myList, stu + (i % 6));
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_size(&myList));

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
		printf("���� ����Ʈ size : %d\n", list_size(&myList));
		printf("%ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������");
		_getch();

	}

	list_destroy(&myList);

	printf("���α׷��� �����մϴ�. �ƹ�Ű�� �����ּ���\n");
	_getch();
	return 0;
} // end main()