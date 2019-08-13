#include <stdio.h>

void SelSort(int arr[], int n)
{
	int i, j;
	int minIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		minIdx = i;    // 정렬 순서상 가장 앞서는 데이터의 index

		for(j = i + 1; j < n; j++)   // 최소값 탐색 (i 값 다음 부터 끝까지)
		{
			if(arr[minIdx] > arr[j])   // 혹시 기존의 maxIdx 값보다 더 작은 것이 발견되었다면?
				minIdx = j;             // maxIdx 값은 좀전에 발견한 더 작은 값을 가리키기
		}

		// for 문이 끝나면
		// minIdx 의 값은 i + 1 부터의 원소 중에서 가장 작은 값을 가리키고 있을터이다.
		// 그러면 이제 i 값과 minIdx 의 값을 교환하면 된다.

		/* 교환 */
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