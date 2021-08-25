#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "BST.h"

bool bst_search(struct node * root, int key)
{
    /** Complete this function */

    return(false);
}

bool insert_node(struct node ** ptr, int insert_data)
{
    if(*ptr == NULL) /// We have to insert a new node in the tree now
    {
        struct node * temp = (struct node *) malloc(sizeof(struct node));
        temp->data = insert_data;
        temp->left = NULL;
        temp->right = NULL;
        *ptr = temp;
        printf("\n%d as Root node inserted!", insert_data);
        return(true);
    }

    if(((*ptr)->data > insert_data)) /// data to be inserted to left sub tree
    {
        if((*ptr)->left != NULL)
            insert_node(&(*ptr)->left, insert_data);
        else
        {
            struct node * temp = (struct node *) malloc(sizeof(struct node));
            temp->data = insert_data;
            temp->left = NULL;
            temp->right = NULL;
            (*ptr)->left = temp;
            printf("\n%d inserted to the left of %d!", insert_data, (*ptr)->data);
            return(true);
        }
    }
    else
    {
        if((*ptr)->right != NULL)
            insert_node(&(*ptr)->right, insert_data);
        else
        {
            struct node * temp = (struct node *) malloc(sizeof(struct node));
            temp->data = insert_data;
            temp->left = NULL;
            temp->right = NULL;
            (*ptr)->right = temp;
            printf("\n%d inserted to the right of %d!", insert_data, (*ptr)->data);
            return(true);
        }
    }


    return(true);
}

bool delete_node(struct node * root, int data)
{

    /** Complete this function */
    return(false);
}

bool save_in_order(struct node * root, FILE * fptr)
{
    /** Complete this function */
    return(false);
}
bool save_pre_order(struct node * root, FILE * fptr)
{
    return(false);
}

bool save_post_order(struct node * root, FILE * fptr)
{
    return(false);
}

int load_tree(struct node * root, FILE * fptr)
{
    /** Complete this function */
    return(false);
}

int find_smallest_node(struct node * root)
{
    /** Complete this function */
    return(0);

}

void print_in_order(struct node * ptr)
{
    if(ptr->left == NULL)   /// Now data of this node will be printed
        printf("%d\t", ptr->data);

    if(ptr->left != NULL)
    {
        print_in_order(ptr->left);
        printf("%d\t", ptr->data);
    }

    if(ptr->right != NULL)
    {
        print_in_order(ptr->right);
    }

    return;
}

void print_pre_order(struct node * root)
{

    /** Complete this function */

}

void print_post_order(struct node * root)
{
    /** Complete this function */

}
