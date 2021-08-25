#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_NODES 7

struct heap_struct
{
    unsigned int max_heap_size;
    unsigned int crnt_heap_size;

    int * elements;
};

/***** Prototypes here *****/
struct heap_struct * create_heap(unsigned int max_elements);
bool is_full(struct heap_struct * H);
void insert_node(int x, struct heap_struct * H);
void print_heap(struct heap_struct * H);

int main(void)
{

    srand((unsigned int)time(NULL));    /// Random number generator seeded with value of time

    int my_array[NUM_NODES];

    for(int x=0; x<NUM_NODES; x++) /// Fill the array with -1s
        my_array[x] = -1;

    int i = 0;
    int j = 0;

    printf("\nArray:\t");
    while(i < NUM_NODES)   /// Fill my_array with unique values ranging from 0 to 99
    {
        int temp = rand() % 100;

        for(j=0; j<i; j++)
        {
            if(temp == my_array[j]) /// The number already exists in the array
            break;
        }

        if(j == i)     /// temp was not found in the array
        {
            my_array[i] = temp;
            printf("%d\t", my_array[i]);
            i++;
        }
    }

    /// Build a new heap

    struct heap_struct * Heap = NULL;

    Heap = create_heap(NUM_NODES);

    for(int i = 0; i<NUM_NODES; i++)
    {
        insert_node(my_array[i], Heap);

    }
    printf("\nHeap:\t");
    print_heap(Heap);

    return 0;
}

struct heap_struct * create_heap(unsigned int max_elements)
{

    struct heap_struct * H;

    H = (struct heap_struct *) malloc(sizeof(struct heap_struct));

    if(H == NULL)
    {
        printf("\nFatal Error!! Out of memory!!\n");
        exit(-1);
    }

    /// Allocate the space for Array plus 1 for senital
    H->elements = (int *) malloc(sizeof(int) * (max_elements+1));
    if(H->elements == NULL)
    {
        printf("\nFatal Error!! Out of memory!!\n");
        exit(-1);
    }
    H->max_heap_size = max_elements;
    H->crnt_heap_size = 0;
    H->elements[0] = -1;

    return H;
}

void insert_node(int x, struct heap_struct * H)
{
    unsigned int i;

    if(is_full(H))
    {
        printf("\nError! Heap is full !!\n");
        return;
    }
    else
    {
       /** Complete this function **/
    }

}

bool is_full(struct heap_struct * H)
{
    return((H->crnt_heap_size) == (H->max_heap_size));
}

void print_heap(struct heap_struct * H)
{
    for(int i = 0; i < H->crnt_heap_size; i++)
        printf("%d\t", H->elements[i+1]);
}

void delete_root(struct heap_struct * H)
{
    /** Complete this function **/
}
