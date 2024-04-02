/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:23:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/28 12:42:09 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_spaces(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r'));
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0' && ft_is_spaces(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit((int)str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return ((int)nbr * sign);
}
