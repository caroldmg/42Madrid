/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:01:03 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/02 19:04:40 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_findnchar(char *read_buf);
char	*ft_gnljoin(char *buf, char *content);
char	*ft_gnlstrlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_gnl(const char *s);
char	*free_null(char **s);

#endif