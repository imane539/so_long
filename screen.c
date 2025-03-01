#include "so_long.h"
#include <fcntl.h>
void screen()
{
    void	*mlx;
	void	*mlx_win;
    	void	*img;
	char	*relative_path = "textures/wall.xpm";
	// int		img_width;
	// int		img_height; 
    // void *test;
    mlx = mlx_init();
   
	mlx_win = mlx_new_window(mlx, 500, 500, "Detective Conan");
    img = mlx_xpm_file_to_image(mlx, relative_path, &(int){0}, &(int){0});
    if (open(relative_path, O_RDONLY) == -1)
        printf("hi\n");
    if (!img)
        printf("hello\n");
    mlx_put_image_to_window(mlx,  mlx_win, img, 0, 0);
    // (void)mlx_win;
    // (void)img;

	mlx_loop(mlx);
    
}