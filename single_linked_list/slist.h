#ifndef _SLIST_H_INCLUDED_
#define _SLIST_H_INCLUDED_

#include<stdint.h>

/* Forward declarations keep the list and node types available to callers. */
typedef struct _slist_ Slist;
typedef struct _node_ Node;

/* Each node stores one integer and the address of the next node. */
struct _node_ {
	int32_t data;
	Node *next;
	};

/* The list tracks endpoints, size, and cached minimum/maximum values. */
struct _slist_ {
	Node *head;
	Node *tail;
	int32_t count;
	int32_t min;
	int32_t max;
	};

Slist slist_new(); // initialize the list to store the linked list
int32_t slist_get_count(const Slist *list);  // A function to get number of elements in the list
Slist* slist_add_head(Slist *list,int32_t ele); // Add a node at the start of list
Slist* slist_add_tail(Slist *list,int32_t ele); // Add a node at the end of the list
uint8_t slist_lookup(const Slist *list,int32_t key); // search for a data if present or not in the list
Slist* slist_delete_head(Slist *list); // delete the first node from the linked list
Slist* slist_delete_tail(Slist *list);  // delete the last element 
void slist_display(const Slist *list); // Print all elements from head to tail
Slist* slist_add_at_position(Slist* list,int32_t ele, int32_t pos); // Insert at a 1-based position
Slist* slist_delete_at_position(Slist* list, int32_t pos); // Delete from a 1-based position
Slist* slist_add_node_after(Slist* list, int32_t ele, int32_t after); // Insert after the first matching value
Slist* slist_delete_after(Slist* list,int32_t ele); // Delete the node after the first matching value
Slist* slist_reverse(Slist* list); // Reverse links in-place
int32_t slist_middle(const Slist *list); // Return the middle element value
Slist* slist_delete_nth_from_end(Slist *list,int32_t n); // Delete the nth node from the end
Slist* slist_remove_duplicates(Slist *list); // Remove repeated values, keeping the first copy
Slist* slist_split_into_two(Slist* list); // Split into first and second halves
uint8_t slist_is_palindrome(Slist *list); // Check whether the list reads the same both ways
uint8_t slist_is_loop(const Slist *list); // Detect whether links contain a cycle
Slist* slist_remove_loop(Slist *list); // Break an existing cycle if one is present

#endif
