#include <stdio.h>


int main()
{
	// �迭 ����, �ʱ�ȭ
	{
		int arr[5] = {1, 2, 3, 4, 5};

		int i;
		// �迭[n]�� index �� 0 ���� ~ n - 1 ����
		for(i = 0; i < 5; i++)
		{
			printf("arr[%d] = %d\n", i, arr[i]);
		}

		// �̶� arr �� �迭������� �ϳ� (���������� ������ ��� ��)
		printf("arr = %d\n", arr);  
		printf("arr = %p\n", arr);  

		// �迭�� sizeof() ������
		printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));
		printf("sizeof(arr) = %d\n", sizeof(arr));  // �迭������ sizeof ���� �迭��ü size��.

		// �迭�� length (����)
		// �迭������ ����
		printf("length = %d\n", sizeof(arr) / sizeof(arr[0]));		
	}

	// ������ �迭... pass
	// DataStructure �� 1���� �迭�̸� ���ҵ�?

	return 0;
}