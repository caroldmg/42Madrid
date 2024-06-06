/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:27:17 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 16:06:59 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result += ft_putstr("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			result += ft_putchar('-');
			n = n * -1;
		}
		if (n > 9)
		{
			result += ft_putnbr(n / 10);
		}
		result += ft_putchar(n % 10 + '0');
	}
	return (result);
}

int	ft_putnbrbase(size_t nbr, char *base, int blen)
{
	int	result;

	result = 0;
	if (nbr >= (size_t)blen)
		result += ft_putnbrbase(nbr / blen, base, blen);
	result += ft_putchar(base[nbr % blen]);
	return (result);
}

int	ft_putptr(unsigned long ptr)
{
	int	result;

	result = 0;
	result += ft_putstr("0x");
	result += ft_putnbrbase(ptr, "0123456789abcdef", 16);
	return (result);
}
