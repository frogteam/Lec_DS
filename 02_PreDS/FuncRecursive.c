#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**
	����Լ�: recursive
**/

int fact(int n)
{
	if (n == 1) return 1;  // ��������

	return n * fact(n - 1);
}

typedef struct _Node
{
	int data;
	struct _Node *pNext;
} Node;


// �־��� node �κ��� �ؼ� ������
// ��� ������ ��� --> ��� �Լ���!

void printNode(Node *pNode)
{
	printf("%d,", pNode->data);

	if (pNode->pNext != NULL)
		printNode(pNode->pNext);

	// �ڷᱸ������ ���� ���� ���̴� ����Լ� ����
}

int main(int argc, char** argv)
{
	{
		int n = 10;
		printf("%d! = %d\n", n, fact(10));
	}

	{
		Node node1 = { 100, NULL };
		Node node2 = { 200, &node1 };
		Node node3 = { 300, &node2 };
		Node node4 = { 400, &node3 };
		Node node5 = { 500, &node4 };

		printNode(&node5);
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




