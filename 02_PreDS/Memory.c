#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**
	malloc, free
	calloc, realloc

	memcpy, memset
**/

int main(int argc, char** argv)
{
	{
		int len = 1000000;
		// �����޸��Ҵ� : Dynamic memory allocation
		int *arr = (int*)malloc(sizeof(int) * len);

		printf("arr[0]: %d\n", arr[0]);

		// �޸𸮸� �Ҵ������� �ʱ�ȭ �����ִ°͵� ����
		memset(arr, 0, sizeof(int) * len);
		printf("arr[0]: %d\n", arr[0]);

		// �ݵ�� �����޸𸮴� ��� ���Ŀ� free �Ҵ����� �ؾ� ��
		free(arr);
	}

	// free(arr);  ���ȿ��� ����ϴ� �����Ҵ�� �����ʹ� �ؾ������ �����̴�.

	// �ڡ� �޸� ���� Memory Leak �߻� ����!!!! �ڡ�



	// realloc()
	printf("\n");
	{
		// re-allocation()

		// ������ �޸� �Ҵ�� �͵��� ������ �����Ҵ� �޾Ƽ� ���뺹��
		// ���� �޸𸮿� ���� �迭 Ȯ�� ����.
		int* arr1 = (int*)malloc(sizeof(int) * 3);
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
		// arr1[3] = 40; <-- ����!

		printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);

		// Ȯ���ϱ�
		//  ������ arr1 �� �Ҵ�� ������ ���� �˴ϴ�. (���� free() ��Ű�� �ʾƵ� ��)
		arr1 = (int*)realloc(arr1, sizeof(int) * 5);
					

		arr1[3] = 40;
		printf("%d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3]);

	}






	//printf("\n�޸� �������ϸ� ���� - �ƹ�Ű�� ������ �����մϴ�\n");
	_getch();
	{
		int len = 1000000;
		// �����޸��Ҵ� : Dynamic memory allocation
		int *arr;

		// �Ǽ� ���� �ϴ� �͵�.  
		int i;
		for (i = 0; i < 100; i++)
		{
			arr = (int*)malloc(sizeof(int) * len);
			_sleep(50);  // 0.01�ʴ��� delay()  �������ϸ� Ȯ�ο�
			//free(arr);  // �������ϸ� ��
		}

		//free(arr);  // ��?

		// �� ����� ���� ���� Visual Studio 2015���� ������ �ǽð� �������ϸ� üũ
		// �������ϸ� : Profiling 
		// ���ɺм� ,  �ð����⵵, ����� ���� ���� ���α׷��м�.
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




