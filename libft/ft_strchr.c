/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:51:02 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/12 13:33:20 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != (char)c && string[i])
		i++;
	if (string[i] == (char)c)
		return ((char *)&string[i]);
	return (NULL);
}
