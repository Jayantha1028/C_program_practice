#include <stdio.h>
#include <assert.h>
#include "Std_linked_list.h"

static void print_list(const Stdll *list)
{
    Student *curr = list->head;
    printf("List: ");
    while (curr != NULL) { printf("%d -> ", curr->rollno); curr = curr->next; }
    printf("NULL\nCount: %d\n", list->count);
    printf("Head: %s\n", list->head ? "set" : "NULL");
    printf("Tail: %s\n\n", list->tail ? "set" : "NULL");
}

int test_linked_list(void)
{
    Stdll list = LL_initialize();
    assert(list.head == NULL && list.tail == NULL && LL_count(&list) == 0);
    printf("Test 1 passed: initialize\n");

    Student s1 = {1, "Alice", 8.5f, "CSE", NULL};
    LL_append(&list, &s1);
    assert(LL_count(&list) == 1 && list.head == list.tail && list.head->rollno == 1 && list.tail->next == NULL);
    printf("Test 2 passed: append first student\n"); print_list(&list);

    Student s2 = {2, "Bob", 7.8f, "ECE", NULL};
    Student s3 = {3, "Charlie", 9.1f, "CSE", NULL};
    LL_append(&list, &s2); LL_append(&list, &s3);
    assert(LL_count(&list) == 3 && list.head->rollno == 1 && list.tail->rollno == 3 && list.tail->next == NULL);
    printf("Test 3 passed: append multiple students\n"); print_list(&list);

    assert(LL_lookup(&list, 1) == 1 && LL_lookup(&list, 2) == 1 && LL_lookup(&list, 3) == 1 && LL_lookup(&list, 100) == 0);
    printf("Test 4 passed: lookup\n");

    Student s4 = {4, "David", 8.2f, "CSE", NULL};
    LL_insert(&list, &s4, 1);
    assert(LL_count(&list) == 4 && list.head->rollno == 4 && list.head->next->rollno == 1 && list.tail->rollno == 3 && list.tail->next == NULL);
    printf("Test 5 passed: insert at beginning\n"); print_list(&list);

    Student s5 = {5, "Eve", 9.0f, "ISE", NULL};
    LL_insert(&list, &s5, 3);
    assert(LL_count(&list) == 5 && list.head->rollno == 4 && list.head->next->rollno == 1 && list.head->next->next->rollno == 5);
    printf("Test 6 passed: insert in middle\n"); print_list(&list);

    Student s6 = {6, "Frank", 7.5f, "ME", NULL};
    LL_insert(&list, &s6, 6);
    assert(LL_count(&list) == 6 && list.tail->rollno == 6 && list.tail->next == NULL);
    printf("Test 7 passed: insert at end\n"); print_list(&list);

    int old_count = LL_count(&list);
    LL_insert(&list, &s6, 0); LL_insert(&list, &s6, 100);
    assert(LL_count(&list) == old_count);
    printf("Test 8 passed: invalid positions\n");

    Stdll empty = LL_initialize();
    Student s7 = {7, "Grace", 8.8f, "CSE", NULL};
    LL_insert(&empty, &s7, 1);
    assert(empty.head == empty.tail && empty.head->rollno == 7 && empty.tail->next == NULL && LL_count(&empty) == 1);
    printf("Test 9 passed: insert into empty list\n"); print_list(&empty);

    Student updated = {3, "Charlie Updated", 9.9f, "AI", NULL};
    LL_update(&list, &updated);
    Student *curr = list.head;
    while (curr && curr->rollno != 3) curr = curr->next;
    assert(curr && curr->cgpa == 9.9f);
    printf("Test 10 passed: update\n"); print_list(&list);

    LL_delete(&list, 2);
    assert(LL_count(&list) == 5);
    printf("Test 11 passed: delete\n"); print_list(&list);

    LL_delete_at(&list, 3);
    assert(LL_count(&list) == 4 && list.head->rollno == 4 && list.head->next->rollno == 1 && list.head->next->next->rollno == 3);
    printf("Test 12 passed: delete at middle position\n"); print_list(&list);

    LL_delete(&list, 4);
    assert(LL_count(&list) == 3 && list.head->rollno == 1 && list.tail->rollno == 6);
    printf("Test 13 passed: delete head by roll number\n"); print_list(&list);

    LL_delete(&list, 6);
    assert(LL_count(&list) == 2 && list.head->rollno == 1 && list.tail->rollno == 3 && list.tail->next == NULL);
    printf("Test 14 passed: delete tail by roll number\n"); print_list(&list);

    LL_delete(&empty, 7);
    assert(LL_count(&empty) == 0 && empty.head == NULL && empty.tail == NULL);
    LL_delete(&empty, 99);
    assert(LL_count(&empty) == 0 && empty.head == NULL && empty.tail == NULL);
    printf("Test 15 passed: delete from single-node and empty list\n"); print_list(&empty);

    printf("All tests passed!\n");
    return 0;
}