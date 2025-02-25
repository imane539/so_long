#include "so_long.h"
int isvisited(t_bfs *a,int x,int y)
{
    while(a->next)
    {
        if(a->x ==x && a->y == y)
            return 1;
        a=a->next;
    }
    return 0;

}
t_bfs *new_node(int x,int y)
{
    t_bfs *new;

    new = malloc(sizeof(t_bfs));
    new ->x = x;
    new ->y = y;
    new ->visited = 1;
    new->next = NULL;
    return new;
}
t_bfs *last_node(t_bfs *a)
{
    if(!a)
    return a;
    while(a->next)
    {
        a = a->next;
    }
    return a;
}
void add_next(t_bfs **a,t_bfs *new)
{
    t_bfs *last;
    if(!(*a))
    (*a) = new;
    else
    {
        last = last_node(*a);
        last->next = new;
    }
}
// void create_queue(t_bfs **a,int x,int y,int visited)
// {
//     // t_bfs *head;
//     // head = NULL;
//     if(!a)
//         a = malloc(sizeof(t_bfs *));
    
// }
