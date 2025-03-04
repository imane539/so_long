#include "so_long.h"
int size_queue(t_bfs *a)
{
    int size ;
    size = 0;
    if(!a)
    return size;
    while(a)
    {
        size++;
        a = a->next;
    }
    return size;
}
int *position(char **map,int line_size,char c)
{
    int i;
    int (size),(j);
    int *position;
    position = malloc(sizeof(int)*2);
    j = 1;
    size = 0;
    while(map[size])   
     size++;
    while(j < size - 1)
    {
        i = 1;
        while(i < line_size - 1)
        {
            if(map[j][i] == c)
            {
                position[0] = j;
                position[1] = i;
            }
            i++;
        }
        j++;
    }
    return position;
}
int check_exit(t_bfs *a,int *e)
{
    while(a)
    {
        if( a->x == e[0] && a->y == e[1])
            return 1;
        a=a->next;
    }
    return 0;
}
void check_components(char **map,int line_size)
{
    int (i),(size),(p),(e),(c);
    size = 0;
    i = 1;
    p = 0;
    c = 0;
    e = 0;

    while(map[size])   
    size++;
    while(i < size - 1)
    {
        p+=count_components(map[i],line_size,'P');
        e+=count_components(map[i],line_size,'E');
        c+=count_components(map[i],line_size,'C');
        i++;
    }
    if(e != 1 || c < 1 || p != 1)
        ft_error("AA",map,NULL,1);
}
int count_components(char *str,int line_size,char c)
{
    int i;
    int count;
    count = 0;
    i = 1;
    while(i < line_size - 1)
    {
        if(str[i] == c)
            count++;
        i++;
    }
    return count;
}