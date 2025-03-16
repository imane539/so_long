/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:41:14 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/13 12:41:17 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	clear_queue(t_bfs **a)
{
	t_bfs	*tmp;

	while (*a)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
	}
	free(a);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	*line;
	char	**map;

	int (fd), (line_size), (n_line), (collectible), (num_enemy);
	line = NULL;
	n_line = 0;
	if (argc != 2)
		ft_error("try again :(", NULL, NULL, 1);
	fd = check_argument(argv[1]);
	map = read_map(fd, line);
	collectible = check_map(map, &num_enemy);
	line_size = (int)ft_strlen(map[n_line]);
	while (map[n_line])
		n_line++;
	mlx.map = map;
	mlx.num_coll = collectible;
	screen(&mlx, line_size, n_line, num_enemy);
}
