
#include "web_req_n_history.h"

int main(){
    char url[200];
    Stack history = stack_new(50);
    StackResult sr = {NULL, 0};
    StackResult *res = &sr;

    Queue que = Queue_new(50);
    Queue *curr = &que;
    QueueResult qr = {NULL, 0};
    QueueResult *mdata = &qr;

    assert(curr!=NULL && mdata!=NULL && history!=NULL && res!=NULL);

    
    return 0;
}