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
	list_add(&myList, 120);   // ������ �߰�
	list_add(&myList, 70);    // ������ �߰�
	printList(&myList);      // [100 50 100 120 70]

	// ������ ��ȸ, get()
	Data data;
	if(list_get(&myList, 4, &data))
		printf("  data=%d\n", data);
	if (list_get(&myList, 5, &data))
		printf("  data=%d\n", data);


	// ������ ����
	// �������� -> [100 50 100 120 70]
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); 
	printList(&myList);  // [40, 30, 100, 120, 30]

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList));

	// [40, 30, 100, 120, 30]
	// ������ ����
	list_remove(&myList, 2);
	printList(&myList);   // [40, 30, 120, 30]
	list_remove(&myList, 2);
	printList(&myList);   // [40, 30, 30]
	list_remove(&myList, 0);
	printList(&myList);   // [30, 30]
	list_remove(&myList, 2);  // ����
	printList(&myList);    // [30, 30]

	list_remove(&myList, 0); // [30]
	list_remove(&myList, 0); // []
	list_remove(&myList, 0);  // ����
	printList(&myList);   // []

	printf("������ ������ %d\n", list_length(&myList));  // 0

	// ������ ����
	list_insert(&myList, 0, 100);  
	printList(&myList);               // [100 ]
	list_insert(&myList, 0, 200);
	printList(&myList);                // [200 100 ]
	list_insert(&myList, 1, 400);
	printList(&myList);                 // [200 400 100 ]
	list_insert(&myList, 3, 500);
	printList(&myList);				// [200 400 100 500]
	list_insert(&myList, 6, 500);   // ����
	printList(&myList);				// [200 400 100 500]
	list_insert(&myList, 3, 600);
	printList(&myList);				// [200 400 100 600 500]

	list_add(&myList, 800);   // tail �۵����� Ȯ��
	printList(&myList);				// [200 400 100 600 500 800]
	printf("������ ������ %d\n", list_length(&myList));
	list_destroy(&myList);

	
	// �� �� ���� ArrayList ���� �ѵڿ� �� �״�� �����Ͽ� LinkedList ����
	{
		printf("--------------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("�������ϸ� ����: ������ - �ƹ�Ű�� ��������\n");
		_getch();
		
		printf("%d �� insert...\n", test_size);
		// �� list_add, list_insert, list_delete, list_get �� printf �� �ּ�ó���ϰ� ����

		// �������ϸ�
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_insert(&myList, 0, i);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("insert ��� : %ld ms ���\n", end - start);

		//----------------------------------------
		printf("�ƹ�Ű�� �����ø� ���� �׽�Ʈ �����մϴ�\n");
		_getch();
		printf("%d �� get...\n", test_size);

		// �������ϸ�
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_get(&myList, i, &data);
		}
		end = clock(); //�ð� ���� ��
		printf("get ��� : %ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ������ ���۵˴ϴ�: ������\n");
		_getch();
		printf("%d �� remove...\n", test_size);
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("remove ��� : %ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������\n");
		_getch();
		list_destroy(&myList);
	}

	

	printf("���α׷��� �����մϴ�. �ƹ�Ű�� �����ּ���\n");
	_getch();
	return 0;
} // end main()