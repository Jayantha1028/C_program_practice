#ifndef customer_service_h_included
#define customer_service_h_included
#include<stdint.h>
#include "../Stack_n_Queue/stack.h"
#include "../Stack_n_Queue/queue.h"
#include <stdlib.h>


#define MAX_SIZE 100
typedef struct _customer_ Customer;


struct _customer_{
    int32_t id;
    char name[40];
};

void customer_add(int32_t id, const char name[], Queue *curr, QueueResult *mdata);
void customer_checkout(Queue *curr, QueueResult *mdata, Stack history, StackResult *res);
void customer_undo(Stack history, StackResult *res, Queue *curr, QueueResult *mdata);
void customer_served_display(Stack history);
void customer_waiting_display(Queue *curr);

#endif