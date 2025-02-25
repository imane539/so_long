#include "so_long.h"
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
// void create_queue(t_bfs **a,int x,int y,int visited)
// {
//     // t_bfs *head;
//     // head = NULL;
//     if(!a)
//         a = malloc(sizeof(t_bfs *));
    
// }
