#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**

**/

int main(int argc, char** argv)
{
	{
		printf("argc = %d\n", argc);

		int i = 0;
		for (i = 0; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}

	}


	printf("%d\n", 1 - (2 + 3 + (4 - 5 * 6) * 7) + 8 * 9);
	printf("%d\n", 24 + 4 - 15 * 8 / (2 + 5 * 2 - 8) + 4);

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




