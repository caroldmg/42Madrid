/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:37:09 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/04 12:13:52 by cde-migu         ###   ########.fr       */
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
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
		dst[c] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (dstsize + ft_strlen(src));
	while (j + 1 < dstsize && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}