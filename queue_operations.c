/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:16:07 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:16:09 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isvisited(t_bfs *a, int x, int y)
{
	while (a)
	{
		if (a->x == x && a->y == y)
			return (1);
		a = a->next;
	}
	return (0);
}

t_bfs	*new_node(int x, int y, int index)
{
	t_bfs	*new;

	new = malloc(sizeof(t_bfs));
	new->x = x;
	new->y = y;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_bfs	*last_node(t_bfs *a)
{
	if (!a)
		return (a);
	while (a->next)
	{
		a = a->next;
	}
	return (a);
}

void	add_next(t_bfs **a, int x, int y, int index)
{
	t_bfs	*last;

	if (!(*a))
		(*a) = new_node(x, y, index);
	else
	{
		last = last_node(*a);
		last->next = new_node(x, y, index);
	}
}

t_bfs	*queue_position(t_bfs *a)
{
	t_bfs	*current;
	int		p;

	current = a;
	p = 0;
	while (current)
	{
		current->position = p;
		p++;
		current = current->next;
	}
	return (a);
}
