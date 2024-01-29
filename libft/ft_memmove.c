/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:05:27 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/26 11:14:11 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			count;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst)
		return (0);
	if (src < dst)
	{
		count = len;
		while (count > 0)
		{
			count--;
			destination[count] = source[count];
		}
	}
	else
	{
		count = 0;
		while (count < len)
		{
			destination[count] = source[count];
			count++;
		}
	}
	return (dst);
}
