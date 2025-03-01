#include "so_long.h"
void screen()
{
    void	*mlx;
	void	*mlx_win;
    void *test;
    mlx = mlx_init();
     int width = 40;
    int height = 40;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Detective Conan");
    test = mlx_xpm_to_image(mlx, "../texture/wall.bng",&width, &height);

    (void)mlx_win;
	mlx_loop(mlx);
    
}