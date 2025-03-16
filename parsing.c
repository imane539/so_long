/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:16:43 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:16:47 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str, char **map, t_bfs **a, int e)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	if (!map)
		exit(1);
	free_array(map);
	if (a)
		clear_queue(a);
	if (e == 1)
		exit(1);
	else
		return (0);
}

int	check_argument(char *av)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(av, '.');
	if (!extension)
		ft_error("add the extension", NULL, NULL, 1);
	if (ft_strncmp(extension, ".ber", ft_strlen(av)) != 0)
		ft_error("the extension incorrect", NULL, NULL, 1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("this map doesn't exist", NULL, NULL, 1);
	return (fd);
}

void	*check_image(t_mlx *mlx, char *img)
{
	void	*mlx_image;

	int (w), (h);
	mlx_image = NULL;
	mlx_image = mlx_xpm_file_to_image(mlx->mlx, img, &w, &h);
	if (!mlx_image)
	{
		ft_putstr_fd("Error\nimage not found", 2);
		clean_all(mlx);
	}
	return (mlx_image);
}

void	init_value(t_mlx *mlx, int line_size, int n_line)
{
	int (w), (h);
	mlx_get_screen_size(mlx->mlx, &w, &h);
	if (n_line * 50 > h || line_size * 58 > w)
	{
		free_array(mlx->map);
		ft_putstr_fd("the max size is ", 2);
		ft_putnbr_fd(w / 58, 2);
		ft_putchar_fd('*', 2);
		ft_putnbr_fd(h / 50, 2);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(1);
	}
	mlx->door = NULL;
	mlx->player = NULL;
	mlx->enemy = NULL;
	mlx->collectible = NULL;
	mlx->wall = NULL;
	mlx->mlx_win = NULL;
	mlx->enemy_position = NULL;
}

void	check_new_line(char *buf, char *line, int fd)
{
	if (buf[0] == '\n')
	{
		free(buf);
		free(line);
		get_next_line(fd, 1);
		ft_error("invalid map", NULL, NULL, 1);
	}
}
