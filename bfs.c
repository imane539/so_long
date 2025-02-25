#include "so_long.h"

void valid_path(char **map,size_t line_size)
{
    int *p;
    t_bfs **a;
    int *e;
    p = position(map,line_size,'P');
    e = position(map,line_size,'E');
    bfs(map,line_size,p,e);
    printf("p->x:%d\n",p[0]);
    printf("p->y:%d\n",p[1]);
    printf("e->x:%d\n",e[0]);
    printf("e->y:%d\n",e[1]);
}
void bfs(char **map,size_t line_size,int *p,int *e)
{
    t_bfs **a;
    a = malloc(sizeof(t_bfs *));
    a = new_node(p[0],p[1]);

}
