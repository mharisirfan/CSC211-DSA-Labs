/** Program to demonstrate that different data types can be pushed onto the stack using
*   structures. Each element contains an extra field 'd_type' to tell which data type
*   is being pushed onto the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack_functions.h"

int main()
{
    struct node * top = NULL;   /// This is the top of the stack

    struct element d1, d2, d3;

    d1.d = 10;
    d1.d_type = 0;

    d2.ch = 'A';
    d2.d_type = 1;

    d3.d = 45;
    d3.d_type = 0;

    push(&top, d1);
    push(&top, d3);
    push(&top, d2);

    for(int i = 0; i<3; i++)
    {
        struct element temp;

        temp = pop(&top);
        if(temp.d_type == 0)
            printf("\nThe data popped is %d", temp.d);
        else
            printf("\nThe data popped is %c", temp.ch);
    }

    return 0;
}
