/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:52:23 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/12 14:05:09 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cmp(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	size;

	k = 0;
	j = 0;
	i = 0;
	size = ft_strlen(little);
	while (big[i] && i < len)
	{
		while (big[i] != little[j] && i < len && big[i])
			i++;
		k = i - j;
		while (big[i] == little[j] && i < len && big[i])
		{
			i++;
			j++;
		}
		if (j >= size)
			return ((char *)&big[k]);
		j--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	return (cmp(big, little, len));
}
