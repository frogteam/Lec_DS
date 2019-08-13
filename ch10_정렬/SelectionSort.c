#include <stdio.h>

void SelSort(int arr[], int n)
{
	int i, j;
	int minIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		minIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for(j = i + 1; j < n; j++)   // �ּҰ� Ž�� (i �� ���� ���� ������)
		{
			if(arr[minIdx] > arr[j])   // Ȥ�� ������ maxIdx ������ �� ���� ���� �߰ߵǾ��ٸ�?
				minIdx = j;             // maxIdx ���� ������ �߰��� �� ���� ���� ����Ű��
		}

		// for ���� ������
		// minIdx �� ���� i + 1 ������ ���� �߿��� ���� ���� ���� ����Ű�� �������̴�.
		// �׷��� ���� i ���� minIdx �� ���� ��ȯ�ϸ� �ȴ�.

		/* ��ȯ */
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}


int main(void)
{
	int arr[4] = {3, 4, 2, 1};
	int i;

	SelSort(arr, sizeof(arr)/sizeof(int));

	for(i=0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}