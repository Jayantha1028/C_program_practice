#include<stdlib.h> // for malloc, free function
#include<assert.h>
#include <stdio.h>
#include <limits.h>
#include "slist.h"

/* Create an empty list with min/max initialized to sentinel values. */
Slist slist_new(){  
	Slist list={NULL,NULL,0,INT_MAX,INT_MIN};
	return list;
}

/* Return the number of nodes currently linked in the list. */
int32_t slist_get_count(const Slist *list){
	assert(list!=NULL);
	return list->count;
}

/* Allocate and initialize one detached node. */
static Node* get_new_node(int32_t ele){
	Node *new_node=(Node*) malloc(sizeof(Node));  //empty node is created of Size of User defined datatype Node
	new_node->data=ele; // the newly created node is assigned the given element
	new_node->next=NULL;  
	return new_node;
}

/* Recalculate cached min and max values after structural changes. */
static void update_min_max(Slist *list){
	assert(list!=NULL);
	list->min=INT_MAX;
	list->max=INT_MIN;
	for(Node* curr=list->head;curr!=NULL;curr=curr->next){
		list->min= (list->min<curr->data)?list->min:curr->data;
		list->max= (list->max>curr->data)?list->max:curr->data;
	}
}


/* Insert a new value before the current head node. */
Slist* slist_add_head(Slist* list,int32_t ele){
	assert(list!=NULL);
	Node *new_node=get_new_node(ele);  // new node is created to attach at the head
	new_node->next=list->head;	    // the new node is attached before the head to make it the first node
	list->head=new_node;		    // update the list with new_node value as the head node
	if (list->tail==NULL)		    // if no element were present before make tail same as new_node
		list->tail=new_node;
	++list->count;			    // update the count
	list->max= (list->max>ele)?list->max:ele;
	list->min= (list->min<ele)?list->min:ele;
	return list;			    // return the list back
}

/* Append a new value after the current tail node. */
Slist* slist_add_tail(Slist* list,int32_t ele){
	assert(list!=NULL);
	Node *new_node=get_new_node(ele);// new node is created to attach at the head
	list->tail->next=new_node;// the new node is attached after the tail to make it the last node
	list->tail=new_node;// update the list with new_node value as the tail node
	if (list->head==NULL) // if no element were present before make head same as new_node
		list->head=new_node;
	++list->count;// update the count
	list->max= (list->max>ele)?list->max:ele;
	list->min= (list->min<ele)?list->min:ele;
	return list;
	}

/* Return 1 when key is found in any node; otherwise return 0. */
uint8_t slist_lookup(const Slist* list, int32_t key){
	assert(list!=NULL);
	Node* curr;
	for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
		if (curr->data==key) 
			return 1;
	}
	return 0;
	}


/* Remove the first node and refresh cached min/max when needed. */
Slist* slist_delete_head(Slist *list){
	assert(list!=NULL);
	if(list->count==0)
		return list;
	  Node* temp=list->head; // create a temp node to avoid conflict
	list->head=temp->next; // update the list with next of head node
	if(list->head==NULL)
		list->tail=NULL;
	--list->count;// update the count
	if (list->max == temp->data){
		list->max=INT_MIN;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->max= (list->max>curr->data)?list->max:curr->data;
		}
	}
	if (list->min == temp->data){
		list->min=INT_MAX;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->min= (list->min<curr->data)?list->min:curr->data;
		}
	}
	free(temp); // clear the temp location
	return list;// return the list back
	}


/* Remove the final node by walking to the node before the tail. */
Slist* slist_delete_tail(Slist *list){
	assert(list!=NULL);
	if(list->count==0){
		return list;
		}
	Node* last=list->tail; // create a last node to store tail node temporarily
	if(list->head==list->tail){
		list->head=list->tail=NULL;  // if only 1 element assign null to head and tail
		}
	else{
	        Node* curr=list->head;
		for(Node* curr=list->head;curr->next!=last; curr=curr->next); // traverse to get one before last location
		curr->next=NULL;
		list->tail=curr;
	}
	--list->count;// update the count
	if (list->max == last->data){
		list->max=INT_MIN;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->max= (list->max>curr->data)?list->max:curr->data;
		}
	}
	if (list->min == last->data){
		list->min=INT_MAX;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->min= (list->min<curr->data)?list->min:curr->data;
		}
	}
	free(last); // clear the location of last
	return list;// return the list back
	}

