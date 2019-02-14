#include <stdio.h>
#include "Wallet.h"

int main()
{
	Wallet myWallet;  // 지갑 생성

	wlt_init(&myWallet); // 지갑 초기화
	wlt_put_coin(&myWallet, 2);  // 동전 삽입 : 500원 x 2개 
	wlt_put_bill(&myWallet, 1);  // 지폐 삽입 : 1000원 x 1개
	
	printf("잔액 %d\n", wlt_balance(&myWallet)); // 잔액 : 2000원

	wlt_take_coin(&myWallet, 2);  // 동전 추출
	wlt_take_bill(&myWallet, 2);  // 지폐 추출 : 실패

	printf("잔액 %d\n", wlt_balance(&myWallet)); // 잔액 : 1000원
	return 0;
}
