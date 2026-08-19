#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"

Stack Stack_new(uint32_t size){
	size=(size>0 && size < MAX_DEPTH)? size: MAX_DEPTH;
	Stack stk=(Stack) malloc(sizeof( struct _stack_));
	assert(stk!=NULL);
	stk->size=size;
	stk->top=-1;
	memset(stk->data,0,sizeof(stk->data));
	return stk;
}

void delete_stack(Stack stk){
	assert(stk!=NULL);
	free(stk);
}

uint8_t stack_full(Stack stk){
	assert(stk!=NULL);
	return (stk->top+1==stk->size);
}

uint8_t stack_empty(Stack stk){
	assert(stk!=NULL);
	return (stk->top==-1);
}

Stack stack_push(Stack stk, float ele, StackResult *res){
	assert(stk!=NULL);
	if (stk->top+1<stk->size){
		stk->data[++stk->top]=ele;
		res->data=ele;
		res->status=STACK_OK;
}else
	res->status=STACK_FULL;
	assert(res->status==STACK_OK || stk->top+1==stk->size);
	return stk;
}

Stack stack_pop(Stack stk, StackResult *res){
	assert(stk!=NULL);
	if (stk->top>-1){
		res->data=stk->data[stk->top];
		--stk->top;
		res->status=STACK_OK;
	}
	else{		
	  res->status=STACK_EMPTY;
	  }
	assert(res->status==STACK_OK || stk->top==-1);
	return stk;
}


Stack stack_peek(Stack stk, StackResult *res){
	assert(stk!=NULL);
	if (stk->top>-1){
		res->data=stk->data[stk->top];
		res->status=STACK_OK;
	}else
		res->status=STACK_EMPTY;
	return stk;
}
