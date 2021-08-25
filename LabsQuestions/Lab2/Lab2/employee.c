#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include"employee.h"

/** This function takes pointer to a node as argument
    and then prompts user to input the data for that
    employee. The function does not return anything.
*/
void inEmpRec(struct employee * emp)
{
    printf("\nEnter the name of the employee: ");
    fgets(emp->name, 50, stdin);

    printf("\nEnter the age of the employee: ");
    scanf("%d", &(emp->age));

    printf("\nEnter the basic salary of the employee: ");
    scanf("%f", &(emp->bs));

    printf("\nRecord entered !\n");
}

/** This function takes pointer to a node as argument
    and then prints the record on the screen (stdout).
    The function does not return anything.
*/
void displayEmpRec(struct employee * emp)
{
    printf("\nName:\t %s", emp->name);
    printf("Age:\t %d\n", emp->age);
    printf("Basic Salary:\t %f\n", emp->bs);
}

/** Function to display the list
*/
void printList(struct employee * emp)
{
   struct employee * ptr = emp;
   printf("\nStart of list: \n");

   //start from the beginning
   while(ptr != NULL)
   {
      displayEmpRec(ptr);
      ptr = ptr->next;
   }

   printf("\nEnd of list.\n");
}


/** Insert a new node at the last location. i.e. after the current one.
    If the list is currently empty, a new node is created for the head.
*/
struct employee *  insertEnd(struct employee * first)
{
   struct employee * temp = first;
   ///create a new node
   struct employee * new_node = (struct employee *) malloc(sizeof(struct employee));

   inEmpRec(new_node);  /// get data for the newly created node.

   ///point its next pointer to NULL
   new_node->next = NULL;

   if(isEmpty(first))    /// if currently the list is empty
   {
    temp = new_node;
    return(temp);
   }
   else
   {
    while((temp->next) != NULL)
        temp = temp->next;      /// scroll to the end of the list
    temp->next = new_node;
   }
   return(first);
}

/** Tests if the list is empty. ONLY the head of the list
    should be passed to this function.
*/
bool isEmpty(struct employee * emp)
{
   return (emp == NULL);
}

/** Function to find the length (in number of nodes) of the list.
*/
int listLength(struct employee * emp)
{
   int length = 0;
   struct employee * current;

   for(current = emp; current != NULL; current = current->next)
   {
      length++;
   }

   return length;
}


