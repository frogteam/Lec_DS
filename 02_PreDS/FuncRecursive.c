#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)

/**
	재귀함수: recursive
**/

int fact(int n)
{
	if (n == 1) return 1;  // 종료조건

	return n * fact(n - 1);
}

typedef struct _Node
{
	int data;
	struct _Node *pNext;
} Node;


// 주어진 node 로부터 해서 끝까지
// 모든 데이터 출력 --> 재귀 함수로!

void printNode(Node *pNode)
{
	printf("%d,", pNode->data);

	if (pNode->pNext != NULL)
		printNode(pNode->pNext);

	// 자료구조에서 가장 많이 쓰이는 재귀함수 형태
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

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




