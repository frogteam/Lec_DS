#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**
	����ü
**/

int main(int argc, char** argv)
{
	{
		struct Student
		{
			int age;
			char gender;
		};

		struct Student stu1;

		// ����ü ��� ����  :  ������ٿ����� (memeber access operator) .(dot) ���
		stu1.age = 10;
		stu1.gender = 'F';


		// ����ü ������
		struct Student *pStu;
		pStu = &stu1;

		// ������ �����ͷ� ��� ���� : -> (arrow operator) ���
		pStu->age = 10;
		pStu->gender = 'M';

		printf("%d, %d\n", stu1.age, stu1.gender);
		printf("%d, %d\n", pStu->age, pStu->gender);
	}

	// ����ü�� '����'�� �� �ȿ��� �Ҹ�ȴ�
	//struct Student stu2;   // ����    


	{
		// ����ü�� size (byte) ����

		typedef struct _Student
		{
			int age;
			char gender;
		} Student;

		Student stu1;   // typedef �� ����ϸ� ��

		// ��� size	
		printf("size fo Student = %d\n", sizeof(stu1));     // ���� 5 byte �ϱ�?
	}
	
	//Student stu2;    // typedef �� ������ ���� �� �������� ��ȿ�ϴ�

	{
		// ����ü �� ����Ǵ� byte padding
		// ����ü �����
		// [ 4 ] [ 4 ]
		struct Student
		{
			// �Ʒ��� 8byte  (
			/*
			char grade;
			char gender;
			int age;
			*/

			// ��Ŵ� 12byte
			char grade;
			int age;
			char gender;
		};
		
		struct Student stu1;
		printf("size fo Student = %d\n", sizeof(stu1));
	}
	

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