/* Print the list contents in traversal order. */
void slist_display(const Slist *list){
	assert(list!=NULL);
	Node* curr=list->head;
	while(curr!=NULL){
		printf("%d->",curr->data);
		curr=curr->next;
	}
	printf("NULL\n");
}


/* Insert at a valid 1-based position, delegating endpoint cases. */
Slist* slist_add_at_position(Slist* list,int32_t ele,int32_t pos){
	assert(list!=NULL);
	if (pos==1)
		return slist_add_head(list,ele);
	else if (pos==list->count+1)
		return slist_add_tail(list,ele);
	else if (pos>list->count || pos<1)
		return list;
	Node* new_node=get_new_node(ele);
	Node* curr=list->head;
	for(int i=1;i<pos-1;i++)
		curr=curr->next;
	new_node->next=curr->next;
	curr->next=new_node;
	if (new_node->next==NULL)
		list->tail=new_node;
	list->min= (list->min<new_node->data)?list->min:new_node->data;
	list->max= (list->max>new_node->data)?list->max:new_node->data;
	++list->count;
	return list;
}


/* Delete a node at a valid 1-based position and maintain list metadata. */
Slist* slist_delete_at_position(Slist* list, int32_t pos){
    assert(list!=NULL);
    if (pos < 1 || pos > list->count)
    return list;

	if (pos == 1)
    	return slist_delete_head(list);

	if (pos == list->count)
    	return slist_delete_tail(list);

    Node* curr=list->head;
    for(int i=1;i<pos-1;i++)
        curr=curr->next;
    Node* temp=curr->next;
    curr->next=curr->next->next;
	--list->count;
	if (list->max == temp->data){
		list->max=INT_MIN;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->max= (list->max>curr->data)?list->max:curr->data;
		}
	}
	if (list->min == temp->data){
		list->min=INT_MAX;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->min= (list->min<curr->data)?list->min:curr->data;
		}
	}
    free(temp);
    return list;
}


/* Insert a new node after the first node whose data matches after. */
Slist* slist_add_node_after(Slist* list, int32_t ele, int32_t after){
    assert(list!=NULL);
	Node* curr= list->head;
    while(curr != NULL){
        if (curr->data==after)
            break;
		curr= curr->next;
    }
    if (curr != NULL)
        {
        Node* new_node= get_new_node(ele);
        new_node->next= curr->next;
        curr->next= new_node;
        ++list->count;
		if (new_node->next==NULL)
			list->tail=new_node;
		list->min= (list->min<new_node->data)?list->min:new_node->data;
		list->max= (list->max>new_node->data)?list->max:new_node->data;
}
return list;
}

/* Delete the node following the first node whose data matches ele. */
Slist* slist_delete_after(Slist* list, int32_t ele){
    assert(list!=NULL);
    if (list->count<2)
        return list;
    Node* curr= list->head;
    while(curr != list->tail){
        if (curr->data==ele)
            break;
        curr= curr->next;
        }
    if (curr != list->tail)
    {
        Node* temp= curr->next;
        curr->next=temp->next;
        if (temp == list->tail)
            list->tail=curr;
		if (list->max == temp->data){
		list->max=INT_MIN;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->max= (list->max>curr->data)?list->max:curr->data;
		}
	}
	if (list->min == temp->data){
		list->min=INT_MAX;
		for(Node* curr=list->head;curr!=NULL;curr=curr->next){ //use a looping variable curr to traverse the list
			list->min= (list->min<curr->data)?list->min:curr->data;
		}
	}
        free(temp);
        --list->count;
    }
    return list;
}



/* Reverse the list links in place and move the old head to tail. */
Slist* slist_reverse(Slist* list){
    assert(list!=NULL);
    if (list->count<2)
        return list;
    Node *curr=list->head;
    Node *prev=NULL;
    Node *next=NULL;
    list->tail= list->head;
    while(curr!=NULL){
        next= curr->next;
        curr->next= prev;
        prev= curr;
        curr=next;
    }
    list->head=prev;
    return list;
}



