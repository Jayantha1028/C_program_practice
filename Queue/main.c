#include "queue.h"
#include<assert.h>

void initialize(){
    Queue que= Queue_new(10);
    Queue *q=&que;
    assert(q->count==0);
    assert(q->size==10);
    QueueResult r={0,3};
    QueueResult* res=&r;
    assert(Queue_empty(q)==1);
    Queue_enqueue(q,10,res);
    assert(res->status==1);
    Queue_dequeue(q,res);
    assert(q->count==0);
    return;
}

int main(){
    initialize();
    return 0;
}