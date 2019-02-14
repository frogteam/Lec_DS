#include <stdio.h>


int main()
{
	// 배열 선언, 초기화
	{
		int arr[5] = {1, 2, 3, 4, 5};

		int i;
		// 배열[n]의 index 는 0 부터 ~ n - 1 까지
		for(i = 0; i < 5; i++)
		{
			printf("arr[%d] = %d\n", i, arr[i]);
		}

		// 이때 arr 을 배열변수라고도 하나 (본질적으로 포인터 상수 다)
		printf("arr = %d\n", arr);  
		printf("arr = %p\n", arr);  

		// 배열과 sizeof() 연산자
		printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));
		printf("sizeof(arr) = %d\n", sizeof(arr));  // 배열변수의 sizeof 값은 배열전체 size값.

		// 배열의 length (길이)
		// 배열원소의 개수
		printf("length = %d\n", sizeof(arr) / sizeof(arr[0]));		
	}

	// 다차원 배열... pass
	// DataStructure 는 1차원 배열이면 족할듯?

	return 0;
}