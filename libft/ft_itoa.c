/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/27 18:25:06 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_cifras(int n, int i)
{
	if (n % 10 == 0)
		count_cifras(n % 10, i + 1);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n > 0)
		i = 1;
	else
		i = 2;
	str = malloc(count_cifras(n, i) * sizeof(char));
}