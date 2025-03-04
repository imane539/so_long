#include "so_long.h"
int ft_error(char *str,char **map,t_bfs **a,int e)
{
   
    ft_putstr_fd("Error\n",1);
    ft_putstr_fd(str,1);
    if(!map)
        exit(1);
    free_array(map);
    if(a)
    clear_queue(a);
    if(e == 1)
    exit(1);
    else 
    return 0;
}
int  check_argument(char *av)
{
    int fd;
    char *extension;
    extension = ft_strrchr(av,'.');
    if(!extension)
        ft_error("add the extension",NULL,NULL,1);
    if(ft_strncmp(extension,".ber",ft_strlen(av)) != 0)
        ft_error("the extension incorrect",NULL,NULL,1);
    fd = open(av,O_RDONLY);
    if(fd < 0)
        ft_error("this map doesn't exist",NULL,NULL,1);
    return fd;
}
