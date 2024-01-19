/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:48:09 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/19 11:29:34 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			count;
	char			*ptr;

	ptr = (char *)calloc(len, sizeof(char));
	if (ptr)
	{
		i = 0;
		count = 0;
		while (i < start)
			s++;
		while (count < len - 1)
		{
			ptr[count] = s[count];
			count++;
		}
		return (ptr);
	}
	else
		return (0);
}