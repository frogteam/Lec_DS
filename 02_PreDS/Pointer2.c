#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#pragma warning(disable:4477)   // unsigned <--> signed ���� warning 

int main()
{
	// �����Ϳ� �迭
	{
		int arr[] = { 10, 20, 30 };
		printf("arr[0] : %d\n", arr[0]);
		printf("arr[0] : %d\n", arr[1]);

		printf("arr: %p\n", arr);
		//printf("&arr: %p\n", &arr);    // arr ���� &arr �� ����!!!
		//printf("&&arr: %p\n", &(&arr));  // �Ұ���
		printf("arr + 1 : %p\n", arr + 1);    // +4 ����    int* �̱� ����

		printf("*arr: %d\n", *arr);
		printf("*(arr + 1) : %d\n", *(arr + 1));

		// �迭 ÷�� ������ �� ������ �������� �����!!
		// ����:  arr[n] <=> *(arr + n)
	}

	// ������ ���� +, -
	{
		short arr[] = { 10, 20, 30 };

		short *p = arr;

		printf("p : %p\n", p);
		printf("p + 1 : %p\n", p + 1);  // +2 ����

		// TODO 
		// p �� ����Ͽ� 
		// arr �� [2] ��° ���� ���� 50 ���� �ٲٱ�
		// printf("arr[2] : %d\n", arr[2]); --> 50
		*(p + 2) = 50;
		p[2] = 50;   // �̷��� �ص� �ȴ�
		printf("arr[2] : %d\n", arr[2]);

	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;

}