#include "so_long.h"
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