/* Use slow/fast pointers to return the middle node value. */
int32_t slist_middle(const Slist *list){
    assert(list!=NULL);
    if (list->count==0)	return 0;
    Node *slow = list->head;
	Node *fast = list->head;
	 while (fast != NULL && fast->next != NULL) { 
		slow = slow->next; 
		fast = fast->next->next;
	}
    return slow->data;
}


/* Convert nth-from-end into an equivalent 1-based position from the head. */
Slist* slist_delete_nth_from_end(Slist *list,int32_t n){
    assert(list!=NULL);
    if (n <= 0 || n > list->count)
        return list;
    return slist_delete_at_position(list, list->count-n+1);
}


/* Floyd cycle detection: slow and fast meet only when a loop exists. */
uint8_t slist_is_loop(const Slist *list) { 
	assert(list != NULL);
	Node *slow = list->head;
	Node *fast = list->head;
	while (fast != NULL && fast->next != NULL) { 
		slow = slow->next; 
		fast = fast->next->next;
		if (slow == fast) 
			return 1;
	}
	return 0;
}


/* Split the list after the midpoint and return the second half. */
Slist* slist_split_into_two(Slist* list){
	assert(list!=NULL);
	if (list->count<2)
		return list;
	int32_t first_count = (list->count + 1) / 2;
	Node *slow = list->head;
	for(int32_t i=1;i<first_count;i++)
		slow=slow->next;
	Slist s1 = slist_new();
	Slist *second = &s1;
	second->head = slow->next;
	slow->next = NULL;
	second->tail = list->tail;
	second->count = list->count - first_count;
	list->count = first_count;
	list->tail = slow;
	update_min_max(list);
	update_min_max(second);
	return second;
}

/* Compare the first half against a temporarily reversed second half. */
uint8_t slist_is_palindrome(Slist *list){
	assert(list!=NULL);
	if (list->count==0)	return 0;
	if (list->count==1)	return 1;

	Node *slow=list->head;
	Node *fast=list->head;
	Node *prev_slow=NULL;
	while(fast!=NULL && fast->next!=NULL){
		prev_slow=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	Node *middle=NULL;
	Node *second_half=slow;
	if(fast!=NULL){
		middle=slow;
		second_half=slow->next;
	}

	prev_slow->next=NULL;
	Slist temp={second_half,list->tail,list->count/2,INT_MAX,INT_MIN};
	slist_reverse(&temp);

	uint8_t result=1;
	Node* ptr= temp.head;
	for(Node* curr=list->head; ptr!=NULL && curr!=NULL;curr=curr->next){
		if (ptr->data!= curr->data){
			result=0;
			break;
		}
		ptr=ptr->next;
	}

	slist_reverse(&temp);
	if(middle!=NULL){
		prev_slow->next=middle;
		middle->next=temp.head;
	}
	else{
		prev_slow->next=temp.head;
	}
	return result;
}


/* Remove duplicate values by scanning every following node for each value. */
Slist* slist_remove_duplicates(Slist *list)
{
    assert(list != NULL);

    if (list->count < 2)
        return list;

    Node *curr = list->head;
    while (curr != NULL)
    {
        Node *check = curr;

        while (check->next != NULL)
        {
            if (curr->data == check->next->data)
            {
                Node *temp = check->next;
                check->next = check->next->next;

                if (temp == list->tail)
                    list->tail = check;

                free(temp);
                --list->count;
            }
            else
            {
            	check = check->next;
            }
        }
        curr = curr->next;
    }

    return list;
}



/* Locate a cycle and reconnect the last loop node back to NULL. */
Slist* slist_remove_loop(Slist *list)
{
    assert(list != NULL);
    if (list->count < 2)
        return list;
    Node *slow = list->head;
    Node *fast = list->head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

	        if (slow == fast)
	        {
	            slow = list->head;

	            if (slow == fast)
	            {
	                while (fast->next != slow)
	                    fast = fast->next;
	            }
	            else
	            {
	                while (slow->next != fast->next)
	                {
	                    slow = slow->next;
	                    fast = fast->next;
	                }
	            }
	            fast->next = NULL;
	            list->tail = fast;
            return list;
        }
    }
    return list;
}
