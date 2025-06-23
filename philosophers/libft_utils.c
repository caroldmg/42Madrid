/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:04:07 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 12:46:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
	{
		memset(ptr, 0, count * size);
		return (ptr);
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
