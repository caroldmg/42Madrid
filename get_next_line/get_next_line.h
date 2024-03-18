/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:01:03 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/18 12:51:56 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_findnchar(char *read_buf);
char	*ft_strjoin(char *buf, char *content);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif