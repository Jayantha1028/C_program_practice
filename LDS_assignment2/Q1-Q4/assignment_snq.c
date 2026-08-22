#include "assignment_snq.h"


uint8_t ispalindrome(const int32_t size,char str[]){
    assert(str!="");
    Stack s = stack_new(size);
    assert(s!=NULL);
    StackResult sr={0,0};
    StackResult *res=&sr;
    Queue que = Queue_new(size);
    Queue *q=&que;
    assert(q!=NULL);
    QueueResult qr={0,0};
    QueueResult *mdata=&qr;
    char c; 
    uint8_t pal=1;
    for(int i=0;i<size;i++){
        stack_push(s,&str[i],res);
        Queue_enqueue(q,&str[i],mdata);
    }
    for(int i=0;i<size;i++){
        stack_pop(s, res);
        Queue_dequeue(q, mdata);

        if (*(char *)res->data != *(char *)mdata->data) {
            pal=0;
            break;
        }
    }
    stack_delete(s);
    return pal;
} 



int32_t *reverse_k_ele(int32_t arr[],const uint32_t len, uint32_t k){
    assert(arr!=NULL);
    k=(k>len)?len:k;
    int32_t temp[k];
    Stack s = stack_new(k);
    assert(s!=NULL);
    StackResult sr={NULL,0};
    StackResult *res=&sr;
    for(int i=0;i<k;i++)
        stack_push(s,&arr[i],res);
    for (int32_t i = 0; i < k; i++) {
        stack_pop(s, res);
        temp[i] = *(int32_t *)res->data;
    }
    for (int32_t i = 0; i < k; i++)
        arr[i] = temp[i];
    stack_delete(s);
    return arr;
}

int32_t *reverse_array(int32_t arr[],const uint32_t len){
    assert(arr!=NULL);
    return reverse_k_ele(arr,len,len);
}


int32_t *even_odd_sorting(int32_t arr[],uint32_t len){
    assert(arr!=NULL);
    int even_count=0;
    for(int i=0;i<len;i++)
        if (arr[i]%2==0)
            ++even_count;
    Queue even = Queue_new(even_count);
    Queue *evenq=&even;
    assert(evenq!=NULL);
    QueueResult qr1={NULL,0};
    QueueResult *mdata1=&qr1;
    Queue odd = Queue_new(len-even_count);
    Queue *oddq=&odd;
    assert(oddq!=NULL);
    QueueResult qr2={NULL,0};
    QueueResult *mdata2=&qr2;
    for(int i=0;i<len;i++){
        if (arr[i]%2==0)
            Queue_enqueue(evenq,&arr[i],mdata1);
        else
            Queue_enqueue(oddq,&arr[i],mdata2);
    }
    int32_t temp[len-even_count];
    for(int i=0;i<len-even_count;i++){
        Queue_dequeue(oddq,mdata2);
        temp[i]=*(int32_t *)mdata2->data;
    }
    for(int i=0;i<even_count;i++){
        Queue_dequeue(evenq,mdata1);
        arr[i]=*(int32_t *)mdata1->data;
    }
    for(int i=even_count;i<len;i++)
        arr[i]=temp[i-even_count];
    
    return arr;
}

