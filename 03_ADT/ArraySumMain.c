#include <stdio.h>

int main()
{
	// 배열의 선언 : 자료구조
	int arr[5] = {1, 2, 3, 4, 5};

	// 배열에 저장된 값의 합 구하기 : 알고리즘
	int sum = 0, i = 0;
	for(i = 0; i < 5; i++)
		sum += arr[i];

	return 0;
}

