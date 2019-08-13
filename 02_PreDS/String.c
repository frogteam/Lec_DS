#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)

/**
	���ڿ� 1
**/

int main(int argc, char** argv)
{
	// �켱 �뷮�� ���� �Ű� ��� �Ѵ�
	{
		char name[10] = "Kim";
		printf("name: %s\n", name);
		printf("sizeof name[10] : %d\n", sizeof(name));   // 10 �� ���´�!   name��  char[] �̱� ����

		// ���ڿ��� �⺻������ char �� �迭�̴�   :  name �� char[] �迭.  ������ char* ����̴�.
		printf("%c, %c, %c, \n", name[0], name[4], name[5]);

		// name�� �������̱� ������ �Ʒ��� ���� ������ ���� ����
		printf("%c, %c, %c, \n", *(name + 0), *(name + 4), *(name + 5));


		name[0] = 'J';  // ����!
		printf("name: %s\n", name);

		//name = "Lee";   // �Ұ�   name �� char[]  ��  ������ �����
	}

	printf("\n");
	{
		char name[] = "Hello";   // size 6 ¥�� char[] �迭 �����Ǿ� ����
		printf("name: %s\n", name);
		printf("sizeof name[] : %d\n", sizeof(name));  // 6 �� ���´�.  'H', 'e', 'l', 'l', 'o', '\0'  
		printf("%c, %c, %c, \n", name[0], name[4], name[5]);
		name[0] = 'J';  // ����!
		printf("name: %s\n", name);
		//name = "Lee";   // �Ұ�   name �� char[]  ��  ������ �����
	}

	printf("\n");
	{
		char *name = "Lake";    // name �� char* �� ������ ������  ,  �׷��� "Lake" �� ��� ������ ����
		printf("name: %s\n", name);
		printf("sizeof *name : %d\n", sizeof(name));  // 4 ��!     �� ?  name �� char* �̱� ����
		printf("%c, %c, %c, \n", name[0], name[2], name[4]);
		//name[0] = 'J';  // �Ұ�!   ��������̶� �ǵ帱�� ����.
		//printf("name: %s\n", name);

		name = "Lee";   // ����!!!
		printf("name: %s\n", name);
	}

	printf("\n");
	{
		// �⺻ ���ڿ� �Լ�

		// strlen()
		char name1[10] = "man";
		printf("strlen(name1): %d\n", strlen(name1));    // ����� sizeof() �� ���ڿ� ���� ���� ����!

		//name1[3] = 'o';   // ������ 'o';
		//printf("strlen : %d\n", strlen(name1));  // ����?

		char name2[10] = "This is SPARTA!!";   // VS ������ warning �����.
		printf("strlen(name2) : %d\n", strlen(name2));   // ��� ����
		printf("name2 : %s\n", name2);

	}

	printf("\n");
	{
		// strcpy()
		char name1[10] = "man";
		char name2[10];
		strcpy(name2, name1);  // name2 <-- name1
		printf("name2 : %s\n", name2);    // �� byte �� copy �Ǿ���?


		// �Ǽ� ���ɼ�1!
		char *title1 = "Gozilla";
		char *title2;
		//strcpy(title2, title1);   // ��!!!!  ������ �ƴϳ�.  ���� �߻�.  title2 ���� �����ּ����� �˰�??
		//printf("title2: %s\n", title2);     // 

		// �Ǽ� ���ɼ�2
		title2 = "King Kong";
		//strcpy(title2, title1);     // ������ �ƴϳ�.  ������?  ��ǻ� ����.   ��� ������ �ǵ帲
		//printf("title2: %s\n", title2);     // 

		// strcpy �ҽ�
		// ���� �޴� �� (destination) �� 
		// �޸� ������ Ȯ���� �Ҵ�� ���¿��� �Ұ�!!
		// ex) �迭, �����޸�

		title2 = (char*)malloc(20);
		strcpy(title2, title1);
		printf("title2: %s\n", title2);
		free(title2); title2 = NULL;  // ���� �޸� �Ҵ��� �ݵ�� ���߿� �Ҵ���ü �ϱ�.
	}

	printf("\n");
	{
		// strcmp()
		// ������ 0,

		char* str1 = "abc";
		char* str2 = "abc";

		printf("strcmp() : %d\n", strcmp(str1, str2));  // 0

		str2 = "def";
		printf("strcmp() : %d\n", strcmp(str1, str2));  // -1      "abc" < "def"

		str2 = "aaa";
		printf("strcmp() : %d\n", strcmp(str1, str2));   // 1      "abc" > "aaa"

		str2 = "ABC"; // ����?
		printf("strcmp() : %d\n", strcmp(str1, str2));   // 1       "abc" > "ABC"  �빮�ں��� �ҹ��ڰ� �ξ� �ڿ� �ִ�.

		printf("a:%d, A:%d\n", 'a', 'A');
	}



	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




