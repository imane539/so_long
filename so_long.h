
#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

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
#endif
