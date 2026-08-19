#ifndef stack_h_included
#define stack_h_included
#include<stdint.h>

#define MAX_DEPTH 32
typedef struct _stack_ *Stack;

struct _stack_{
	uint32_t size;
	int32_t top;
	float data[MAX_DEPTH];
};

typedef struct _stack_result_ StackResult;
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 3

struct _stack_result_{
	float data;
	uint8_t status;
};

/* Public Interfaces*/
Stack Stack_new(uint32_t size);
void stack_delete(Stack stk);
uint8_t stack_full(Stack stk);
uint8_t stack_empty(Stack stk);
Stack stack_push(Stack stk, float ele, StackResult *res);
Stack stack_pop(Stack stk, StackResult *res);
Stack stack_peek(Stack stk, StackResult *res);

#endif
