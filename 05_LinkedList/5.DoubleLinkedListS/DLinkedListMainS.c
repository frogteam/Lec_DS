#include <stdio.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "DLinkedListS.h"

// ����Ʈ ��� ����� �Լ�
void printData(Data* pData)
{
	printf("%s/%d��/%c, ", pData->szName, pData->age, pData->grade);
}

void printList(List *pList)
{
	list_init_forward(pList);  // �� forward iteration ����
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]");

	list_init_backward(pList);  // �� backward iteration ����
	printf("[");
	while (list_hasPrev(pList))
	{
		printData(list_prev(pList));
	}
	printf("]\n");
}


int main()
{
	printf("<< ���� ���� ����Ʈ >>\n\n");
	Data stu[] = {
		{"ȫ�浿", 20, 'A'},
		{"������", 34, 'B'},
		{"����", 30, 'D'},
		{"������", 23, 'E'},
		{"�ڼ���", 77, 'C'},
		{"����Ŭ", 38, 'C'}
	};

	List myList;
	list_init(&myList);

	// ������ �߰�
	printList(&myList);
	list_add(&myList, stu + 0);
	printList(&myList);
	list_add(&myList, stu + 1);
	printList(&myList);
	list_add(&myList, stu + 2);
	printList(&myList);
	list_add(&myList, stu + 3);
	printList(&myList);
	list_add(&myList, stu + 4);
	printList(&myList);

	// ������ ����
	list_set(&myList, 0, stu + 5);
	list_set(&myList, 2, stu + 5);
	printList(&myList);

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList));

	//������ ��ȸ
	Data data;
	if (list_get(&myList, 0, &data)) { printData(&data); printf("\n");}
	if (list_get(&myList, 6, &data)) { printData(&data); printf("\n"); }
	if (list_get(&myList, 4, &data)) { printData(&data); printf("\n"); }
	printf("\n");

	// ������ ����
	list_remove(&myList, 0);
	list_remove(&myList, 3);
	printList(&myList);
	list_remove(&myList, 0);
	list_remove(&myList, 1);
	printList(&myList);
	list_remove(&myList, 0);
	list_remove(&myList, 0);
	printList(&myList);


	// �˻����� üũ
	// �ϴ� 
	int i;
	for (i = 0; i < 3000; i++)
	{
		list_add(&myList, stu + 0);
	}

	clock_t start, end;
	long result;
	int sum = 0;
	int j;

	printf("clock() ��������\n");
	start = clock(); //�ð� ���� ����

	for (j = 0; j < 1000; j++)
	{
		for (i = 0; i < 2000; i++)
		{
			list_get(&myList, i, &data);
		}
	}


	end = clock(); //�ð� ���� ��
	result = end - start;
	printf("%ld ms\n", result);




	list_destroy(&myList);

	printf("���α׷��� �����մϴ�. �ƹ�Ű�� �����ּ���\n");
	_getch();
	return 0;
} // end main()