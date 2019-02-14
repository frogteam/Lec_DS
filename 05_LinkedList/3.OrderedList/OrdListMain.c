#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   //_getch()
#include <time.h>
#include "OrdList.h"

#pragma warning(disable:4996)



// 리스트 출력 도우미 함수
void printData(Data* pData)
{
	printf("%s/%d살/%c, ", pData->szName, pData->age, pData->grade);
}
void printList(List *pList)
{
	list_first(pList);  // iteration 시작
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]\n");
}

// 나이 오름차순 정렬 함수
int OrdByAgeAsc(Data *d1, Data *d2)
{
	if (d1->age < d2->age)
		return 0; 
	else
		return 1;
}

// 나이 내림차순 정렬 함수
int OrdByAgeDesc(Data *d1, Data *d2)
{
	if (d1->age > d2->age)
		return 0;
	else
		return 1;
}

// 성적 오름차순 정렬 함수
int OrdByGradeAsc(Data *d1, Data *d2)
{
	if (d1->grade < d2->grade)
		return 0;
	else
		return 1;
}


// 성적 내림차순 정렬 함수
int OrdByGradeDesc(Data *d1, Data *d2)
{
	if (d1->grade > d2->grade)
		return 0;
	else
		return 1;
}

// 이름 오름차순 정렬 함수
// strcmp(s1, s2);
//-1: ASCII 코드 기준으로 문자열2(s2)가 클 때
//0 : ASCII 코드 기준으로 두 문자열이 같을 때
//1 : ASCII 코드 기준으로 문자열1(s1)이 클 때
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
	
	myList.fnComp = OrdByNameDesc;  //  정렬

	Data stu[] = {
		{"홍길동", 20, 'A'},
		{"James", 34, 'B'},
		{"허준", 30, 'D'},
		{"제일형", 23, 'E'},
		{"하후", 77, 'C'},
		{"마이클", 38, 'C'}
	};

	printList(&myList);
	list_add(&myList, stu + 0);   // &stu[0] 로 해도 되다
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

	printf("프로그램을 종료합니다. 아무키나 눌러주세요\n");
	_getch();
	return 0;
} // end main()