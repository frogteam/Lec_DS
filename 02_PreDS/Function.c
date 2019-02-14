#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**

**/

void incValue(int v)  // Call By Value
{
	v++;
	printf("incValue ȣ��: %d\n", v);
}

void incValue2(int *p)
{
	(*p)++;
	printf("incValue2 ȣ��: %d\n", *p);
}

// �迭 �Ű�����
void incArray(int* arr, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		arr[i]++;
	}
}

// �迭�� ���� (��������)
int* createArray(int n)
{
	int arr[3] = { n * 1, n * 10, n * 100 };
	return arr;
}

// �����Ҵ�� �迭 ����
int* createArray2(int n)
{
	int* arr = (int*)malloc(sizeof(int) * 3); 
	arr[0] = n + 1;
	arr[1] = n + 10;
	arr[2] = n + 100;
	return arr;
}


int main(int argc, char** argv)
{
	{
		// Call By Value  : ȣ�⿡ �־� ���� ��ȭ ����
		int a = 100;
		incValue(a);    
		printf("�Լ� ȣ���� : %d\n", a);  // ���� �ȵ�


		// Call By Reference : ȣ�⿡ �־� ���� ��ȭ ����
		int b = 300;
		incValue2(&b);
		printf("�Լ� ȣ���� : %d\n", b);  // ���� ��

		// C ���� �Ű������� '������' �� �Ѱ��ָ� Call By Reference  (��, ȣ���� ���� ��ȭ ����)
	}

	printf("\n");
	{
		// �迭 �̸��� �����ʹ�.   �׷��ϱ�, �迭�� �Ű������� �Ѱ����� ������, �� Call By Reference

		int arr[3] = { 10, 20, 30 };   // �迭 �̸��� �����ʹ�!
		incArray(arr, 2);   // ���� �ΰ��� 1����,  

		// �Լ� ȣ���� ��������? 
		int i;
		for (i = 0; i < 3; i++) {
			printf("%d ", arr[i]);      // ���� ����Ǿ� �ִ� --> Call By Reference
		}
		printf("\n");  
	}

	// �迭�� �����ϴ� ���, �����͸� �����ϴ� ���. ����
	printf("\n");
	{
		int* arr = createArray(3);

		printf("%d %d %d\n", arr[0], arr[1], arr[2]);   // �ſ� ����,  ����� ������ �𸣳� �׻� ������� �ʴ´�.
													//  warning C4172: ���� ���� �Ǵ� �ӽ�: arr�� �ּҸ� ��ȯ�ϰ� �ֽ��ϴ�.


		int* arr2 = createArray2(3);
		printf("%d %d %d\n", arr2[0], arr2[1], arr2[2]);  // ����� ������... �׷���...
		
		free(arr2);  // ȣ���� �ʿ��� å������ �����޸� ������ ������ ������ memory leak �߻�!  <-- C ���α׷��� ����� ��!
	}


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




