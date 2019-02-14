#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**
����ü������ ���Կ�����?
�߻��ϴ� ��������?
����ü �����Ϸ���?
����ü ����� �迭�� ������?
��� ������
**/


int main(int argc, char** argv)
{
	{
		// ����ü�� ���� ����
		typedef struct _Student
		{
			int age;
			char grade;
		}Student;

		Student stu1 = { 10, 'A' };   // ����ü ���� ����� ���ÿ� �ʱ�ȭ ����.
		Student stu2 = { 23, 'B' };

		//stu1 = { 40, 'C' };  // �ϴ� ����� ���Ŀ��� �̷� ���� �Ұ�

		printf("stu1: %d, %c\n", stu1.age, stu1.grade);
		printf("stu2: %d, %c\n", stu2.age, stu2.grade);

		stu1 = stu2;   // ����ü������ ����.  

		// ����ü������ ������ '���' �� '����' �߻�
		printf("stu1: %d, %c\n", stu1.age, stu1.grade);
		printf("stu2: %d, %c\n", stu2.age, stu2.grade);

		// �纻���� Ȯ��
		stu1.age = 50;  stu1.grade = 'D';
		printf("stu1: %d, %c\n", stu1.age, stu1.grade);
		printf("stu2: %d, %c\n", stu2.age, stu2.grade);
	}

	printf("\n");
	{
		// ����ü ����� �迭�� �ִٸ�?
		// ����ü ����� ��� �����ϳ�?
		typedef struct _Student
		{
			char name[10];  // �迭  (����ũ��)
			int age;
			char grade;
		}Student;

		Student stu1 = { "Choi", 19, 'A' };
		Student stu2;

		stu2 = stu1;  // ����ȴ�.  Ȯ���غ���

		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);   // ����Ȯ��!
		// ���� '�迭' ����� ���簡 �ȴ�!?!?!

		// ���� ����? Ȯ���غ���
		sprintf(stu1.name, "%s", "Lee");  // stu1 �� ����
		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // stu2 �� ��ȭ����
	}

	printf("\n");
	{
		// ����!  ����ü ����� �����Ͷ��??
		typedef struct _Student
		{
			char *name;  // �����ʹ�!!
			int age;
			char grade;
		}Student;


		Student stu1;
		stu1.name = (char*)malloc(sizeof(char) * 20);
		sprintf(stu1.name, "%s", "Jacob");
		stu1.age = 40;
		stu1.grade = 'F';

		Student stu2;
		
		stu2 = stu1;  // ����ȴ�.  Ȯ���غ���

		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);   // ����Ȯ��!
		// ���� '�迭' ����� ���簡 �ȴ�!?!?!

		// ���� ����? Ȯ���غ���
		sprintf(stu1.name, "%s", "Lee");  // stu1 �� ����
		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // ��stu2 �� ����Ǿ��١�


		// ����: �������� ���縸 �߻���.
		// ����ü���� ������ ��� ����� �ſ� ���� ���

		// �� �ɰ��Ѱ�
		// stu1 �� ���� ������ ���
		free(stu1.name);
		
		printf("stu1.name ��ü��\n");
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // ���� ���� ����!!

		// ���� ���� ���� ���� ���� (shallow copy) ��� ��.
		
		// �ذ��Ϸ��� ���� ���� (deep copy) �� �ؾ� ��
	}

	printf("\n");
	{
		// ���� ���� deep copy 
		// ����ü ���簡 �߻��Ҷ�
		// �����޸�
		typedef struct _Student
		{
			char *name;  // �����ʹ�!!
			int age;
			char grade;
		}Student;

		Student stu1;
		stu1.name = (char*)malloc(sizeof(char) * 20);
		sprintf(stu1.name, "%s", "Jacob");
		stu1.age = 40;
		stu1.grade = 'F';

		Student stu2;
		// ���� ����
		stu2.name = (char*)malloc(sizeof(char) * 20);
		strcpy(stu2.name, stu1.name);
		stu2.age = stu1.age;
		stu2.grade = stu1.grade;

		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);   // ����Ȯ��!
		// ���� '�迭' ����� ���簡 �ȴ�!?!?!

		// ���� ����? Ȯ���غ���
		sprintf(stu1.name, "%s", "Lee");  // stu1 �� ����
		printf("stu1 %s %d %c\n", stu1.name, stu1.age, stu1.grade);
		printf("stu2 %s %d %c\n", stu2.name, stu2.age, stu2.grade);  // stu2 �� �״��!

		free(stu1.name);
		free(stu2.name);
	}


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




