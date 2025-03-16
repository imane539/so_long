/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:47:05 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/13 08:47:07 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	the_same_index(t_bfs *a, int index)
{
	int	count;

	count = 0;
	if (!a)
		return (count);
	while (a)
	{
		if (a->index == index)
			count++;
		a = a->next;
	}
	return (count);
}

void	change_moves(int *x, int *y, int moves)
{
	if (moves == 0)
		*x = *x - 1;
	if (moves == 1)
		*y = *y - 1;
	if (moves == 2)
		*x = *x + 1;
	if (moves == 3)
		*y = *y + 1;
}

void	find_enemies(t_mlx *mlx)
{
	int (i), (j), (e);
	i = 0;
	e = 0;
	mlx->enemy_position = malloc(sizeof(int *) * mlx->num_enemy);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'G')
			{
				mlx->enemy_position[e] = malloc(sizeof(int) * 2);
				mlx->enemy_position[e][0] = i;
				mlx->enemy_position[e][1] = j;
				e++;
			}
			j++;
		}
		i++;
	}
}

void	player_animation(char **path, char move)
{
	if (move == 'l')
	{
		path[0] = "textures/left_walk1.xpm";
		path[1] = "textures/left_walk2.xpm";
		path[2] = "textures/left_walk3.xpm";
	}
	if (move == 'u')
	{
		path[0] = "textures/up_walk1.xpm";
		path[1] = "textures/up_walk2.xpm";
		path[2] = "textures/up_walk3.xpm";
	}
	if (move == 'r')
	{
		path[0] = "textures/right_walk1.xpm";
		path[1] = "textures/right_walk2.xpm";
		path[2] = "textures/right_walk3.xpm";
	}
	if (move == 'd')
	{
		path[0] = "textures/down_walk1.xpm";
		path[1] = "textures/down_walk2.xpm";
		path[2] = "textures/down_walk3.xpm";
	}
}

void	put_image_to_window(t_mlx *mlx, int i, int j, int change)
{
	if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall, j
			* mlx->width, i * mlx->height);
	if (mlx->map[i][j] == 'P' && change == 1)
	{
		mlx->player_position[0] = i;
		mlx->player_position[1] = j;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player, j
			* mlx->width, i * mlx->height);
	}
	if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->collectible, j
			* mlx->width, i * mlx->height);
	if (mlx->map[i][j] == 'G')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->enemy, j
			* mlx->width, i * mlx->height);
	if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->door, j
			* mlx->width, i * mlx->height);
}
