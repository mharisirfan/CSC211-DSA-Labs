
#include <stdlib.h>
#include <stdbool.h>

#include "employee.h"

void flush();

int main()
{
    int choice;

    struct employee * head = NULL; /// Pointer to the first element (head) of the list
    3

    printf("Hello! This program lets you manage your Employees' Database:\n");

    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Enter a new node to the list.");
        printf("\n2. Print the list.");
        printf("\n3. Delete the last item from the list.");
        printf("\n4. Save the list to a file.");
        printf("\n5. Exit the menue.\n");



        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add a new node to the list at the end. Create one if empty.
            {
                printf("\nAdding a new node: \n\n");
                head = insertEnd(head);
                break;
            }

            case    2:  /// Print the list.
            {
                printList(head);
                break;
            }

            case    3:  /// Delete the last item from the list
            {
                printf("\nThis function is not yet implemented\n");
                break;
            }

            case    4:  /// Save list to file
            {
                printf("\nThis function is not yet implemented\n");
                break;
            }

            case    5:  /// Exit the program.
            {
                printf("\nExiting on user request.\n\n");
                return(0);
            }
        }
    }
    return 0;
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
