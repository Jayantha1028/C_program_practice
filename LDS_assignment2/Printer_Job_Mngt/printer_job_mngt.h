#ifndef _printer_job_mngt_h_
#define _printer_job_mngt_h_
#include<stdint.h>
#include "../Stack_n_Queue/stack.h"
#include "../Stack_n_Queue/queue.h"

typedef struct _printer_job_mngt_ Print;


struct _printer_job_mngt_{
    int32_t job_id;
    char docName[50];
    int32_t pageCount;
};

Queue print_new();
Queue* print_add(Print* p,Queue *curr,QueueResult mdata);
Queue* print_delete(Print* p,Queue *curr,QueueResult mdata);
Queue* print_restore(Stack* history,StackResult *res,Queue *curr,QueueResult mdata);
Queue* print_waiting(Queue *curr,QueueResult mdata);
Queue* print_completed(Stack* history,StackResult *res);

#endif