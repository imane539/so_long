/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:58:06 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/02/22 15:58:12 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_line(char **line, char *buffer);
size_t	ft_strlen_get(char *str);
char	*ft_strdup_get(char *s1);
char	*ft_strjoin_get(char *s1, char *s2);
char	*ft_substr_get(char *s, unsigned int start, size_t len);
int		check_line(char *buff);
char	*ft_read(int fd, char **line, char *buffer);
char	*ft_stop(char **buf);
#endif /* GET_NEXT_LINE_H */
