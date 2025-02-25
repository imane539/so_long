
#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

typedef struct s_bfs
{
    int x;
    int y;
    int visited;
    struct s_bfs *next;
}              t_bfs;

/**********parsing file****** */
void ft_error(char *str);
int check_argument(char *av);

/**********map_operations**** */
char **read_map(int fd);
size_t check_rectangular(char **map);
void check_wall(char **map,size_t line);
void check_map(char **map);

/**********components**** */
void check_components(char **map,size_t line_size);
int count_components(char *str,size_t line_size,char c);
int *position(char **map,size_t line_size,char c);

/************bfs********** */
void valid_path(char **map,size_t line_size);
void bfs(char **map,size_t line_size,int *p,int *e);

/************queue_operations */
t_bfs *new_node(int x,int y);
t_bfs *last_node(t_bfs *a);
#endif

