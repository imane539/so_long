#include "so_long.h"

int main(int argc, char **argv)
{
    int fd;
    char **map;
  
    if(argc != 2)
        ft_error("try again :(",NULL,NULL,1);
    fd = check_argument(argv[1]);
    map = read_map(fd);
    check_map(map);
    screen();
}

