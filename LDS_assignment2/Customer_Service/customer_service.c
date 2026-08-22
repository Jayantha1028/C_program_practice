#include "customer_service.h"

static Customer *_new_Customer(int32_t id, const char name[]){
    Customer *c = malloc(sizeof(Customer));
    assert(c!=NULL);
    c->id = id;
    strncpy(c->name, name, sizeof(c->name) - 1);
    c->name[sizeof(c->name) - 1] = '\0';
    return c;
}

void customer_register(const int32_t id, const char name[], Queue *curr, QueueResult *mdata){
    Customer *c = _new_Customer(id, name);
    Queue_enqueue(curr, c, mdata);
}

void customer_checkout(Queue *curr, QueueResult *mdata, Stack history, StackResult *res){
    assert(history!=NULL && res!=NULL && curr!=NULL && mdata!=NULL);
    Queue_dequeue(curr, mdata);
    if (mdata->status == QUEUE_OK) {
        stack_push(history, mdata->data, res);
    }
}

void customer_undo(Stack history, StackResult *res, Queue *curr, QueueResult *mdata){
    assert(history!=NULL && res!=NULL && curr!=NULL && mdata!=NULL);
    stack_pop(history, res);
    if (res->data!=NULL) {
        Queue_enqueue(curr, res->data, mdata);
    }
}

void customer_served_display(Stack history){
    assert(history!=NULL);
    int32_t count = history->top;
    for (int i = 0; i <= count; i++) {
        Customer *c = (Customer *)history->data[i];
        printf("| %d | %s |\n", c->id, c->name);
    }
}

void customer_waiting_display(Queue *curr){
    assert(curr!=NULL);
    int32_t count = curr->count;
    int32_t size = curr->size;
    int32_t head = curr->head;
    int i = 0;
    while (i++ < count) {
        Customer *c = (Customer *)curr->data[head];
        printf("| %d | %s |\n", c->id, c->name);
        head = (head + 1) % size;
    }
}
