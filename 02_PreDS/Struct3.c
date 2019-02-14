#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**
	�Ű����� ����ü?  
	������ �����ͷ�!
	Call By Reference
**/

typedef struct _Node
{
	int arr[100000];
} Node;

void func1(Node node) {}   // ȣ��� Node ũ�� ��ŭ�� �Ű����� ���� �߻�

void func2(Node *pNode) {}   // ȣ��� ������ (4byte) ��ŭ�� ���� �߻�

int main(int argc, char** argv)
{
	{
		Node data;
		printf("sizeof data : %d\n", sizeof(data));    // ���� ū ����ü

		int i, loop = 100000;
		clock_t start, end;
		

		printf("clock() func1() ��������\n");
		start = clock(); //�ð� ���� ����
		for (i = 0; i < loop; i++)
		{
			func1(data);   // �Լ�ȣ��� ����ü �Ű������� ����(data -> node)�� �߻��ȴ�.  '����' ��
		}
		end = clock(); //�ð� ���� ��
		printf("%ld ms\n", end - start);

		printf("clock() func2() ��������\n");
		start = clock(); //�ð� ���� ����
		for (i = 0; i < loop; i++)
		{
			func2(&data);   // �Լ�ȣ��� ������ �Ű������� ����(&data -> pNode)�� �߻��ȴ�.
		}
		end = clock(); //�ð� ���� ��
		printf("%ld ms\n", end - start);

	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




