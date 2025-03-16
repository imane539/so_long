/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:35:07 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/13 06:35:10 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	s;

	s = count * size;
	if (count && s / count != size)
		return (NULL);
	p = malloc(s);
	if (!p)
		return (NULL);
	ft_bzero(p, s);
	return (p);
}
