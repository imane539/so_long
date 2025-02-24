#include "so_long.h"
void ft_error(char *str)
{
    ft_putstr_fd("Error\n",1);
    ft_putstr_fd(str,1);
    exit(1);
}
int  check_argument(char *av)
{
    int fd;
    char *extension;
    extension = ft_strrchr(av,'.');
    if(!extension)
        ft_error("add the extension");
    if(ft_strncmp(extension,".ber",ft_strlen(av)) != 0)
        ft_error("the extension incorrect");
    fd = open(av,O_RDONLY);
    if(fd < 0)
        ft_error("this map doesn't exist");
    return fd;
}
