/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:56:28 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/12 15:05:29 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	k;

	k = 0;
	destsize = 0;
	j = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i])
		i++;
	while (dest[destsize])
		destsize++;
	if (destsize >= size)
		return (i + size);
	k = destsize;
	while (k < size - 1 && src[j])
	{
		dest[k++] = src[j++];
	}
	dest[k] = '\0';
	return (i + destsize);
}
