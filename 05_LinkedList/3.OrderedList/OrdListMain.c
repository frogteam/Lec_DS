#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "OrdList.h"

#pragma warning(disable:4996)



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

// ���� �������� ���� �Լ�
int OrdByAgeAsc(Data *d1, Data *d2)
{
	if (d1->age < d2->age)
		return 0; 
	else
		return 1;
}

// ���� �������� ���� �Լ�
int OrdByAgeDesc(Data *d1, Data *d2)
{
	if (d1->age > d2->age)
		return 0;
	else
		return 1;
}

// ���� �������� ���� �Լ�
int OrdByGradeAsc(Data *d1, Data *d2)
{
	if (d1->grade < d2->grade)
		return 0;
	else
		return 1;
}


// ���� �������� ���� �Լ�
int OrdByGradeDesc(Data *d1, Data *d2)
{
	if (d1->grade > d2->grade)
		return 0;
	else
		return 1;
}

// �̸� �������� ���� �Լ�
// strcmp(s1, s2);
//-1: ASCII �ڵ� �������� ���ڿ�2(s2)�� Ŭ ��
//0 : ASCII �ڵ� �������� �� ���ڿ��� ���� ��
//1 : ASCII �ڵ� �������� ���ڿ�1(s1)�� Ŭ ��
int OrdByNameAsc(Data *d1, Data *d2)
{
	if(strcmp(d1->szName, d2->szName) < 0)
		return 0;
	else
		return 1;
}

int OrdByNameDesc(Data *d1, Data *d2)
{
	if (strcmp(d1->szName, d2->szName) > 0)
		return 0;
	else
		return 1;
}


int main()
{
	List myList;
	list_init(&myList);
	
	myList.fnComp = OrdByNameDesc;  //  ����

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
	list_add(&myList, stu + 5);
	printList(&myList);



	list_destroy(&myList);

	printf("���α׷��� �����մϴ�. �ƹ�Ű�� �����ּ���\n");
	_getch();
	return 0;
} // end main()