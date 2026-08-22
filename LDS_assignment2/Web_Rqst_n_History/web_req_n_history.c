#include "web_req_n_history.h"

Queue* url_append(const char url[200],Queue* curr,QueueResult* mdata){
    assert(curr!=NULL && mdata!=NULL);
    Queue_enqueue(curr,&url,mdata);
    return curr;
}

Stack* url_completion(Queue* curr,QueueResult* mdata,Stack *history,StackResult* res){
    assert(curr!=NULL && mdata!=NULL && history!=NULL && res!=NULL);
    Queue_dequeue(curr,mdata);
    stack_push(history,mdata->data,res);
    return history;
}

char* url_lastItem(Stack *history,StackResult* res){
    assert(history!=NULL && res!=NULL);
    stack_peek(history,res);
    return res->data;
}

void print_waitingList(Queue* curr){
    assert(curr!=NULL);
    int32_t count=curr->count;
    int32_t head=curr->head;
    int32_t size=curr->size;
    int32_t c=0;
    for(int32_t head=curr->head;c++!=count;head=(head+1)%size){
        printf("%s\n",curr->data);
    }
}

void print_processed(Stack history){
    assert(history!=NULL);
    int32_t top=history->top;
    for(int32_t i=top;i<-1;--i){
        printf("%s\n",history->data);
    }
}