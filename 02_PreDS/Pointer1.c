#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#pragma warning(disable:4477)   // unsigned <--> signed ���� warning 
int main()
{
	// �ּ�
	{
		int n = 10;

		printf("n = %d\n", n);
		
		// �ּҿ����� &
		printf("n �� �ּҴ� %x\n", &n);  
		printf("n �� �ּҴ� %p\n", &n);  // �ּҿ����� &
	}

	printf("\n");

	// �ּҸ� ��� Ÿ�� : ������
	{
		int n = 100;
		int *p;   // p �� int Ÿ���� �ƴ϶� int* ������ Ÿ��!
		//p = n;   X
		p = &n;  // �����ʹ� �ּҸ� ��ƾ� �մϴ�.
		printf("p = %p, &n = %p  ���� \n", p, &n);

		// ���������� *
		printf("*p = %d, n = %d ���� \n", *p, n);
	}

	printf("\n");

	// �������� ������ (����������)
	{
		int n1 = 300, n2 = 500;
		int *p = &n1;
		int **pp = &p;  // int* ������ ������ ���� ������, Ÿ���� int**

		// QUIZ : pp ������ 300 ���� ����غ�����
		//printf("%d", ??);
		printf("**pp = %d\n", **pp);

		// QUIZ : pp ������ ����Ͽ�
		// p �� n1 �� �ƴ� n2 �� ������ �ϱ�
		// ���������� 
		// printf("%d\n", *p);  --> 500 �� ������ �ϱ�

		*pp = &n2;
		printf("*p = %d\n", *p);


		// QUIZ : pp ������ ����Ͽ�
		// n2 ����  800 ���� �ٲٱ�
		// printf("n2 = %d\n", n2); --> 800
		
		// *pp  -> p
		// **pp -> *p
		**pp = 800;

		printf("n2 = %d\n", n2);
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;


}