/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:37:42 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/03/13 06:37:46 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_get(char *s1)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	size = (int)ft_strlen_get(s1);
	p = malloc(size + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	p = malloc(ft_strlen_get(s1) + ft_strlen_get(s2) + 1);
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

int	check_line(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_get(char *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = ft_strlen_get(s);
	i = 0;
	if (start > size)
		return (ft_strdup_get(""));
	if (len > size - start)
		len = size - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
