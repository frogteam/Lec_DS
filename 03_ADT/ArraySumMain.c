#include <stdio.h>

int main()
{
	// �迭�� ���� : �ڷᱸ��
	int arr[5] = {1, 2, 3, 4, 5};

	// �迭�� ����� ���� �� ���ϱ� : �˰���
	int sum = 0, i = 0;
	for(i = 0; i < 5; i++)
		sum += arr[i];

	return 0;
}

