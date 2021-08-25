#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 16  /// 16, 128, 1024, etc


#define MERGE_SORT      1
#define QUICK_SORT      2

void print_array(int * ptr_array, int size);
void sort_array(int * ptr_array, int size, int sort_type);

void merge_sort(int * ptr_array, int size);
void merge(int * ptr_arr1, int size1, int * ptr_arr2, int size2);

void quick_sort(int * ptr_array, int start_idx, int end_idx);
int partition(int * ptr_array, int start_idx, int end_idx);
void swap(int * ptr_num1, int * ptr_num2);

int main()
{
    srand((unsigned int)time(NULL));    /// Random number generator seeded with value of time

    /** Initialize an Integer Array and initialize it with random numbers between 0-999 **/
    int my_array[ARRAY_SIZE];

    for(int i=0; i<ARRAY_SIZE; i++)
    {
        my_array[i] = rand()%1000;
    }
    /*************************************************************************************/
    printf("Unsorted array:\n");
    print_array(my_array, ARRAY_SIZE);
    /// to store execution time of code
	double time_spent = 0.0;

	clock_t begin = clock();

	/// do the sorting part here
	sort_array(my_array,ARRAY_SIZE,QUICK_SORT);

	clock_t end = clock();

	printf("Sorted array:\n");
	print_array(my_array, ARRAY_SIZE);
	/// calculate elapsed time by finding difference (end - begin) and
	/// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n\nTime elpased is %f seconds", time_spent);

    return 0;
}

void print_array(int * ptr_array, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%3d\t", *(ptr_array+i));

    }
    printf("\n\n");
}

void sort_array(int * ptr_array, int arr_size, int sort_type)
{

    switch(sort_type)
    {

        case MERGE_SORT:
        /**************** Call Merge Sort Function Here ************************/

        merge_sort(ptr_array, arr_size);

        /***********************************************************************/
        break;

        case QUICK_SORT:
        /**************** Call Merge Sort Function Here ************************/

        quick_sort(ptr_array, 0, arr_size-1);   /// call the function wih start and end indices

        /***********************************************************************/
        break;
    }


}

void merge_sort(int * ptr_array, int array_size)
{
    if(array_size == 1)     /// Base case here
        return;

    int size1 = array_size/2;
    int size2;

    if(array_size % 2 == 1)     /// We are also tackling the case where the array size is not even
        size2 = (array_size/2)+1;
    else
        size2 = (array_size/2);

    merge_sort(ptr_array, size1);
    merge_sort(ptr_array+(array_size/2), size2);


    merge(ptr_array, size1, ptr_array+(array_size/2), size2);
    return;

}

void merge(int * ptr_arrA, int sizeA, int * ptr_arrB, int sizeB)
{

    int * ptr_arrC = (int *) malloc(sizeof(int)*(sizeA+sizeB));  /// Array of integers to temporarily hold the sorted data

    int indexA = 0;     /// to keep track of the elements in A
    int indexB = 0;     /// to keep track of the elements in A
    int indexC = 0;

    while((indexA < sizeA)&&(indexB<sizeB))
    {
        if((*(ptr_arrA+indexA)) > (*(ptr_arrB+indexB)))     /// if elemnt in A is greater than element in B
        {
            *(ptr_arrC + indexC) =  *(ptr_arrB+indexB);     /// Place the smaller element at the start of C
            indexB ++;
            indexC ++;
        }
        else
        {
            *(ptr_arrC + indexC) =  *(ptr_arrA+indexA);     /// Place the smaller element at the start of C
            indexA ++;
            indexC ++;
        }
    }

    /// At this stage either A or B will have no elements left
    while(indexA < sizeA)
    {
        *(ptr_arrC + indexC) =  *(ptr_arrA+indexA);
         indexA ++;
         indexC ++;
    }

    while(indexB < sizeB)
    {
        *(ptr_arrC + indexC) =  *(ptr_arrB+indexB);
         indexB ++;
         indexC ++;
    }

    /// Now the elements are in sorted order in C.
    /// Time to plug them back into the original array

    /** To Complete **/

    free(ptr_arrC);  /// Delete the previously allocated memory
    return;
}

void quick_sort(int * ptr_array, int start_idx, int end_idx)
{
    if(start_idx < end_idx)
    {
        int pivot_idx = partition(ptr_array, start_idx, end_idx);

        quick_sort(ptr_array, start_idx, pivot_idx-1);
        quick_sort(ptr_array, pivot_idx+1, end_idx);
    }

}
int partition(int * ptr_array, int start_idx, int end_idx)
{

    /** To Complete **/
}

/* By reference swapping of integers*/
void swap(int * ptr_num1, int * ptr_num2)
{
    int temp;
    temp = *(ptr_num1);
    *(ptr_num1) = *(ptr_num2);
    *(ptr_num2) = temp;
}
