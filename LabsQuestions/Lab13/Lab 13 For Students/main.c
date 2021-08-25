#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "node.h"
#include "stack_functions.h"

#define NUM_VERTICES 10
/** This function takes a pointer to the
    adjacency matrix of a Graph and the
    size of this matrix as arguments and
    prints the matrix
*/
void print_graph(int * graph, int size);

/** This function takes a pointer to the
    adjacency matrix of a Graph, the size
    of this matrix, the source and dest
    node numbers along with the weight or
    cost of the edge and fills the adjacency
    matrix accordingly.
*/
void add_edge(int * graph, int size, int src, int dst, int cost);


/** This function takes a pointer to the adjacency matrix of
    a graph, the size of this matrix, source and destination
    vertex numbers as inputs and prints out the path from the
    source vertex to the destination vertex. It also prints
    the total cost of this path.
*/
void find_path_dfs(int * graph, int size, int src, int dst);

int main()
{
    int my_graph[NUM_VERTICES][NUM_VERTICES];   /// An adjacency matrix representation of graph
    
    memset(my_graph,-1,NUM_VERTICES * NUM_VERTICES * sizeof(int));     /// Initiallize with -1 representing infinte cost.

    for(int i=0; i<NUM_VERTICES; i++)
        add_edge(&my_graph[0][0], NUM_VERTICES, i, i, 0);	/// All the vertices have a cost of 0 for visiting themselves

    add_edge(&my_graph[0][0], NUM_VERTICES, 0, 3, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 4, 14);

    /** Task 1: Complete the rest of the Adjacency Matrix according to Figure 8 **/

    print_graph(&my_graph[0][0], NUM_VERTICES);

    find_path_dfs(&my_graph[0][0], NUM_VERTICES, 4, 8);
    //find_path_dfs(&my_graph[0][0], NUM_VERTICES, 9, 2);
    getchar();
    return 0;
}

void add_edge(int * graph, int size, int src, int dst, int cost)
{
    *(graph+(src*size+dst)) = cost;	/// Look carefully how the indices are calculated. You will need it for 2nd task.
}

void print_graph(int * graph, int size)
{
    //char vertices[size];
    for(int i=0; i<size; i++)
    {
        printf("\t%d", i);
    }
    printf("\n\n");
    for(int x=0; x<size; x++)
    {
        printf("%d\t", x);
        for(int y=0; y<size; y++)
            printf("%d\t", *(graph+(x*size+y)));
        printf("\n");
    }
}


void find_path_dfs(int * graph, int size, int src, int dst)
{
    int visited[size] = {0};  /// To keep track of all the visited nodes

    /********** We make a stack for holding the visited vertices *****************/

    struct node * top = NULL;   /// This is the top of the stack

    /** The DFS will work as follows:
        1. Visit src vertex. Set 'current_visiting' to src.
        2. Explore this vertex.
            If it is the destination vertex, stop.
            Otherwise visit its first unvisited neighbour (add to stack the current vertex)
            If no unvisited neighbour vertex remains, go back (pop from stack)
        3. Repeat 2*/

    int crnt_visiting = src;
    int crnt_exploring = src;
    int path_cost = 0;
    bool PATH_FOUND = false;
    while(!PATH_FOUND)
    {
        visited[crnt_visiting] = 1; /// Now we have visited this node
        struct element temp;

        if(crnt_visiting == dst)	/// If the vertex is found
        {
            printf("\nPath found: ");
            printf("\nCost: %d\n", path_cost);
            while(!isStackEmpty(&top))		/// Empty the stack so all the allocated memory is freed.
            {
                printf("Pop\n");
                pop(&top);
            }
            PATH_FOUND = true;
            continue;
        }
        else    /// Explore this vertex
        {
		/** 	Complete this function. You are free to make any changes to this function.
			But make sure that path cost is correctly found.
		*/
        }
    }


}
