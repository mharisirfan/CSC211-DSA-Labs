#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 16   /// 16, 128, 1024, etc

#define BUBBLE_SORT     1
#define SELECTION_SORT  2
#define INSERTION_SORT  3
#define MERGE_SORT      4

void print_array(int * ptr_array, int size);
void sort_array(int * ptr_array, int size, int sort_type);
void merge_sort_array(int * ptr_array, int size);
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

    /// to store execution time of code
	double time_spent = 0.0;

	clock_t begin = clock();

	/// do the sorting part here
	sort_array(my_array,ARRAY_SIZE,BUBBLE_SORT);

	clock_t end = clock();

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
}

void sort_array(int * ptr_array, int arr_size, int sort_type)
{

    switch(sort_type)
    {
        case BUBBLE_SORT:
        /****************** Implement Bubble Sort Here *************************/
         for(int k = arr_size; k>0; k--)    /// Outer loop moves the partition between the
         {                                  /// sorted and un-sorted sub-arrays.
            for(int i=0; i<k-1; i++)
            {
                if(*(ptr_array+i)>*(ptr_array+i+1)) /// If item on the left is greater than the one on the right
                {
                    int temp = *(ptr_array+i+1);    /// Swap them.
                    *(ptr_array+i+1) = *(ptr_array+i);
                    *(ptr_array+i) = temp;
                }
            }
        }
        /***********************************************************************/
        break;

        case SELECTION_SORT:
        /****************** Implement Selection Sort Here **********************/



        /***********************************************************************/
        break;

        case INSERTION_SORT:
        /**************** Implement Insertion Sort Here ************************/



        /***********************************************************************/
        break;

        case MERGE_SORT:
        /**************** Call Merge Sort Function Here ************************/

        merge_sort_array(ptr_array, arr_size);

        /***********************************************************************/
        break;
    }


}

void merge_sort_array(int * ptr_array, int size)
{
    /*** Complete this function ***/
}
