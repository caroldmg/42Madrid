/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/28 12:45:36 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countdigits(long num)
{
	size_t	count;

	count = 0;
	if (num <= 0)
	{
		num = num * -1;
		count++;
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*ft_setstr(char *str, long num, size_t count)
{
	str[count--] = '\0';
	if (num < 0)
	{
		num = num * -1;
		str[0] = '-';
	}
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[count] = num % 10 + '0';
		num = num / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count;

	count = ft_countdigits(n);
	str = ft_calloc(count + 1, sizeof(char));
	if (str)
	{
		ft_setstr(str, n, count);
		return (str);
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_itoa(14);
	printf("%s", res);
	free(res);
	return (0);
}
*/
