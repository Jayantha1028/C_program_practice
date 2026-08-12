#include <stdio.h>
#include "Std_linked_list.h"

/* Print roll numbers and basic list metadata. */
static void print_list(const Stdll *list)
{
    Student *curr = list->head;

    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->rollno);
        curr = curr->next;
    }
    printf("NULL\nCount: %d\n", LL_count((Stdll *)list));
    printf("Head: %s\n", list->head ? "set" : "NULL");
    printf("Tail: %s\n\n", list->tail ? "set" : "NULL");
}

/* Find and display full student details for a given roll number. */
static void print_student_detail(const Stdll *list,int32_t rollno){
    if (!LL_lookup(list, rollno)){
        printf("%d is not found in the list.\n", rollno);
        return;
    }
    Student *curr = list->head;
    while (curr != NULL) {
        if(curr->rollno==rollno){
            printf("Rollno - %d\n", curr->rollno);
            printf("Name - %s\n", curr->name);
            printf("CGPA - %f\n", curr->cgpa);
            printf("Program - %s\n ", curr->program);
            break;
        }
        curr = curr->next;
    }
}

/* Read student fields from the user and return a filled Student value. */
static Student read_student(void)
{
    Student student = {0, "", 0.0f, "", NULL};

    printf("Enter roll number: ");
    scanf("%d", &student.rollno);

    printf("Enter name: ");
    scanf("%99s", student.name);

    printf("Enter CGPA: ");
    scanf("%f", &student.cgpa);

    printf("Enter program: ");
    scanf("%39s", student.program);

    return student;
}

int main(void)
{
    /* Keep one list for the whole program session. */
    Stdll list = LL_initialize();
    int choice;

    while (1) {
        /* Display the menu before each operation. */
        printf("\nFunctions to be performed on student linked list:\n");
        printf("1. Create/reset the list\n");
        printf("2. Append\n");
        printf("3. Lookup\n");
        printf("4. Update\n");
        printf("5. Insert\n");
        printf("6. Delete\n");
        printf("7. Delete at a position\n");
        printf("8. Print the list\n");
        printf("9. Display the Student details\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            return 1;
        }

        switch (choice) {
            case 1:
                /* Reset the list metadata to an empty state. */
                list = LL_initialize();
                printf("List created successfully.\n");
                break;

            case 2: {
                /* Append the entered student as the last node. */
                Student student = read_student();
                LL_append(&list, &student);
                printf("Student added successfully.\n");
                break;
            }

            case 3: {
                /* Check whether a roll number exists in the list. */
                int32_t rollno;

                printf("Enter roll number to lookup: ");
                scanf("%d", &rollno);

                if (LL_lookup(&list, rollno))
                    printf("%d is found in the list.\n", rollno);
                else
                    printf("%d is not found in the list.\n", rollno);
                break;
            }

            case 4: {
                /* Update an existing student using roll number as the key. */
                Student student = read_student();
                LL_update(&list, &student);
                printf("%d details updated if the student exists.\n", student.rollno);
                break;
            }

            case 5: {
                /* Insert the entered student at the requested 1-based position. */
                Student student = read_student();
                int32_t pos;

                printf("Enter position to insert at: ");
                scanf("%d", &pos);

                LL_insert(&list, &student, pos);
                printf("%d details inserted if the position is valid.\n", student.rollno);
                break;
            }

            case 6: {
                /* Delete the student matching the entered roll number. */
                int32_t rollno;

                printf("Enter roll number to delete: ");
                scanf("%d", &rollno);

                LL_delete(&list, rollno);
                printf("%d deleted if the student exists.\n", rollno);
                break;
            }

            case 7: {
                /* Delete a node using its 1-based list position. */
                uint32_t pos;

                printf("Enter position to delete: ");
                scanf("%u", &pos);

                LL_delete_at(&list, pos);
                printf("Student deleted if the position is valid.\n");
                break;
            }

            case 8:
                /* Show the complete list. */
                print_list(&list);
                break;

            case 9: {
                /* Display all stored details for one student. */
                int32_t rollno;
                printf("Enter the Rollno :");
                scanf("%d",&rollno);
                print_student_detail(&list,rollno);
                break;
            }

            case 10:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
