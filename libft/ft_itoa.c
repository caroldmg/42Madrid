/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/30 19:10:00 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_cifras(int n, int i)
{
	if (n > 10)
		count_cifras(n / 10, i + 1);
	return (i);
}

static char	*fill_str(int n, char *s, int len)
{
	int		i;
	char	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	while (i < len - 1)
	{
		s[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	s[len - 1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n >= 0)
		i = 2;
	else
		i = 3;
	i = count_cifras(n, i);
	str = malloc(count_cifras(n, i) * sizeof(char));
	if (!str)
		return (0);
	fill_str(n, str, i);
	return (str);
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