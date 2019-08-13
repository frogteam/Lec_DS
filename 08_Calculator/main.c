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

// 연산자 우선순위 정보
// + -   * /
const int PRECED_PLUS = 2;
const int PRECED_MINUS = 2;
const int PRECED_MUL = 3;   // +, - 보다는 우선순위 높아야 함
const int PRECED_DIV = 3;


void test(char* expr)
{
	Stack opStack;  // operator 스택
	Queue opQ;   // operand 큐
	char pBuf[MAX_TOKEN_LENGTH];

	stack_init(&opStack);
	queue_init(&opQ);

	// stack & queue 동작 테스트
	char *ptr = strtok(expr, " ");
	while (ptr != NULL)
	{
		stack_push(&opStack, ptr); // 스택에 넣기
		queue_enq(&opQ, ptr); // 큐에 넣기

		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");  // 더이상 뽑을 토큰 없으면 ptr 은 NULL 이다
	}

	printf("스택 출력\n");
	while (!stack_is_empty(&opStack))
	{
		stack_pop(&opStack, pBuf);
		printf("%s ", pBuf);
	}
	printf("\n");

	printf("큐 출력\n");
	while (!queue_is_empty(&opQ))
	{
		queue_deq(&opQ, pBuf);
		printf("%s ", pBuf);
	}
	printf("\n");

	stack_destroy(&opStack);
	queue_destroy(&opQ);
}




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

// 숫자(실수)인지 확인
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

// infix expr 의 토큰 분리 --> tokQueue
void exprTokenizer(char* expr, Queue *tokQueue)
{
	char *delim = " \t";  // delimeter 는 공백과 탭 
	char *sepOp = "+-/*(){}[]";   // 구분해야 할 연산자, 괄호  (separator)
	char *sepNum = "0123456789.";   // 숫자 (피연산자 
	char pBuf[MAX_TOKEN_LENGTH];
	int i;

	// 1. 일단 공백 단위로 토큰 분리
	// 2. 분리된 토큰 내에서 operand, operator 및 괄호 토큰 추출하여 enqueue

	// 1. 일단 공백 단위로 토큰 분리
	char *ptr;
	ptr = strtok(expr, delim);   
	while (ptr != NULL)
	{
		//printf("공백 토큰 %s\n", ptr);  //확인용
		int n;   // strspn 결과 자리수 이동
		char *p = ptr;

		// 2. 분리된 토큰 내에서 operand, operator 및 괄호 토큰 추출하여 enqueue
		while (*p != '\0')
		{
			n = strspn(p, sepNum);    // 숫자로 시작하나?  숫자는 몇자리인가 --> n
			if (n > 0)  // 숫자였다면  (숫자가 아니면 n 은 0 이다)
			{
				strncpy(pBuf, p, n);   // n자리 만큼 문자열 복사
				pBuf[n] = '\0';         // 문자열 마무리는 \0  토큰 완성
				//printf("%s\n", pBuf);
				queue_enq(tokQueue, pBuf);  // 완성된 숫자(피연산자)토큰 은 enqueue
				p += n;   // 문자열 포인터는 n 만큼 이동
			}

			n = strspn(p, sepOp);    // 연산자로 시작하나?
			if (n > 0) // 연산자라면 (연산자가 아니면 n 은 0)
			{
				for (i = 0; i < n; i++)   // 연산자는 한글자 라는 전제.   n 개 만큼 연산자 토큰 발생
				{
					sprintf(pBuf, "%c", p[i]);   // 토큰
					//printf("%s\n", pBuf);
					queue_enq(tokQueue, pBuf);
				}
				p += n;  // 문자열 포인터는 n 만큼 이동
			}
		} // end while

		ptr = strtok(NULL, delim);  // 다음 토큰
	} // end while (공백 구분 토큰)

	//printf("\n토큰 분리 완료\n");
	//_getch();
}

