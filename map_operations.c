/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:15:44 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:15:46 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = (int)ft_strlen(map[i++]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != size)
			ft_error("the map is not rectangular", map, NULL, 1);
		i++;
	}
	return (size);
}

void	check_wall(char **map, int line)
{
	int (i), (j), (size);
	size = 0;
	i = 0;
	while (map[size])
		size++;
	while (i < size)
	{
		if (i == 0 || i == size - 1)
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j++] != '1')
					ft_error("The map must be enclosed/surrounded by walls",
						map, NULL, 1);
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][line - 1] != '1')
				ft_error("The map must be enclosed/surrounded by walls", map,
					NULL, 1);
		}
		i++;
	}
}

void	check_caracter(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != '0'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'G')
				ft_error("invalid character", map, NULL, 1);
			j++;
		}
		i++;
	}
}

int	check_map(char **map, int *num_enemy)
{
	int	line_size;
	int	i;

	i = 0;
	while (map[i])
		i++;
	line_size = check_rectangular(map);
	check_wall(map, line_size);
	check_caracter(map);
	*num_enemy = check_components(map, line_size);
	return (valid_path(map, line_size));
}

char	**read_map(int fd, char *line)
{
	char	*tmp;
	char	*buf;
	char	**map;

	buf = get_next_line(fd, 0);
	if (!buf)
		ft_error("invalid map", NULL, NULL, 1);
	while (buf)
	{
		if (!line)
			line = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(line, buf);
			free(line);
			line = ft_strdup(tmp);
			free(tmp);
		}
		check_new_line(buf, line, fd);
		free(buf);
		buf = get_next_line(fd, 0);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
