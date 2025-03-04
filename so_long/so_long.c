#include "so_long.h"

int main(int argc, char **argv)
{
    char **map;
    int (fd),(line_size),(n_line);
    n_line = 0;
    if(argc != 2)
        ft_error("try again :(",NULL,NULL,1);
    fd = check_argument(argv[1]);
    map = read_map(fd);
    line_size = check_map(map);
    while(map[n_line])
    n_line++;
    screen(map,line_size,n_line);
}

