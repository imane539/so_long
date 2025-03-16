/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:35:34 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/13 06:35:36 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
