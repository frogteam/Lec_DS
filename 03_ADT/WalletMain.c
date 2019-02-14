#include <stdio.h>
#include "Wallet.h"

int main()
{
	Wallet myWallet;  // ���� ����

	wlt_init(&myWallet); // ���� �ʱ�ȭ
	wlt_put_coin(&myWallet, 2);  // ���� ���� : 500�� x 2�� 
	wlt_put_bill(&myWallet, 1);  // ���� ���� : 1000�� x 1��
	
	printf("�ܾ� %d\n", wlt_balance(&myWallet)); // �ܾ� : 2000��

	wlt_take_coin(&myWallet, 2);  // ���� ����
	wlt_take_bill(&myWallet, 2);  // ���� ���� : ����

	printf("�ܾ� %d\n", wlt_balance(&myWallet)); // �ܾ� : 1000��
	return 0;
}
