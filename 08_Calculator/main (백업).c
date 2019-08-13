#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수

#include <ctype.h>   // isdigit, isalpha

#pragma warning(disable:4996)
#include "ListBaseStack.h"
#include "ListQueue.h"

// 전역 변수
#define MAX_EXPR_LENGTH  100
#define MAX_TOKEN_LENGTH 10

#define TRUE 1
#define FALSE 0

const char *g_Delim = " ";
char g_Buf[100];

void test(char* expr)
{
	Stack opStack;  // operator 스택
	Queue opQ;   // operand 큐

	stack_init(&opStack);
	queue_init(&opQ);

	// stack & queue 동작 테스트
	char *ptr = strtok(expr, g_Delim);
	while (ptr != NULL)
	{
		stack_push(&opStack, ptr); // 스택에 넣기
		queue_enq(&opQ, ptr); // 큐에 넣기

		printf("%s\n", ptr);
		ptr = strtok(NULL, g_Delim);  // 더이상 뽑을 토큰 없으면 ptr 은 NULL 이다
	}

	printf("스택 출력\n");
	while (!stack_is_empty(&opStack))
	{
		stack_pop(&opStack, g_Buf);
		printf("%s ", g_Buf);
	}
	printf("\n");

	printf("큐 출력\n");
	while (!queue_is_empty(&opQ))
	{
		queue_deq(&opQ, g_Buf);
		printf("%s ", g_Buf);
	}
	printf("\n");

	stack_destroy(&opStack);
	queue_destroy(&opQ);
}



// 연산자 우선순위 정보
// + -   * /
const int PRECED_PLUS = 2;
const int PRECED_MINUS = 2;
const int PRECED_MUL = 3;   // +, - 보다는 우선순위 높아야 함
const int PRECED_DIV = 3;

// 연산자 우선순위 리턴
int getPreced(char* op)
{
	if (!strcmp("+", op)) return PRECED_PLUS;
	if (!strcmp("-", op)) return PRECED_MINUS;
	if (!strcmp("*", op)) return PRECED_MUL;
	if (!strcmp("/", op)) return PRECED_DIV;
	return 0;
}

// 연산자 우선순위 비교
// 리턴값: 0 -> 같다.   음수 -> op1 < op2   양수 -> op1 > op2 
int compOp(char* op1, char* op2)
{
	return getPreced(op1) - getPreced(op2);
}

// 숫자인지 확인  ( C 언어는 이런것도 
// 참고로 isdigit 은 .. char 밖에 처리 안되서리..
int isNumber(char *str)
{
	//int len = strlen(str);
	//int i;
	//for (i = 0; i < len; i++)
	//	if(!isdigit(str[i])) return FALSE;  // 숫자 아님

	char *ep = NULL;  // end pointer 정상적으로 파싱 끝나면 숫자 끝을 가리킨
	double f = strtod(str, &ep);    // http://www.cplusplus.com/reference/cstdlib/strtod/
	if (!ep || *ep)    // 끝까지 parsing 이 끝나면 ep 가 가리키는 곳은 \0 이어야 한다.  *ep 가 \0 이 아닌 값이 나왔다는 것은 정상적인 파싱으로 끝났다는 뜻이 아님.
		return FALSE;  // 숫자 아님

	return TRUE;   // 숫자 확인
}

/*
	infix expr 의 토큰 분리 --> queue
*/
void exprTokenizer(char* expr, Queue *pq)
{
	char *delim = " \t";  // delimeter 는 공백과 탭 
	char *sepOp = "+-/*(){}[]";   // 구분해야 할 연산자, 괄호  (separator)
	char *sepNum = "0123456789.";   // 숫자 (피연산자 
	char pBuf[MAX_TOKEN_LENGTH];

	// 1. 일단 공백 단위로 토큰 분리
	// 2. 분리된 토큰 내에서 operand, operator 및 괄호 토큰 추출하여 enqueue

	char *ptr;
	ptr = strtok(expr, delim);   // 1. 일단 공백 단위로 토큰 분리
	while (ptr != NULL)
	{
		printf("공백 토큰 %s\n", ptr);  //확인용

		int i = 0, bi = 0;
		char ch = ptr[i];
		while (ch != '\0')
		{
			bi = 0;
			while (strchr(sepOp, ch) != NULL)
			{
				pBuf[bi] = ch; bi++;
				i++;  // 다음값
				ch = ptr[i];  
				if (strchr(sepOp, ch) == NULL)
				{
					pBuf[bi] = '\0';  // 토큰 마무리
					queue_enq(pq, pBuf);
					printf("토큰: %s\n", pBuf);  // 테스트용
					break;
				}
			} // end while(연산자 분리 토큰)

			bi = 0;
			while (strchr(sepNum, ch) != NULL)
			{
				pBuf[bi] = ch; bi++;
				i++;  // 다음값
				ch = ptr[i];
				if (strchr(sepNum, ch) == NULL)
				{
					pBuf[bi] = '\0';  // 토큰 마무리
					queue_enq(pq, pBuf);
					printf("토큰: %s\n", pBuf);  // 테스트용
					break;
				}
			} // end while(숫자 분리 토큰)
		}



		ptr = strtok(NULL, delim);  // 다음 토큰
	} // end while (공백 구분 토큰)

}



