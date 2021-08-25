struct element
{
    int value;
};
struct node
{
    struct element data;
    int node_priority;
    struct node * next;
};
