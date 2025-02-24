#include "so_long.h"

void check_components(char **map,size_t line_size)
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
        ft_error("AA");
}
int count_components(char *str,size_t line_size,char c)
{
    size_t i;
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