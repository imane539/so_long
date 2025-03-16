/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:15:56 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:15:58 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player,
		mlx->player_position[1] * mlx->width, mlx->player_position[0]
		* mlx->height);
	if (mlx->map[mlx->player_position[0]][mlx->player_position[1]] == 'G')
	{
		ft_putstr_fd("you lose the game\n", 1);
		clean_all(mlx);
	}
	if (mlx->map[mlx->player_position[0]][mlx->player_position[1]] == 'C')
		mlx->map[mlx->player_position[0]][mlx->player_position[1]] = '0';
}

void	move_player(t_mlx *mlx, int x, int y, char move)
{
	char	*path[3];

	int (new_x), (new_y);
	new_x = mlx->player_position[0] + x;
	new_y = mlx->player_position[1] + y;
	if (mlx->map[new_x][new_y] == 'E' && mlx->collected == mlx->num_coll)
	{
		ft_putstr_fd("you win the game\n", 1);
		clean_all(mlx);
	}
	if (mlx->map[new_x][new_y] == '1' || (mlx->map[new_x][new_y] == 'E'
			&& mlx->collected != mlx->num_coll))
		return ;
	mlx->player_position[0] = new_x;
	mlx->player_position[1] = new_y;
	player_animation(path, move);
	player(mlx, path);
	mlx->n_mov++;
	if (mlx->map[mlx->player_position[0]][mlx->player_position[1]] == 'C')
		mlx->collected++;
}

void	player(t_mlx *mlx, char **path)
{
	static int	change = 0;

	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (change == 0)
		mlx->player = check_image(mlx, path[0]);
	if (change == 1)
		mlx->player = check_image(mlx, path[1]);
	if (change == 2)
		mlx->player = check_image(mlx, path[2]);
	change = (change + 1) % 3;
}

void	animation(t_mlx *mlx)
{
	static int	change = 0;

	if (mlx->collectible)
		mlx_destroy_image(mlx->mlx, mlx->collectible);
	if (change == 0)
		mlx->collectible = check_image(mlx, "textures/collectible.xpm");
	if (change == 1)
		mlx->collectible = check_image(mlx, "textures/collectible1.xpm");
	if (change == 2)
		mlx->collectible = check_image(mlx, "textures/collectible2.xpm");
	change = (change + 1) % 3;
}

void	move_enemy(t_mlx *mlx)
{
	static int	direction = 1;

	int (x), (y), (i);
	i = 0;
	while (i < mlx->num_enemy)
	{
		x = mlx->enemy_position[i][0];
		y = mlx->enemy_position[i][1];
		if (mlx->map[x][y + direction] == '0')
		{
			mlx->map[x][y] = '0';
			mlx->map[x][y + direction] = 'G';
			mlx->enemy_position[i][1] += direction;
		}
		else
			direction *= -1;
		i++;
	}
}
