/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:32:00 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/12 13:32:12 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	if (fd < 0)
		return ;
	if (!s)
		return ;
	size = ft_strlen(s);
	write(fd, s, size);
}
