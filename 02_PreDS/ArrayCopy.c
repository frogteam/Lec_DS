#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)
#pragma warning(disable:4477)   // unsigned <--> signed ���� warning 

void printArr(int *arr, int length)
{
	int i;
	printf("[");
	for (i = 0; i < length; i++)
	{
		printf("%d,", arr[i]);
	}
	printf("]\n");
}

int main()
{
	{
		// �迭�� ����?
		int arr1[3] = { 10, 20, 30 };
		int arr2[3];
		int len = 3;

		// arr2 = arr1;   // �Ұ�!!!   �迭������ ������ �����!
							// arr2 ��ü�� ���ٲ۴�.
		
		// ���1 : for��
		int i;
		for (i = 0; i < len; i++)
			arr2[i] = arr1[i];

		printArr(arr2, len);


		// ���2 : memcpy
		memcpy(arr2, arr1, sizeof(arr1));
		printArr(arr2, len);


		
	}

	{
		// memcpy() �� for ���� ������ �ξ� �ռ���.

		int len = 10000;   // 10000 ��¥�� int[] �迭 ����
		int *arr1 = (int*)malloc(sizeof(int) *  len);
		int *arr2 = (int*)malloc(sizeof(int) *  len);

		int i, cnt, loop = 100000;
		clock_t start, end;

		printf("clock() for ��������\n");
		start = clock(); //�ð� ���� ����
		for (cnt = 0; cnt < loop; cnt++)
		{
			for (i = 0; i < len; i++)
				arr2[i] = arr1[i];
		}
		end = clock(); //�ð� ���� ��
		printf("%ld ms\n", end - start);


		printf("clock() memcpy ��������\n");
		start = clock(); //�ð� ���� ����
		for (cnt = 0; cnt < loop; cnt++)
		{
			memcpy(arr2, arr1, sizeof(int) * len);
		}
		end = clock(); //�ð� ���� ��
		printf("%ld ms\n", end - start);

	}

	{
		// ���ڿ� - �迭 ����
		char *szName = "Hello World";
		char arrName[20];
		char arrName2[20];

		// arrName = szName   // �翬�� �ȵȴ�.

		// ���1 : ���ڿ� �Լ� ���
		strcpy(arrName, szName);
		printf("%s\n", arrName);

		// ���2 : memcpy ����
		memcpy(arrName2, szName, strlen(szName) + 1);  //  \0 ���� ���� �ʱ�
		printf("%s\n", arrName2);

	}

	printf("\n");
	{
		// ���ڿ� ���翡���� 
		// memcpy �� strcpy �� ������ ����ѵ�.   (���� for ���ٴ� �е������� ����)
		char str1[20] = "Hello World";
		char str2[20];

		int i, cnt, loop = 100000000;
		clock_t start, end;
		int strLen = strlen(str1);

		printf("clock() strcpy ��������\n");
		start = clock(); //�ð� ���� ����
		for (cnt = 0; cnt < loop; cnt++)
		{
			strcpy(str2, str1);
		}
		end = clock(); //�ð� ���� ��
		printf("%ld ms\n", end - start);


		printf("clock() memcpy ��������\n");
		start = clock(); //�ð� ���� ����
		for (cnt = 0; cnt < loop; cnt++)
		{
			memcpy(str2, str1, strLen + 1);
		}
		end = clock(); //�ð� ���� ��
		printf("%ld ms\n", end - start);



	}


}