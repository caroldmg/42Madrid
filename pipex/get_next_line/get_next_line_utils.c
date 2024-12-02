/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:37:09 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/02 19:05:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while (*s != '\0')
	{
		strlen++;
		s++;
	}
	return (strlen);
}

char	*ft_gnlstrlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;

	c = 0;
	if (dstsize > 0)
	{
		while (c < dstsize - 1 && src[c] != '\0')
		{
			dst[c] = src[c];
			c++;
		}
	}
	dst[c] = '\0';
	return (dst);
}

int	ft_findnchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*free_null(char **s)
{
	if (*s != NULL)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

char	*ft_gnljoin(char *buf, char *content)
{
	size_t	buf_len;
	size_t	cont_len;
	char	*new;

	buf_len = 0;
	if (buf != NULL)
		buf_len = ft_strlen_gnl(buf);
	cont_len = ft_strlen_gnl(content);
	new = (char *)malloc((buf_len + cont_len + 1) * sizeof(char));
	if (!new)
	{
		free_null(&content);
		return (free_null(&buf));
	}
	ft_gnlstrlcpy(new, buf, buf_len + 1);
	ft_gnlstrlcpy(new + buf_len, content, cont_len + 1);
	if (buf)
		free_null(&buf);
	return (new);
}
