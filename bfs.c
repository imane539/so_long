#include "so_long.h"

void valid_path(char **map,size_t line_size)
{
    int *p;
    // t_bfs **a;
    int *e;
    p = position(map,line_size,'P');
    e = position(map,line_size,'E');
    bfs(map,line_size,p,e);
   
}
t_bfs **moves(char **map,t_moves *moves,t_bfs *a)
{
}
void bfs(char **map,size_t line_size,int *p,int *e)
{
    // t_bfs **a;
    t_moves moves;

    // a = malloc(sizeof(t_bfs *));
    // a = new_node(p[0],p[1]);
    (void)map;
    (void)line_size;
    (void)e;

    moves = allocate_moves(p[0],p[1]);
    // printf("up->x:%d\n",moves.up[0]);
    // printf("up->y:%d\n",moves.up[1]);
    // printf("down->x:%d\n",moves.down[0]);
    // printf("down->y:%d\n",moves.down[1]);
    // printf("left->x:%d\n",moves.left[0]);
    // printf("left->y:%d\n",moves.left[1]);
    // printf("right->x:%d\n",moves.right[0]);
    // printf("right->y:%d\n",moves.right[1]);
    // printf("e->x:%d\n",e[0]);
    // printf("e->y:%d\n",e[1]);
}
t_moves allocate_moves(int x,int y)
{
    t_moves moves;
    moves.up = malloc(sizeof(int) *2);
    moves.down = malloc(sizeof(int) *2);
    moves.left = malloc(sizeof(int) *2);
    moves.right = malloc(sizeof(int) *2);
    moves.up[0] = x-1;
    moves.up[1] = y;
    moves.down[0] = x+1;
    moves.down[1] = y;
    moves.left[0] = x;
    moves.left[1] = y-1;
    moves.right[0] = x;
    moves.right[1] = y+1;
    return moves;
}