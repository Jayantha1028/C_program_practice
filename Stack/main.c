#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack stk = stack_new(3);
    StackResult res;

    stack_push(stk, 10.0f, &res);
    printf("Pushed: %.2f\n", res.data);

    stack_push(stk, 20.0f, &res);
    printf("Pushed: %.2f\n", res.data);

    stack_peek(stk, &res);
    printf("Peek: %.2f\n", res.data);

    stack_pop(stk, &res);
    printf("Popped: %.2f\n", res.data);

    stack_delete(stk);
    return 0;
}
