#ifndef _web_h_
#define _web_h_

#include "../Stack_n_Queue/stack.h"
#include "../Stack_n_Queue/queue.h"
#include<stdlib.h>

Queue* url_append(const char url[200],Queue* curr,QueueResult* mdata);
Stack* url_completion(Queue* curr,QueueResult* mdata,Stack *history,StackResult* res);
char* url_lastItem(Stack *history,StackResult* res);
void print_waitingList(Queue* curr);
void print_processed(Stack history);


#endif