// infix 로 된 expr 에서 operator 와 operand 추출하여
// postfix 방식 순서로 queue 에 저장
void InfixToPostfix(char* expr, Queue *pq)
{
	char pTopBuf[10];   // 스택의 top 에 push/ pop 할 데이터 담는 버퍼

	Stack opStack;  // operator 스택
	stack_init(&opStack);

	char *token = strtok(expr, g_Delim);

	while (token != NULL)
	{
		// operand(숫자)이면 큐에 넣기
		if (isNumber(token))
		{
			queue_enq(pq, token); // 큐에 넣기
		}
		else
		{
			// operand 가 아니면.
			char op = token[0];   // 연산자 추출

			switch (op)
			{
				// 1. 연산자
				case '+':
				case '-':
				case '*':
				case '/':
					// stack 을 peek 하여 
					// 자신(op)보다 우선순위가 같거나 큰 연산자라면 pop 하여 queue에 넣기
					
					while(stack_peek(&opStack, pTopBuf))  // pop 하지 않고 일단 들여다 봄
					{
						if (0 > compOp(pTopBuf, token))  // pBuf[0] 의 우선순위가 op 보다 작으면
							break;

						stack_pop(&opStack, pTopBuf);   // pop 해서
						queue_enq(pq, pTopBuf);         // enqueue 하기
					}
					
					stack_push(&opStack, token);  // 최종적으로 자기 자신이 push 되기
					break;

				// 2.여는 괄호
				case '(':
				case '[':
				case '{':
					stack_push(&opStack, token);  // 여는 괄호는 무조건 스택으로
					break;

				// 3.닫는괄호 : 닫는 괄호는 push 하지 않고 아래 처리
				case ')':   // '(' 까지 pop 하기, ※ pop 하는 도중 다른 여는 괄호 만나면 에러
					while (stack_pop(&opStack, pTopBuf))
					{
						if (!strcmp(pTopBuf, "("))  // "(" 를 pop 하면 종료
							break;   
						
						queue_enq(pq, pTopBuf);
					}
					break;
				case ']':   // '[' 까지 pop 하기, ※ pop 하는 도중 다른 여는 괄호 만나면 에러 
					while (stack_pop(&opStack, pTopBuf))
					{
						if (!strcmp(pTopBuf, "["))  // "[" 를 pop 하면 종료
							break;

						queue_enq(pq, pTopBuf);
					}
					break;
				case '}':   // '{' 까지 pop 하기, ※ pop 하는 도중 다른 여는 괄호 만나면 에러 
					while (stack_pop(&opStack, pTopBuf))
					{
						if (!strcmp(pTopBuf, "{"))  // "{" 를 pop 하면 종료
							break;

						queue_enq(pq, pTopBuf);
					}
					break;
				
			} // end switch
		} // end if

		//printf("%s\n", token);  // 토큰 테스트 출력
		token = strtok(NULL, g_Delim);  // 더이상 뽑을 토큰 없으면 token 은 NULL 이다
	} // end while(token)

	// 토큰을 다 뽑아낸뒤
	// 스택에 남아있는 operator 는 전부 pop 하여 큐에 enqueue 하기
	// ※ 사실 이 단계에서 닫는 괄호가 스택에 남아있었다면 에러다
	while (!stack_is_empty(&opStack))
	{
		stack_pop(&opStack, pTopBuf); // pop 한것을		
		queue_enq(pq, pTopBuf);       // enque 하기
	}

	stack_destroy(&opStack);  // operator 스택 제거
}

/*
	infix expr 연산식 문자열을 받아서
	이를 evaluate 한 결과값을 리턴
*/
double calcExpr(char *expr)
{
	Queue tokQueue;   // expr 에서 추출한 token 들을 담을 큐
	Queue postQueue;  // postfix expr로 변환된 token 들을 담을 큐
	Stack opStack;  // operator 스택
	
	queue_init(&tokQueue);
	queue_init(&postQueue);
	stack_init(&opStack);

	char *pBuf[MAX_TOKEN_LENGTH];
	char *token = pBuf;

	double result = 0;   // 연산 결과값

	// 1. infix expr 문자열 -->  토큰  (tokQueue)
	exprTokenizer(expr, &tokQueue);

	// 2. infix 토근 (tokQueue)--> postfix 토큰 (postQueue)  (shauting yard algorithm)


	// 3. postfix 토큰 (postQueue) --> 계산 (result)



	stack_destroy(&opStack);
	queue_destroy(&postQueue);
	queue_destroy(&tokQueue);

	return result;
}

 



int main(int argc, char** argv)
{

	char expr[MAX_EXPR_LENGTH] = "10-20/100 +1- 2/ 88";
	//char expr[MAX_EXPR_LENGTH] = "1 - ( 2 + 3 + ( 4 - 5 * 6 ) * 7 ) + 8 * 9";
							// ↑결과 : 1 2 3 + 4 5 6 * - 7 * + - 8 9 * +
							//  산술 연산 결과  250

	//char expr[MAX_EXPR_LENGTH] = "24 + 4 - 15 * 8 / ( 2 + 5 * 2 - 8 ) + 4";
							// ↑결과 : 24 4 + 15 8 * 2 5 2 * + 8 - / - 4 +
							// 산술 연산 결과  2

	//char expr[MAX_EXPR_LENGTH] = "10 + 20";
	

	calcExpr(expr);


	//char *ep = NULL;
	//double f = strtod(".3", &ep);
	//if (ep && !(*ep))
	//	printf("%lf\n", f);
	//else
	//	printf("double 변환 불가\n");


	//int result = calcPost(&opQueue);
	//printf("계산결과: %d\n", result);

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()





