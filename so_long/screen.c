#include "so_long.h"
void clean_all(t_mlx *mlx)
{
        mlx_destroy_window(mlx->mlx, mlx->mlx_win);
        free_array(mlx->map);
        mlx_destroy_image(mlx->mlx,mlx->player);
        mlx_destroy_image(mlx->mlx,mlx->enemy);
        mlx_destroy_image(mlx->mlx,mlx->collectible);
        mlx_destroy_image(mlx->mlx,mlx->wall);
        mlx_destroy_display(mlx->mlx);
        free(mlx->mlx);
         exit(0);

}
int window_close(t_mlx *mlx)
{
    clean_all(mlx);
    return 0;
}
int key_press(int key_code, t_mlx *mlx)
{
    if(key_code == 65307)
    clean_all(mlx);
    return 0;
}
void screen(char **map,int line_size,int n_line)
{
    t_mlx mlx;
    int (i),(j),(w),(h);
	char	*wall = "textures/wall.xpm";
	char	*player = "textures/conan_1.xpm";
	char	*enemy = "textures/gin.xpm";
	char	*door = "textures/door.xpm";
	char	*collectible = "textures/collectible.xpm";
    mlx.map = map;
    mlx.mlx = mlx_init();
    mlx.player = mlx_xpm_file_to_image(mlx.mlx, player, &w, &h);
    mlx.enemy = mlx_xpm_file_to_image(mlx.mlx, enemy, &w, &h);
    mlx.door = mlx_xpm_file_to_image(mlx.mlx, door, &w, &h);
    mlx.collectible = mlx_xpm_file_to_image(mlx.mlx, collectible, &w, &h);
      if(!mlx.collectible)
        ft_error("invalid textures",mlx.map,NULL,1);
    mlx.wall = mlx_xpm_file_to_image(mlx.mlx, wall, &w, &h);
    mlx.height = n_line * h;
    mlx.width = line_size * w;
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Detective Conan");
    i = 0;
    while(mlx.map[i])
    {
        j = 0;
        while(mlx.map[i][j])
        {
            if(mlx.map[i][j] == '1')
                mlx_put_image_to_window(mlx.mlx,  mlx.mlx_win , mlx.wall, j * w, i * h);
            if(mlx.map[i][j] == 'P')
                player_moves(mlx,j * w ,i * h);
            if(mlx.map[i][j] == 'C')
            {
                mlx_put_image_to_window(mlx.mlx,  mlx.mlx_win , mlx.collectible, j * w, i * h);
            }
             if(mlx.map[i][j] == 'G')
            {
                mlx_put_image_to_window(mlx.mlx,  mlx.mlx_win , mlx.enemy, j * w, i * h);
            }
             if(mlx.map[i][j] == 'E')
            {
                mlx_put_image_to_window(mlx.mlx,  mlx.mlx_win , mlx.door, j * w, i * h);
            }
            j++;
        }
        i++;
    }
    mlx_hook(mlx.mlx_win, 2, 1L<<0, key_press, &mlx);
    mlx_hook(mlx.mlx_win, 17, 0, window_close, &mlx);
    mlx_loop(mlx.mlx);    
}
