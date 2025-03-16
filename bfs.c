/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:52:47 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/13 06:52:50 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(char **map, int line_size)
{
	int		*p;
	int		*e;
	int		collectible;
	t_bfs	**a;

	int (i), (j);
	i = 0;
	collectible = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'C')
				collectible++;
		i++;
	}
	p = position(map, line_size, 'P');
	e = position(map, line_size, 'E');
	a = bfs(map, &collectible, p, e);
	free(p);
	free(e);
	clear_queue(a);
	if (!collectible)
		exit(1);
	return (collectible);
}

int	valid_moves(char **map, int *p, t_bfs **a, int index)
{
	int (x), (y), (moves), (c);
	moves = 0;
	c = 0;
	while (moves < 4)
	{
		x = p[0];
		y = p[1];
		change_moves(&x, &y, moves);
		if (map[x][y] == 'C' && !isvisited(*a, x, y))
			c++;
		if (map[x][y] != '1' && map[x][y] != 'G' && !isvisited(*a, x, y))
			add_next(a, x, y, index);
		moves++;
	}
	return (c);
}

int	the_first(t_bfs *a, int *p, int *count, int check)
{
	a = queue_position(a);
	while (a)
	{
		if (a->position == *count)
		{
			p[0] = a->x;
			p[1] = a->y;
			if (check == 1)
				(*count)++;
			return (1);
		}
		a = a->next;
	}
	return (0);
}

t_bfs	**fill_queue(char **map, int *p, int *coll)
{
	t_bfs	**a;

	*coll = 0;
	a = malloc(sizeof(t_bfs *));
	(*a) = new_node(p[0], p[1], 0);
	*coll += valid_moves(map, p, a, 1);
	return (a);
}

t_bfs	**bfs(char **map, int *collectible, int *p, int *e)
{
	t_bfs	**a;

	int (count), (index), (coll), (same_index);
	count = 1;
	index = 1;
	a = fill_queue(map, p, &coll);
	while (*collectible != coll || !check_exit(*a, e))
	{
		same_index = the_same_index(*a, index++);
		if (!the_first(*a, p, &count, 1) && same_index == 0)
			break ;
		while (same_index > 0)
		{
			if (p[0] == e[0] && p[1] == e[1])
				if (same_index-- == 0 || !the_first(*a, p, &count, 0))
					break ;
			coll += valid_moves(map, p, a, index);
			if (same_index == 0 || !the_first(*a, p, &count, 0))
				break ;
			count++;
		}
	}
	if (*collectible != coll || !check_exit(*a, e))
		*collectible = ft_error("invalid path", map, NULL, 0);
	return (a);
}
