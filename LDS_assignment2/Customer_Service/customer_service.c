#include "customer_service.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

static Customer *_new_Customer(int32_t id, const char name[]){
    Customer *c = malloc(sizeof(Customer));
    if (c == NULL)
        return NULL;
    c->id = id;
    strncpy(c->name, name, sizeof(c->name) - 1);
    c->name[sizeof(c->name) - 1] = '\0';
    return c;
}

void customer_add(int32_t id, const char name[], Queue *curr, QueueResult *mdata){
    Customer *c = _new_Customer(id, name);
    Queue_enqueue(curr, c, mdata);
}

void customer_checkout(Queue *curr, QueueResult *mdata, Stack history, StackResult *res){
    Queue_dequeue(curr, mdata);
    if (mdata->status == QUEUE_OK) {
        stack_push(history, mdata->data, res);
    }
}

void customer_undo(Stack history, StackResult *res, Queue *curr, QueueResult *mdata){
    stack_pop(history, res);
    if (res->status == STACK_OK) {
        Queue_enqueue(curr, res->data, mdata);
    }
}

void customer_served_display(Stack history){
    if (history == NULL) return;
    int32_t count = history->top;
    for (int i = 0; i <= count; i++) {
        Customer *c = (Customer *)history->data[i];
        if (c != NULL) {
            printf("| %d | %s |\n", c->id, c->name);
        }
    }
}

void customer_waiting_display(Queue *curr){
    if (curr == NULL) return;
    int32_t count = curr->count;
    int32_t size = curr->size;
    int32_t head = curr->head;
    int i = 0;
    while (i++ < count) {
        Customer *c = (Customer *)curr->data[head];
        if (c != NULL) {
            printf("| %d | %s |\n", c->id, c->name);
        }
        head = (head + 1) % size;
    }
}

int main(int argc, char const *argv[])
{
    Stack history = stack_new(50);
    StackResult sr = {NULL, 0};
    StackResult *res = &sr;

    Queue que = Queue_new(50);
    Queue *curr = &que;
    QueueResult qr = {NULL, 0};
    QueueResult *mdata = &qr;

    customer_add(1, "Jay", curr, mdata);
    assert(curr->count == 1);
    customer_add(2, "Yoyo", curr, mdata);
    assert(curr->count == 2);
    customer_checkout(curr, mdata, history, res);
    assert(curr->count == 1);
    assert(history->top == 0);

    stack_delete(history);
    return 0;
}