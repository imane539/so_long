#include "so_long.h"

int change_the_move(int key_code ,t_mlx *mlx)
{
    printf("%d\n",key_code);
    (void)mlx;
    return 0;
}
void player_moves(t_mlx mlx, int w ,int h)
{
    mlx_put_image_to_window(mlx.mlx,  mlx.mlx_win , mlx.player,w, h);
    mlx_hook(mlx.mlx_win, 2, 1L<<0, change_the_move, &mlx);
}