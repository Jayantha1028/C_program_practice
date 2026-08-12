/************
* Author:
* Date:
* Purpose:
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

/* Verify that a newly initialized list starts empty. */
void test_empty_list(){
    Slist l1 = slist_new();
    Slist *list = &l1;
    assert (slist_get_count(list) == 0);
    printf("Hello !\n");
}

/* Verify head insertion order, count updates, and lookup behavior. */
void test_add_node_head() {
    Slist l1 = slist_new();
    Slist *list = &l1;
    list = slist_add_head(list, 10);
    assert (slist_get_count(list) == 1);
    list = slist_add_head(list, 20);
    list = slist_add_head(list, 30);
    list = slist_add_head(list, 40);
    list = slist_add_head(list, 50);
    assert (slist_get_count(list) == 5);
    assert (slist_lookup(list, 20) == 1);
    assert (slist_lookup(list, 50) == 1);
    assert (slist_lookup(list, 60) == 0);

}

/* Verify deleting from the head removes only the first node each time. */
void test_delete_from_head(){
    Slist l1 = slist_new();
    Slist *list = &l1;
    list = slist_add_head(list, 10);
    assert (slist_get_count(list) == 1);
    list = slist_add_head(list, 20);
    list = slist_add_head(list, 30);
    list = slist_add_head(list, 40);
    list = slist_add_head(list, 50);
    list = slist_delete_head(list);
    assert (slist_lookup(list, 50) == 0);
    list = slist_delete_head(list);
    assert (slist_get_count(list) == 3);
    list = slist_add_head(list, 50);
    assert (slist_lookup(list, 50) == 1);
    printf("Hello w!\n");
    
}

/* Verify deleting from the tail removes only the last node each time. */
void test_delete_from_tail(){
    Slist l1 = slist_new();
    Slist *list = &l1;
    list = slist_add_head(list, 10);
    assert (slist_get_count(list) == 1);
    list = slist_add_head(list, 20);
    list = slist_add_head(list, 30);
    list = slist_add_head(list, 40);
    list = slist_add_head(list, 50);
    list = slist_delete_tail(list);
    printf("Hello w!\n");
    assert (slist_lookup(list, 10) == 0);
    assert (list->count== 4);
    printf("Hello w!\n");
    list = slist_delete_tail(list);
    assert (list->count== 3);
    printf("Hello w!\n");
    assert (slist_get_count(list) == 3);

}

/* Run the basic linked-list test suite. */
int main()
{
    printf("Hello world!\n");
    test_empty_list();
     printf("Hello world!\n");
    test_add_node_head();
     printf("Hello world!\n");
    test_delete_from_head();
     printf("Hello world!\n");
    test_delete_from_tail();

    return 0;
}
