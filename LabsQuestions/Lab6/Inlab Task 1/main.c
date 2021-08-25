#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "node.h"
#include "pr_queue_functions.h"
int main()
{
   srand((unsigned int)time(NULL));

   struct node * front = NULL;
   struct node * rear = NULL;

   struct element new_data;
   int new_prior;

   for(int i = 0; i < 5; i++)
   {
        new_data.value = i;
        new_prior = rand() % 10;        /// A priority value between 0 and 9
        pr_enqueue(&rear, &front, new_data, new_prior);
        printf("Enqueue data: %d with priority: %d", new_data.value, new_prior);
        printf("\n");

        if(pr_isEmpty(&front))
            printf("Data not added!!! \n");
   }

   for(int i = 0; i < 5; i++)
   {
        new_data = pr_dequeue(&front);
        printf("Dequeue data: %d", new_data.value);
        printf("\n");
   }

    return 0;
}
