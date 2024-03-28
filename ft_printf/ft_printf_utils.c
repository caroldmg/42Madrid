/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/28 12:13:14 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//de momento tengo aqui las funciones hasta que vea como usar las de la libft

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	res;

	res = 0;
	while (s[res])
	{
		ft_putchar_fd(s[res], fd);
		res++;
	}
	return (res);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result = ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			result += ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		result += ft_putchar_fd(n % 10 + '0', fd);
	}
	return (result);
}
