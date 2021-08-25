struct element
{
    int vertex_num;
    int cost_to_visit;
};
struct node
{
    struct element data;

    struct node * next;
};
