#include "stack.h"
#include<assert.h>
void initialize(){
        Stack s=Stack_new(8);
	assert(s->size==8);
	assert(s->top==-1);
	assert(stack_empty(s)==1);
	StackResult r={0,3};
	StackResult *res= &r;
	stack_push(s,2.0f,r);
	assert(s->top==0);
	assert(res->status==1);
	assert(stack_empty(s)==0);
	assert(stack_full(s)==0);
	stack_pop(s,res);
}

int main(){
	intialize();
	return 0;
}
