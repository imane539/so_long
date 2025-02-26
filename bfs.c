#include "so_long.h"

void valid_path(char **map,size_t line_size)
{
    int *p;
    int *e;
    int collectible;
    int (i),(j);
    i = 0;
    collectible = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j++] == 'C')
                collectible++;
        }
        i++;
    }
    p = position(map,line_size,'P');
    e = position(map,line_size,'E');
    bfs(map,collectible,p,e);
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
int valid_moves(char **map,int *p,t_bfs **a,int index)
{
    int (x),(y),(moves),(c);
    moves = 0;
    c = 0;
    while(moves < 4)
    {
        x = p[0];
        y = p[1];
        change_moves(&x,&y,moves);
        if(map[x][y] == 'C' && !isvisited(*a,x,y))
            c++;  
        if(map[x][y] != '1' && !isvisited(*a,x,y))
            add_next(a,x,y,index);
        moves++;
    }
    return c;
}
int the_first(t_bfs *a,int *p,int *count)
{
    a = queue_position(a);
    while(a)
    {
        if(a->position == *count)
        {
            p[0] = a->x;
            p[1] = a->y;
            return 1;
        }
        a = a->next;
    }
    return 0;
}

void bfs(char **map,int collectible,int *p,int *e)
{
    t_bfs **a;
    int (count),(index),(coll),(same_index);
    count = 1;
    coll = 0;
    index = 0;
    a = malloc(sizeof(t_bfs *));
    (*a) = new_node(p[0],p[1],index++);
    coll+=valid_moves(map,p,a,index);
    while(collectible != coll || !check_exit(*a,e))
    {
        same_index = the_same_index(*a,index);
        index++;
        if(!the_first(*a,p,&count) && same_index == 0)
            break;
        count++;
        while(same_index > 0)
        {
                coll+=valid_moves(map,p,a,index);
                same_index--;
                if(same_index == 0 || !the_first(*a,p,&count))
                    break;
                count++;
        }
    }
     if(collectible != coll || !check_exit(*a,e))
        ft_error("invalid path");
}
