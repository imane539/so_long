/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:16:18 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:16:21 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_all(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free_array(mlx->map);
	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (mlx->enemy)
		mlx_destroy_image(mlx->mlx, mlx->enemy);
	if (mlx->collectible)
		mlx_destroy_image(mlx->mlx, mlx->collectible);
	if (mlx->wall)
		mlx_destroy_image(mlx->mlx, mlx->wall);
	if (mlx->door)
		mlx_destroy_image(mlx->mlx, mlx->door);
	mlx_destroy_display(mlx->mlx);
	if (mlx->enemy_position)
	{
		while (i < mlx->num_enemy)
			free(mlx->enemy_position[i++]);
		free(mlx->enemy_position);
	}
	free(mlx->mlx);
	exit(0);
}

int	key_press(int key_code, t_mlx *mlx)
{
	if (key_code == 65307)
		clean_all(mlx);
	if (key_code == 97)
		move_player(mlx, 0, -1, 'l');
	if (key_code == 100)
		move_player(mlx, 0, 1, 'r');
	if (key_code == 119)
		move_player(mlx, -1, 0, 'u');
	if (key_code == 115)
		move_player(mlx, 1, 0, 'd');
	if (mlx->collected == mlx->num_coll)
	{
		if (mlx->door)
			mlx_destroy_image(mlx->mlx, mlx->door);
		mlx->door = check_image(mlx, "textures/door_open.xpm");
	}
	return (0);
}

void	display_images(t_mlx *mlx, int change)
{
	int (i), (j);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			put_image_to_window(mlx, i, j, change);
			j++;
		}
		i++;
	}
}

int	update_animation(t_mlx *mlx)
{
	char		*move_count;
	static int	frame = 0;

	if (frame++ % 700 == 0)
	{
		animation(mlx);
		move_enemy(mlx);
	}
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	display_images(mlx, 0);
	player_move(mlx);
	move_count = ft_itoa(mlx->n_mov);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 350, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 400, 10, 0xFFFFFF, move_count);
	free(move_count);
	return (0);
}

void	screen(t_mlx *mlx, int line_size, int n_line, int num_enemy)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_error("", mlx->map, NULL, 1);
	init_value(mlx, line_size, n_line);
	mlx->door = check_image(mlx, "textures/door.xpm");
	mlx->player = check_image(mlx, "textures/normal.xpm");
	mlx->enemy = check_image(mlx, "textures/gin.xpm");
	mlx->collectible = check_image(mlx, "textures/collectible.xpm");
	mlx->wall = check_image(mlx, "textures/wall.xpm");
	mlx->height = 50;
	mlx->width = 58;
	mlx->mlx_win = mlx_new_window(mlx->mlx, line_size * mlx->width, n_line
			* mlx->height, "Detective Conan");
	if (!mlx->mlx_win)
		ft_error("", mlx->map, NULL, 1);
	display_images(mlx, 1);
	mlx->n_mov = 0;
	mlx->collected = 0;
	mlx->num_enemy = num_enemy;
	find_enemies(mlx);
	mlx_loop_hook(mlx->mlx, update_animation, mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, clean_all, mlx);
	mlx_loop(mlx->mlx);
}
