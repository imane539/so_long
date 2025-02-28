
#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_moves
{
    int *up;
    int *down;
    int *left;
    int *right;
}              t_moves;

typedef struct s_bfs
{
    int x;
    int y;
    int index;
    int position;
    struct s_bfs *next;
}              t_bfs;

/**********parsing file****** */
int ft_error(char *str,char **map,t_bfs **a,int e);
int check_argument(char *av);

/**********map_operations**** */
char **read_map(int fd);
size_t check_rectangular(char **map);
void check_wall(char **map,size_t line);
void check_map(char **map);
void check_caracter(char **map);
/**********components**** */
void check_components(char **map,size_t line_size);
int count_components(char *str,size_t line_size,char c);
int *position(char **map,size_t line_size,char c);
int size_queue(t_bfs *a);
int check_exit(t_bfs *a,int *e);
/************bfs********** */
void valid_path(char **map,size_t line_size);
int valid_moves(char **map,int *p,t_bfs **a,int index);
int the_first(t_bfs *a,int *p,int *count,int check);
t_bfs	**bfs(char **map,int *collectible,int *p,int *e);
t_bfs **fill_queue(char **map,int *p,int *coll);
/************queue_operations */
int isvisited(t_bfs *a,int x,int y);
t_bfs *new_node(int x,int y,int index);
t_bfs *last_node(t_bfs *a);
void add_next(t_bfs **a,int x,int y,int index);
t_bfs *queue_position(t_bfs *a);

/*************utils********* */
void free_array(char **map);
int the_same_index(t_bfs *a,int index);
void change_moves(int *x,int *y,int moves);
void clear_queue(t_bfs **a);

/*************screen ********/
void screen();
#endif

