
#include "customer_service.h"

int main(int argc, char const *argv[])
{
    Stack history = stack_new(50);
    StackResult sr = {NULL, 0};
    StackResult *res = &sr;

    Queue que = Queue_new(50);
    Queue *curr = &que;
    QueueResult qr = {NULL, 0};
    QueueResult *mdata = &qr;

    assert(curr!=NULL && mdata!=NULL && history!=NULL && res!=NULL);

    customer_register(1, "Jay", curr, mdata);
    assert(curr->count == 1);
    customer_register(2, "Yoyo", curr, mdata);
    assert(curr->count == 2);
    customer_checkout(curr, mdata, history, res);
    assert(curr->count == 1);
    assert(history->top == 0);

    stack_delete(history);
    return 0;
}