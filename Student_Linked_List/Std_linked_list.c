#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "Std_linked_list.h"

/* Create an empty linked list. */
Stdll LL_initialize(void){
    Stdll list= {NULL,NULL,0};
    return list;
}


/* Return the number of students currently stored in the list. */
int32_t LL_count(Stdll* list){
    assert(list != NULL);
    return list->count;
}


/* Allocate a new list node and copy student data into it. */
static Student* create_new_node(Student* student){
    Student* new_node = (Student*)malloc(sizeof(Student));
    if (new_node == NULL)
        return NULL;
    new_node->next=NULL;
    new_node->rollno=student->rollno;
    strncpy(new_node->name, student->name, NameSize - 1);
    new_node->name[NameSize - 1] = '\0';
    new_node->cgpa=student->cgpa;
    strncpy(new_node->program, student->program, ProgramSize - 1);
    new_node->program[ProgramSize - 1] = '\0';
    return new_node;
}

/* Add a new student to the end of the linked list. */
Stdll* LL_append(Stdll* list, Student* student){
    assert (list!=NULL);
    if (student == NULL) 
        return list;
    Student* new_std = create_new_node(student);
    if (new_std == NULL)
        return list;

    if (list->head==NULL){
        list->head=list->tail=new_std;
    } else {
        list->tail->next=new_std;
        list->tail=new_std;
    }
    ++list->count;
    return list;
}

/* Search the list by roll number. Returns 1 when found, otherwise 0. */
uint32_t LL_lookup(const Stdll* list, int32_t rollno){
    assert (list!=NULL);
    if (list->head == NULL) 
        return 0;
    Student *curr=list->head;
    while (curr!=NULL){
        if (curr->rollno==rollno){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}



/* Update name, CGPA, and program for an existing roll number. */
Stdll* LL_update(Stdll* list, Student* student){
    assert (list!=NULL);
    if (student == NULL) 
        return list;
    Student *curr=list->head;
    while (curr!=NULL){
        if (curr->rollno==student->rollno){
            curr->cgpa=student->cgpa;
            strncpy(curr->name, student->name, NameSize - 1);
            curr->name[NameSize - 1] = '\0';
            strncpy(curr->program, student->program, ProgramSize - 1);
            curr->program[ProgramSize - 1] = '\0';
            return list;
        }
        curr = curr->next;
    }
    return list;
}

/* Insert a student at a 1-based position in the list. */
Stdll* LL_insert(Stdll* list, Student* student, int32_t pos)
{
    assert(list != NULL);

    if (student == NULL)
        return list;

    if (pos == 0 || pos > list->count + 1)
        return list;

    Student* new_node = create_new_node(student);

    if (new_node == NULL)
        return list;

    // Insert at beginning
    if (pos == 1) {
        new_node->next = list->head;
        list->head = new_node;

        if (list->tail == NULL)
            list->tail = new_node;
    }
    else {
        Student* temp = list->head;

        for (int32_t i = 1; i < pos - 1; i++)
            temp = temp->next;

        new_node->next = temp->next;
        temp->next = new_node;

        if (new_node->next == NULL)
            list->tail = new_node;
    }

    ++list->count;
    return list;
}

/* Delete the student node at a 1-based position. */
Stdll* LL_delete_at(Stdll* list, uint32_t pos){    
    assert (list!=NULL);

    if(pos == 0 || pos > (uint32_t)list->count)
        return list;
    Student* to_delete=list->head;
    if(pos==1){
        list->head=to_delete->next;
        if(list->head==NULL)
            list->tail=NULL;
    }
    else{
     Student* iter=list->head;
    for(uint32_t i=1; i < pos - 1; i++)
        iter=iter->next;
    to_delete= iter->next;
    iter->next=to_delete->next;
    if (to_delete==list->tail)
        list->tail=iter;
    }
    --list->count;
    free(to_delete);
    return list;
    }

/* Delete the first student node matching the given roll number. */
Stdll* LL_delete(Stdll* list, int32_t rollno){
    assert (list!=NULL);

    if (list->head == NULL)
        return list;

    uint8_t found=0;
    Student* temp=list->head;
    if (list->head->rollno==rollno){
        found=1;
        list->head=temp->next;
        if(list->head==NULL)
            list->tail=NULL;
    }
    else{
    Student* iter=list->head;
    for(;iter->next!=NULL;iter=iter->next){
        if (iter->next->rollno==rollno){
            found=1;
            break;
            }
        }
    if (!found)
        return list;

    temp= iter->next;
    iter->next=temp->next;
    if (temp->next==NULL)
        list->tail=iter;
    }
    if(found){
        --list->count;
        free(temp);
        }
    return list;
}
