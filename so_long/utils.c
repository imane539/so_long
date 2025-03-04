#include "so_long.h"
void free_array(char **map)
{
    int i;
    i = 0;
    while(map[i])
        free(map[i++]);
    free(map);
}
void clear_queue(t_bfs **a)
{
    t_bfs *tmp;
    while(*a)
    {
        tmp = (*a);
        (*a) = (*a)->next;
        free(tmp);
    }
    free(a);
}
int the_same_index(t_bfs *a,int index)
{
    int count;
    count = 0;
    if(!a)
    return count;
    while(a)
    {
        if(a->index == index)
        count++;
        a = a->next;
    }
    return count;
}
void change_moves(int *x,int *y,int moves)
{
    if(moves == 0)
    *x = *x - 1;
    if(moves == 1)
    *y = *y - 1;
    if(moves == 2)
    *x = *x + 1;
    if(moves == 3)
    *y = *y + 1;
}
