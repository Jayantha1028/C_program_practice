#ifndef student_linked_list_h
#define student_linked_list_h
#include <stdint.h>

/* Maximum number of characters stored for student name and program. */
typedef struct _student_ Student;
#define NameSize 100
#define ProgramSize 40

/* Node structure for each student in the singly linked list. */
struct _student_ {
    int32_t rollno;
    char name[NameSize];
    float cgpa;
    char program[ProgramSize];
    Student* next;
};

typedef struct _list_info_ Stdll;

/* Stores list metadata: first node, last node, and total node count. */
struct _list_info_{
    Student* head;
    Student* tail;
    int32_t count;
};

/* Linked-list operations. */
Stdll LL_initialize(void);
int32_t LL_count(Stdll* list);
Stdll* LL_append(Stdll* list, Student* student);
Stdll* LL_delete(Stdll* list, int32_t rollno);
uint32_t LL_lookup(const Stdll* list, int32_t rollno);
Stdll* LL_update(Stdll* list, Student* student);
Stdll* LL_insert(Stdll* list, Student* student,int32_t pos);
Stdll* LL_delete_at(Stdll* list, uint32_t pos);

#endif // student_linked_list_h
