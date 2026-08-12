#include <assert.h>
#include <stdio.h>
#include "slist.h"

/* Build a list from an array so edge-case tests stay compact. */
static Slist* make_list(const int *values, int count)
{
    Slist l1 = slist_new();
    Slist *list = &l1;
    for (int i = 0; i < count; ++i)
        slist_add_tail(list, values[i]);
    return list;
}

/* Exercise palindrome checks, splitting, and loop removal edge cases. */
int main(void)
{
    /* Palindrome should be detected without damaging head, tail, or count. */
    int odd_pal[] = {1, 2, 3, 2, 1};
    Slist *pal = make_list(odd_pal, 5);
    assert(slist_is_palindrome(pal) == 1);
    assert(slist_get_count(pal) == 5);
    assert(pal->head->data == 1);
    assert(pal->tail->data == 1);
    assert(pal->tail->next == NULL);

    /* Non-palindrome input should leave the list structurally valid. */
    int not_pal[] = {1, 2, 3};
    Slist *np = make_list(not_pal, 3);
    assert(slist_is_palindrome(np) == 0);
    assert(slist_get_count(np) == 3);
    assert(np->tail->next == NULL);

    /* Splitting should divide odd-sized lists with the extra node in front. */
    int split_values[] = {4, 1, 9, 2, 7};
    Slist *first = make_list(split_values, 5);
    Slist *second = slist_split_into_two(first);
    assert(first->count == 3);
    assert(second->count == 2);
    assert(first->tail->data == 9);
    assert(second->head->data == 2);
    assert(first->min == 1 && first->max == 9);
    assert(second->min == 2 && second->max == 7);

    /* Loop removal should restore a NULL-terminated tail. */
    Slist l = slist_new();
    Slist* loop = &l;
    slist_add_tail(loop, 10);
    slist_add_tail(loop, 20);
    slist_add_tail(loop, 30);
    loop->tail->next = loop->head;
    assert(slist_is_loop(loop) == 1);
    slist_remove_loop(loop);
    assert(slist_is_loop(loop) == 0);
    assert(loop->tail->data == 30);
    assert(loop->tail->next == NULL);

    puts("edge tests passed");
    return 0;
}
