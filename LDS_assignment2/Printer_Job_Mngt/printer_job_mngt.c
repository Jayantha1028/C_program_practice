#include "printer_job_mngt.h"

Queue print_new(){
    Queue que = Queue_new(50);
    Queue *curr = &que;
    assert(curr!=NULL);
    return *curr;
}


Queue* print_add(Print* p,Queue *curr,QueueResult mdata){

}
Queue* print_delete(Print* p,Queue *curr,QueueResult mdata){

}
Queue* print_restore(Stack* history,StackResult *res,Queue *curr,QueueResult mdata){

}
Queue* print_waiting(Queue *curr,QueueResult mdata){

}
Queue* print_completed(Stack* history,StackResult *res){
    
}


int main(){
    Stack history = stack_new(50);
    StackResult sr = {NULL, 0};
    StackResult *res = &sr;

    
    QueueResult qr = {NULL, 0};
    QueueResult *mdata = &qr;



    return 0;
}