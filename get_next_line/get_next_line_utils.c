/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:37:09 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/12 15:09:59 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

//igual es interesante cambiar el retorno para que devuelva la string creada?
char	*ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

char	*ft_start_strcpy(char *dst, const char *src, size_t start)
{
	size_t	c;

	c = 0;
	while (src[start] != '\0')
		dst[c++] = src[start++];
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

char	*ft_strjoin(char *buf, char *content)
{
	size_t	buf_len;
	size_t	cont_len;
	char	*new;

	buf_len = 0;
	if (!buf && !content)
		return (NULL);
	if (buf)
		buf_len = ft_strlen(buf);
	cont_len = ft_strlen(content);
	new = (char *)malloc((buf_len + cont_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, buf, buf_len + 1);
	ft_strlcpy(new + buf_len, content, cont_len + 1);
	new[buf_len + cont_len] = '\0';
	free(buf);
	return (new);
}
