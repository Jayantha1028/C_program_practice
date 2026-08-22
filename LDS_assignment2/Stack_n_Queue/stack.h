#ifndef stack_h_included
#define stack_h_included
#include<stdint.h>

typedef struct _stack_* Stack;

#define MAX_DEPTH 32

struct _stack_{
    uint32_t size;
    int32_t top;
    void *data[MAX_DEPTH];
};

typedef struct _Stack_Result_ StackResult;

#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 3

struct _Stack_Result_ {
    void *data;
    uint32_t status;
};

Stack stack_new(int32_t size);
void stack_delete(Stack stk);
uint32_t stack_full(Stack stk);
uint32_t stack_empty(Stack stk);
Stack stack_push(Stack stk, void *ele, StackResult *res);
Stack stack_pop(Stack stk, StackResult *res);
Stack stack_peek(Stack stk, StackResult *res);

#endif
