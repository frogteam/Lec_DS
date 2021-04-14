#include <stdio.h>
#include "Wallet.h"

int main()
{
	Wallet myWallet;  // 지갑 생성

	wlt_init(&myWallet); // 지갑 초기화
	wlt_put_coin(&myWallet, 2);  // 동전 삽입 : 500원 x 2개 
	wlt_put_bill(&myWallet, 1);  // 지폐 삽입 : 1000원 x 1개
	
	printf("잔액 %d\n", wlt_balance(&myWallet)); // 잔액 : 2000원

	wlt_put_coin(&myWallet, 3); // 동전삽입 : 500원 x 3개
	wlt_put_bill(&myWallet, 4); // 지폐삽입 : 1000원 x 4개

	printf("잔액 %d\n", wlt_balance(&myWallet));  // 잔액 : 7500원

	wlt_take_coin(&myWallet, 4);  // 동전 추출
	wlt_take_bill(&myWallet, 2);  // 지폐 추출
	printf("잔액 %d\n", wlt_balance(&myWallet));  // 잔액 : 3500원

	wlt_take_coin(&myWallet, 2);  // 추출 실패
	wlt_take_bill(&myWallet, 10); // 추출 실패

	return 0;
}
