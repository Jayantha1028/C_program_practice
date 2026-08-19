#ifndef queue_h_included
#define queue_h_included
#include<stdint.h>

#define MAX_DEPTH 32
typedef struct _queue_ Queue;

struct _queue_{
	uint32_t size;
	uint32_t count;
	uint32_t head;
	uint32_t tail;
	int32_t data[MAX_DEPTH];
};

typedef struct _queue_result_ QueueResult;
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 3

struct _Queue_result_{
	int32_t data;
	uint8_t status;
};

/* Public Interfaces*/
Queue Queue_new(uint32_t size);
uint8_t Queue_full(Queue* q);
uint8_t Queue_empty(Queue* q);
Queue* Queue_enqueue(Queue* q, int32_t ele, QueueResult *res);
Queue* Queue_dequeue(Queue *q, QueueResult *res);

#endif
