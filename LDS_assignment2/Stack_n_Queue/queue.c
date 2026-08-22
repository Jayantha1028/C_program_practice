#include<assert.h>
#include<stdlib.h>
#include "queue.h"

/* Public Interfaces*/
Queue Queue_new(uint32_t size){
	size=(size>0 && size < MAX_DEPTH)? size: MAX_DEPTH;
	Queue q={size,0,0,0,{NULL}};
	return q;
}

uint8_t Queue_full(Queue *q){
	assert(q != NULL);
	return (q->count==q->size);
}

uint8_t Queue_empty(Queue *q){
	assert(q!=NULL);
	return (q->count==0);
}

Queue* Queue_enqueue(Queue *q, void *ele, QueueResult *res){
	assert(q!=NULL);
	assert(res != NULL);
	if (q->count<q->size){
		q->data[q->tail]=ele;
		q->tail=(q->tail+1)%(q->size);
		++q->count;
		res->status=QUEUE_OK;
	}else
		res->status=QUEUE_FULL;
	assert(res->status==QUEUE_OK || q->count==q->size);
	return q;
}

Queue* Queue_dequeue(Queue *q, QueueResult *res){
	assert(q!=NULL);
	assert(res != NULL);
	if (q->count>0){
		res->data=q->data[q->head];
		q->head=(q->head+1)%(q->size);
		--q->count;
		res->status=QUEUE_OK;
	}else{
		res->data = NULL;
		res->status=QUEUE_EMPTY;
	}
	assert(res->status==QUEUE_OK || q->count==0);
	return q;
}
