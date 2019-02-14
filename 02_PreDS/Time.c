#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/*
	C, C++ ���� ���� �����ϱ�
	���1:  time() ���
	���2:  clock() ���

	C ���� ���α׷� ���� ���� ��Ű��
		_sleep() ���
*/
int main()
{
	// time() �Լ�
	{
		// ���: time.h �� time(NULL) ���
		time_t start, end;
		double result;
		int i, j;
		int sum = 0;
		printf("time() ��������\n");
		start = time(NULL); // �ð� ���� ����

		for (i = 0; i < 100000; i++) {
			for (j = 0; j < 10000; j++) {
				sum += i * j;
			}
		}

		end = time(NULL); // �ð� ���� ��
		result = (double)(end - start);
		printf("%f s\n", result); //��� ���
	}


	// �ð����� : clock() ���
	{
		// ���2 : 
		clock_t start, end;
		long result;
		int i, j;
		int sum = 0;

		printf("clock() ��������\n");
		start = clock(); //�ð� ���� ����

		for (i = 0; i < 100000; i++) {
			for (j = 0; j < 10000; j++) {
				sum += i * j;
			}
		}

		end = clock(); //�ð� ���� ��
		result = end - start;
		printf("%ld ms\n", result);
	}


	// sleep() �ֱ�
	{		
		clock_t start, end;
		long result;
		int sum = 0;

		printf("sleep() ��������\n");
		start = clock(); //�ð� ���� ����

		_sleep(5000);  // �������� ���� stdlib.h �� ����

		end = clock(); //�ð� ���� ��
		result = end - start;
		printf("%ld ms\n", result);
	}


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}
