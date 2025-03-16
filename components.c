/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:10:31 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 04:10:33 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_queue(t_bfs *a)
{
	int	size;

	size = 0;
	if (!a)
		return (size);
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	*position(char **map, int line_size, char c)
{
	int	i;
	int	*position;

	int (size), (j);
	position = malloc(sizeof(int) * 2);
	j = 1;
	size = 0;
	while (map[size])
		size++;
	while (j < size - 1)
	{
		i = 1;
		while (i < line_size - 1)
		{
			if (map[j][i] == c)
			{
				position[0] = j;
				position[1] = i;
			}
			i++;
		}
		j++;
	}
	return (position);
}

int	check_exit(t_bfs *a, int *e)
{
	while (a)
	{
		if (a->x == e[0] && a->y == e[1])
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_components(char **map, int line_size)
{
	int (i), (size), (p), (e), (c), (g);
	size = 0;
	i = 1;
	p = 0;
	c = 0;
	e = 0;
	g = 0;
	while (map[size])
		size++;
	while (i < size - 1)
	{
		p += count_components(map[i], line_size, 'P');
		e += count_components(map[i], line_size, 'E');
		c += count_components(map[i], line_size, 'C');
		g += count_components(map[i], line_size, 'G');
		i++;
	}
	if (e != 1 || c < 1 || p != 1)
		ft_error("the map must contain 1 E,1 P and at least 1 C", map,
			NULL, 1);
	return (g);
}

int	count_components(char *str, int line_size, char c)
{
	int (i), (count);
	count = 0;
	i = 1;
	while (i < line_size - 1)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
