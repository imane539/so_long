#include "so_long.h"

size_t check_rectangular(char **map)
{
    int i;
    size_t size;

    i = 0;
    size = ft_strlen(map[i++]);
    while(map[i])
    {
        if(ft_strlen(map[i]) != size)
            ft_error("the map is not rectangular",map,NULL,1);
        i++;
    }
    return size;
}
void check_wall(char **map ,size_t line)
{
    int (i),(j),(size);
    
    size = 0;
    i = 0;
    while(map[size])
        size++;
    while(i < size)
    {
        if(i == 0 || i == size - 1)
        {
            j = 0;
            while(map[i][j])
            {
                if(map[i][j++] != '1')
                    ft_error("The map must be enclosed/surrounded by walls",map,NULL,1);
            }
        }
        else
        {
            if(map[i][0] != '1' || map[i][line - 1] != '1')
                ft_error("The map must be enclosed/surrounded by walls",map,NULL,1);
        }
        i++;
    }
}
void check_caracter(char **map)
{
    int i;
    int j;
    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != '0' && map[i][j] != 'E' && map[i][j] != 'P')
            ft_error("invalid character",map,NULL,1);
            j++;
        }
        i++;
    }
}
void check_map(char **map)
{
    size_t line_size;
    line_size = check_rectangular(map);
    check_wall(map,line_size);
    check_caracter(map);
    check_components(map,line_size);
    valid_path(map,line_size);
}
char **read_map(int fd)
{
    char **map;
    char *line;
    char *tmp;
    char *buf;

    line = NULL;
    buf = get_next_line(fd);
    while(buf)
    {
        if(!line)
           line = ft_strdup(buf);
        else
        {
            tmp = ft_strjoin(line,buf);
            free(line);
            line = ft_strdup(tmp);
            free(tmp);
        }
        free(buf);
        buf = get_next_line(fd);
    }
    map = ft_split(line,'\n');
    free(line);
    return map;
}
