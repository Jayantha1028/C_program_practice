#include "../Stack_n_Queue/stack.h"
#include "../Stack_n_Queue/queue.h"
#include<stdlib.h>

Queue* url_append(char url[200],Queue* curr,QueueResult* mdata){
    Queue_enqueue(curr,&url,mdata);
    return curr;
}

Stack* url_completion(Queue* curr,QueueResult* mdata,Stack *history,StackResult* res){
    Queue_dequeue(curr,mdata);
    stack_push(history,mdata->data,res);
    return history;
}

char* url_lastItem(Stack *history,StackResult* res){
    stack_peek(history,res);
    return res->data;
}

void print_waitingList(Queue* curr,QueueResult* res){
    int32_t count=curr->count;
    int32_t head=curr->head;
    int32_t size=curr->size;
    int32_t c=0;
    for(int32_t head=curr->head;c++!=count;head=(head+1)%size){
        printf("%s\n",curr->data);
    }
}

void print_processed(Stack history,StackResult *res){
    int32_t top=history->top;
    for(int32_t i=top;i<-1;--i){
        printf("%s\n",history->data);
    }
}

int main(){
    char url[200];
    Stack history = stack_new(50);
    StackResult sr = {NULL, 0};
    StackResult *res = &sr;

    Queue que = Queue_new(50);
    Queue *curr = &que;
    QueueResult qr = {NULL, 0};
    QueueResult *mdata = &qr;
    
    return 0;
}