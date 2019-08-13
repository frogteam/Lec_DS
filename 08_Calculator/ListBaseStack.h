#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS	1
#define FAIL	0

/* 스택의 데이터 */
#ifndef __NODE_DATA__
#define __NODE_DATA__
typedef char Data;     // 기본 데이터 타입

typedef struct _node
{
	Data *str;
	struct _node *pNext;
} Node;
#endif

typedef struct _listStack
{
	Node *pTop;	                           // 이번 예제에서는 numData 유지 안함  (몇개가 있는지는 다루지 않음)
} ListStack;

typedef ListStack Stack;

/* 스택의 동작 */
void stack_init(Stack *pStack);
void stack_destroy(Stack *pStack);

int stack_is_empty(Stack *pStack);     // 스택이 비었는지 확인

int stack_push(Stack *pStack, Data *pData);   // top 에 데이터 넣기  ★
int stack_pop(Stack *pStack, Data *pData);       // top 의 데이터 꺼내기
int stack_peek(Stack *pStack, Data *pData);      // top 데이터 미리 보기

#endif