// infix 로 된 tokQueue 에서 postfix 방식으로 postQueue 에 enqueue
void InfixToPostfix(Queue *tokQueue, Queue *postQueue)
{
	char pTopBuf[MAX_TOKEN_LENGTH];   // 스택의 top 에 push/ pop 할 데이터 담는 버퍼
	char token[MAX_TOKEN_LENGTH];

	Stack opStack;  // operator 스택
	stack_init(&opStack);

	//char *token = strtok(expr, g_Delim);

	while (!queue_is_empty(tokQueue))
	{
		queue_deq(tokQueue, token);

		// operand(숫자)이면 큐에 넣기
		if (isNumber(token))
		{
			queue_enq(postQueue, token); // 큐에 넣기
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
						queue_enq(postQueue, pTopBuf);         // enqueue 하기
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
						
						queue_enq(postQueue, pTopBuf);
					}
					break;
				case ']':   // '[' 까지 pop 하기, ※ pop 하는 도중 다른 여는 괄호 만나면 에러 
					while (stack_pop(&opStack, pTopBuf))
					{
						if (!strcmp(pTopBuf, "["))  // "[" 를 pop 하면 종료
							break;

						queue_enq(postQueue, pTopBuf);
					}
					break;
				case '}':   // '{' 까지 pop 하기, ※ pop 하는 도중 다른 여는 괄호 만나면 에러 
					while (stack_pop(&opStack, pTopBuf))
					{
						if (!strcmp(pTopBuf, "{"))  // "{" 를 pop 하면 종료
							break;

						queue_enq(postQueue, pTopBuf);
					}
					break;
				
			} // end switch
		} // end if

		//printf("%s\n", token);  // 토큰 테스트 출력
		//token = strtok(NULL, g_Delim);  // 더이상 뽑을 토큰 없으면 token 은 NULL 이다
	} // end while(token)

	// 토큰을 다 뽑아낸뒤
	// 스택에 남아있는 operator 는 전부 pop 하여 큐에 enqueue 하기
	// ※ 사실 이 단계에서 닫는 괄호가 스택에 남아있었다면 에러다
	while (!stack_is_empty(&opStack))
	{
		stack_pop(&opStack, pTopBuf); // pop 한것을		
		queue_enq(postQueue, pTopBuf);       // enque 하기
	}

	stack_destroy(&opStack);  // operator 스택 제거
}

// infix expr 연산식 문자열을 받아서 evaluate 한 결과값 리턴
double calcExpr(char *expr)
{
	Queue tokQueue;   // expr 에서 추출한 token 들을 담을 큐
	Queue postQueue;  // postfix expr로 변환된 token 들을 담을 큐
	Stack opStack;  // operator 스택
	
	queue_init(&tokQueue);
	queue_init(&postQueue);
	stack_init(&opStack);

	char pBuf[MAX_TOKEN_LENGTH];
	char *token = pBuf;

	double result = 0;   // 연산 결과값

	// 1. infix expr 문자열 -->  토큰  (tokQueue)
	exprTokenizer(expr, &tokQueue);

	// 2. infix 토근 (tokQueue)--> postfix 토큰 (postQueue)  (shauting yard algorithm)
	InfixToPostfix(&tokQueue, &postQueue);

	// 3. postfix 토큰 (postQueue) --> 계산 (result)
	// postfix 로 된 큐에서 하나하나 뽑아낸다
	while (!queue_is_empty(&postQueue))
	{
		queue_deq(&postQueue, token);

		// operand 이면 push 하고
		// operator 이면 두개 pop 해서 연산후 다시 push

		if (isNumber(token))
		{
			stack_push(&opStack, token);  // operand 이면 push 하고
		}
		else
		{
			char op = token[0];
			stack_pop(&opStack, token); // 먼저 pop 하는게 우측 피연산자다
			double right = atof(token);
			stack_pop(&opStack, token);  // 그 다음 pop 하는게 좌측 피연산자다
			double left = atof(token);


			switch (op)
			{
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '*':
				result = left * right;
				break;
			case '/':
				result = left / right;
				break;
			}

			// 연산결과는 다시 push
			sprintf(pBuf, "%.2lf", result);   // 소숫점 자리수 제한
			stack_push(&opStack, pBuf);
		}
	} // end while

	// 마지막에 스택에 남아있는 한개의 값이 연산의 결과값이다.
	stack_pop(&opStack, pBuf);
	result = atof(pBuf);


	//---------------------------------------------------------------------
	stack_destroy(&opStack);
	queue_destroy(&postQueue);
	queue_destroy(&tokQueue);

	return result;
}



int main(int argc, char** argv)
{
	// 테스트 용 infix 수식들
	char test_expr[][MAX_EXPR_LENGTH] = {
		"1 - ( 2 + 3 + ( 4 - 5 * 6 ) * 7 ) + 8 * 9",
			// ↑ post결과 : 1 2 3 + 4 5 6 * - 7 * + - 8 9 * +
			//  산술 연산 결과  250.0

		"1 - (2 + 3 + (4 - 5 * 6) * 7) + 8 * 9",
		"1-(2+3+(4-5*6)*7)+8*9",

		"24 + 4 - 15 * 8 / ( 2 + 5 * 2 - 8 ) + 4"
			// ↑ post결과 : 24 4 + 15 8 * 2 5 2 * + 8 - / - 4 +
			// 산술 연산 결과  2.0
	};

	char expr[MAX_EXPR_LENGTH];

	while (1)
	{
		printf(">");
		gets_s(expr, MAX_EXPR_LENGTH - 1);  // 문자열로 한줄 입력

		if (!strcmp(expr, "exit")) break;  // 종료
		printf("%.2lf\n", calcExpr(expr));
	}


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()





