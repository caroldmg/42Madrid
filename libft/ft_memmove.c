/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:05:27 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:13:49 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*source;
	size_t	count;

	source = (const char *)src;
	count = 0;
	while (count < len)
	{
		*source = *(char *)src;
		*(char *)dst = *source;
		dst++;
		source++;
		count++;
	}
	return (dst - count);
}
