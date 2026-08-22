#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack stack_new(int32_t size)
{
    size = (size > 0 && size <= MAX_DEPTH) ? size : MAX_DEPTH;

    Stack stk = (Stack)malloc(sizeof(struct _stack_));
    assert(stk != NULL);

    stk->size = size;
    stk->top = -1;
    memset(stk->data, 0, sizeof(stk->data));

    return stk;
}

void stack_delete(Stack stk)
{
    assert(stk != NULL);
    free(stk);
}

uint32_t stack_full(Stack stk)
{
    assert(stk != NULL);
    return stk->top + 1 == (int32_t)stk->size;
}

uint32_t stack_empty(Stack stk)
{
    assert(stk != NULL);
    return stk->top == -1;
}

Stack stack_push(Stack stk, void *ele, StackResult *res)
{
    assert(stk != NULL);

    if (stack_full(stk)) {
        res->status = STACK_FULL;
        return stk;
    }

    stk->data[++stk->top] = ele;
    res->data = ele;
    res->status = STACK_OK;
    return stk;
}

Stack stack_pop(Stack stk, StackResult *res)
{
    assert(stk != NULL);

    if (stack_empty(stk)) {
        res->status = STACK_EMPTY;
        return stk;
    }

    res->data = stk->data[stk->top--];
    res->status = STACK_OK;
    return stk;
}

Stack stack_peek(Stack stk, StackResult *res)
{
    assert(stk != NULL);
    assert(res != NULL);

    if (stack_empty(stk)) {
        res->status = STACK_EMPTY;
        res->data = NULL; 
        return stk;
    }

    res->data = stk->data[stk->top];
    res->status = STACK_OK;
    return stk;
}
